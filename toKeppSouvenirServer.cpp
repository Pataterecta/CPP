
#include "Server.hpp"
#include "Client.hpp"
#include "Replies.hpp"
#include <stdexcept>

volatile std::sig_atomic_t sigFlag = 0; 
// volatile = register protection, value wouldn't be registered in cpu register but memory can read and write directly
// sig_atomic_t = read and write wouldnt be interrupted
// volatile : the way we check, sig_atomic_t the value protection when checking on it

Server::Server(int port, std::string password) 
	: _port(port), _password(password), _fdSocket(-1), _executor(this)
{

}

Server::~Server()
{
	cleanDown();
}

Channel* Server::getOrCreateChannel(const std::string& name)
{
	Channel* channel = getChannelByName(name);
	if (channel != NULL)
		return (channel);
	addChannel(name);
		return (getChannelByName(name));
}


Channel* Server::getChannelByName(const std::string& name) {
    std::map<std::string, Channel*>::iterator it = _channels.find(name);
    if (it != _channels.end()) {
        return it->second;
    }
    return NULL;
}

void Server::addChannel(const std::string& name) {
    if (_channels.find(name) == _channels.end()) {
        _channels[name] = new Channel(name);
    }
}

void Server::removeChannel(const std::string& name)
{
	std::map<std::string, Channel*>::iterator it = _channels.find(name);
	if (it != _channels.end())
	{
		delete it->second;
		_channels.erase(it);
	}
	// 채널 목록에서 없애구, 채널 delete dealloc 관리하기
}

void Server::acceptNewClient(void)
{
	struct sockaddr_in clientAddr; // os will fill this when accept IPv4 adress in this struct
	std::memset(&clientAddr, 0, sizeof(clientAddr));
	socklen_t client_addr_size = sizeof(clientAddr);

	int temp_clientFd = accept(_fdSocket, (struct sockaddr *)&clientAddr, &client_addr_size); // cast sockaddr_in* into sockaddr* in a general adress treating way
	// accept() makes the connection socket and its return value is a socket (for the connection so diff from listen socket) fd
	if (temp_clientFd == FAIL)
	{	
		sysError(ERR_ACCEPT);
		return ;
	}
	if (fcntl(temp_clientFd, F_SETFL, O_NONBLOCK) == -1)
	{
		// making client socket to non blocking
		// F_SETFL(for setting the flag, if not there are duplicating managing etc)
		// https://man7.org/linux/man-pages/man2/fcntl.2.html
		close(temp_clientFd);
		return ;
	}
	pollfd add_to_polling; // sys/poll.h already provided struct
	add_to_polling.fd = temp_clientFd;
	add_to_polling.events = POLLIN;
	// events that "we" want to check out for a specific fd 
	// POLLIN = theres data to read? POLLOUT = theres data to send? POLLHUP = thers disconnection?
	// events could be several cuz bit mask, and as we set this with the creation, when we setPolling() just init it by deleting POLLOUT
	add_to_polling.revents = 0; 
	// revents could be several too, by OR calculation
	// events and revents are in short revents cuz bitmask -> no need bigger value, server can have many FDs so economy
	// what actually happenned, when poll() it's set up and  
	std::string clientHostname(inet_ntoa(clientAddr.sin_addr));
	// internet address to ASCCI representation, return value is is a pointer to an array containing the string char *
	// but not in a char(*)[15] way just the starting point address
	Client* client = new Client(temp_clientFd, clientHostname); 
	// leak management checking is important
	_clients.insert(std::make_pair(temp_clientFd, client));
	// paring and putting in our map data struct
	_polling.push_back(add_to_polling);
	// appending the struct in our _polling vector to the end of the container
}

std::map<int, Client*> Server::getClients(void) const
{
	return this->_clients;
}


const std::map<int, Client*>& Server::congetC(void) const
{
	return this->_clients;
}

int Server::isDis(int fd)
{
	// based on the fd check pollfd's revents flag
	std::vector<struct pollfd>::iterator it = _polling.begin() + 1;
	// + 1 cuz [0] is server fd's place, checking only clients
	while (it != _polling.end())
	{
		if (fd == it->fd)
		{
			if (it->revents & POLLHUP || it->revents & POLLERR || it->revents & POLLNVAL)
			return (1);
			// disconnected and error cases all only returned in revents, Hang up, Error, Invalid request : fd not open 
		}
		++it;
	}
	return (0);
}

void Server::recvServ(int fd, int *i)
{
	// receive messages from a socket and then managing it with _readBuffer
	// reading as possible max
	char tempBuff[1024];
	while (1)
	{
		int ret = recv(fd, tempBuff, sizeof(tempBuff), 0);
		if (ret < 0) // ret < 0 && errno ==EGAIN/EWOULDBLOCK 이래야 지금 읽을 거 끝이라 하네
		{
			if (errno == EINTR)
				continue ;
			if (errno == EWOULDBLOCK || errno == EAGAIN)
				break ;
			_todelFds.insert(_polling[*i].fd);
			break ;
			// 1. EINTR, interrupted by delivery of a signal(system call interruption) before any data was available
			// 2. EWOULDBLOCK EAGAIN The socket is marked nonblocking(our case)
			// no data is available(for now, so normal situation, we received as much as we can or was empty)
			// and the receive operation would block or a receive timeout has been set and the timeout expired before data was received
		}
		else if (ret == 0) // when the other side closed the connection(client disconnected by an orderly shutdown)
		{
			_todelFds.insert(_polling[*i].fd);
			break ;
		}
		std::map<int, Client*>::iterator it = _clients.find(fd);
		if (it != _clients.end())
		{
			Client* client = it->second;
			client->appendToReadBuffer(std::string(tempBuff, ret));
			if (client->getReadBuffer().size() > MAX_READ_BUFF) // message too long without finding \r\n Server protection logic
			{
				_todelFds.insert(_polling[*i].fd);
				break ;
			}
			size_t pos; // std::string::npos to mark that we havent found so (if !(pos == std::string::npos)) means if we found
			while ((pos = client->getReadBuffer().find("\r\n")) != std::string::npos)
			{
				// \r\n 's starting point, so pos + 2 > 512
				if (pos + 2 > MAX_ONE_MESSAGE)
				{
					_todelFds.insert(_polling[*i].fd);
					break ;
				}
				std::string oneLine = client->extractMessage();
				if (isDis(fd))	
				{
					_todelFds.insert(_polling[*i].fd);
					break ;
				}
				if (!(oneLine == ""))
				{
					Message msg = _parser.parseLine(oneLine);
					_executor.dispatchMessage(client, msg);
                    if (client->isToDisconnect())
						return;
				}
			}
		}
	}
}

void Server::sendServ(int fd, int *i)
{
	// send() from the _writeBuffer
	std::map<int, Client*>::iterator it = _clients.find(fd);
	if (it == _clients.end())
		return ;
	Client* client = it->second;
	std::string& wbuff = client->getWriteBuffer();
	while (!wbuff.empty())
	{
		int ret = send(fd, wbuff.c_str(), wbuff.size(), 0);
		if (ret < 0)
		{
			if (errno == EINTR)
				continue ;
			if (errno == EWOULDBLOCK || errno == EAGAIN)
				break ;
			_todelFds.insert(_polling[*i].fd);
			break ;
		}
		wbuff.erase(0, ret);
	}
}

// execution logics and uses, on the server class
// need to be developped better with error replies in other classe discussing with exec
void Server::privateMsg(const std::string& targNick, const std::string& msg)
{
	Client* targ = getClientByNick(targNick);
	if (!targ)
		return ; // need to check the protocol
	targ->appendToWriteBuffer(msg);
}

void Server::channelMsg(const std::string& name, Client* sender, const std::string& msg)
{
	Channel* thisChannel = getChannelByName(name);
	if (!thisChannel)
		return ;
	thisChannel->broadcastMessage(msg, sender);
}

// server broadCast
void Server::broadCastAll(const std::string& msg, int notThisFd)
{
	std::map<int, Client*>::iterator it;
	for (it = _clients.begin(); it != _clients.end(); ++it)
	{
		if (it->first == notThisFd)
			continue;
		it->second->appendToWriteBuffer(msg);
	}
}

const std::string& Server::getPassword(void) const// go const or better this way?
{
	return this->_password;
}

Client* Server::getClientByFd(int fd)
{
	std::map<int, Client*>::iterator it = _clients.find(fd);
	if (it != _clients.end())
		return it->second;
	return NULL;
}

Client* Server::getClientByNick(const std::string& nickname)
{
	std::map<int, Client*>::iterator it;
	for (it = _clients.begin(); it != _clients.end(); ++it)
	{
		if (it->second->getNickname() == nickname)
			return it->second;
	}
	return NULL;
}

// to debug, dont forget to earase 

// void Server::debug_delInChannel()
// {
// 	std::map<std::string, Channel*>::iterator ch_it = _channels.begin();
// 	ch_it = _channels.begin();
// 	int i = 0;
// 	while (ch_it != _channels.end())
// 	{
// 		std::cout << "channel name: " << ch_it->first << std::endl;

// 		std::vector<Client*> clients = ch_it->second->getMembers();
// 		std::vector<Client*>::iterator it = clients.begin();
// 		while (it != clients.end())
// 		{
// 			const int fd = (*it)->getFd();
// 			std::cout << "Channel has these fds: " << fd << std::endl;
// 			++it;
// 		}
// 		++ch_it;
// 		++i;
// 	}
// 	std::cout << "theres " << i << " numbers of channels" << std::endl;
// }

void Server::delInPolling(void)
{
	std::vector<struct pollfd>::iterator it = _polling.begin() + 1;
	while (it != _polling.end())
	{
		if (_todelFds.find(it->fd) != _todelFds.end()) // is this fd inside of _todelFds
			it = _polling.erase(it);
		else
			++it;
	}
}

void Server::delInChannel(void)
{
	// debug_delInChannel();
	// first find and remove the matching clinet(s) using todelFds, on each channels  
	std::map<std::string, Channel*>::iterator ch_it = _channels.begin();
	while (ch_it != _channels.end())
	{
		Channel* channel = ch_it->second;
		std::set<int>::iterator it = _todelFds.begin();
		while (it != _todelFds.end())
		{
			int fd = *it;
			if (_clients.find(fd) != _clients.end())
			{
				channel->removeClient(_clients[fd]);
			}
			++it;
		}
		it = _todelFds.begin();
		++ch_it;
	}
	// then verify if theres no empty channel
	ch_it = _channels.begin();
	while (ch_it != _channels.end())
	{
		Channel* emp_channel = ch_it->second;
		if (emp_channel->isEmpty()) // this channel is empty after deleting the clients on _todelFds
		{
			delete emp_channel;
			_channels.erase(ch_it++);
		}
		else
		++ch_it;
	}
	// debug_delInChannel();
}

void Server::delInClients(void)
{
	std::set<int>::iterator it = _todelFds.begin();
	while (it != _todelFds.end())
	{
		int fd = *it;
		if (_clients.find(fd) != _clients.end())
		{
			delete(_clients[fd]);
			_clients.erase(fd);
			close(fd);
		}
		++it;
	}
}

void Server::disconnectClients(void)
{
	delInPolling();
	delInChannel();
	delInClients();
	_todelFds.clear();
}

void Server::sysError(int sys_enum)
{
	std::string errors[ERR_count] = {"socket", "bind", "listen", "accept", "poll"};
	std::string errMsg = "Error_systemcall: " + errors[sys_enum] + " " + strerror(errno);
	if (sys_enum == ERR_ACCEPT) {
	        std::cerr << errMsg << std::endl;
	        return ; // accept error isn't fatal
	    }
	    throw std::runtime_error(errMsg);
}

void Server::deleteAllChannels(void)
{
    std::map<std::string, Channel*>::iterator it = _channels.begin();
    for (; it != _channels.end(); ++it)
    {
        delete it->second;
    }
    _channels.clear();
}

void Server::deleteAllClients(void)
{
    std::map<int, Client*>::iterator it = _clients.begin();
    for (; it != _clients.end(); ++it)
    {
		// add com with Reply class 
        delete it->second;
        close(it->first);
    }
    _clients.clear();
}

void Server::closeServerSocket(void)
{
    if (_fdSocket >= 0)
    {
        close(_fdSocket);
        _fdSocket = -1;
    }
}

void Server::cleanDown(void)
{
    deleteAllChannels();
    deleteAllClients();
    closeServerSocket();
    
    _polling.clear();
    _todelFds.clear();
}

void Server::confServer()
{
	_fdSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (_fdSocket == FAIL)
		sysError(ERR_SOCKET); // maybe better set another enum ?

	struct sockaddr_in svAddr;
	std::memset(&svAddr, 0, sizeof(svAddr));
	svAddr.sin_family = AF_INET; // the address family for the transport address This member should always be set to AF_INET, if this setting is missing than the most networking functions return EINVAL
	svAddr.sin_addr.s_addr = INADDR_ANY; // An IN_ADDR structure that contains an IPv4 transport address, means any address for socket binding
	svAddr.sin_port = htons(_port); // A transport protocol port number
	// htons : host byte order to network byte order, which means CPU registers from the smaller byte(Little Endian), and the network uses Big Endian, host to network short(2 bytes which is host way)

	int activeReuse = 1;
	if (setsockopt(_fdSocket, SOL_SOCKET, SO_REUSEADDR, &activeReuse, sizeof(activeReuse)) < 0) // SOL_SOCKET, to set options at the socket level, 
		sysError(ERR_SOCKET); // garantee reuse of the same socket even when server turned off and then on for bind()
	if (fcntl(_fdSocket, F_SETFL, O_NONBLOCK) == -1)
		sysError(ERR_SOCKET);
	int bound = bind(_fdSocket, (struct sockaddr *)&svAddr, sizeof(svAddr)); // give the socket fd to local addr, cast for bind
	// bind -> register this socket to this address(IP + PORT), so that the data can come to me
	// client doesnt need cuz client's os choose a usable port and put the ip and bind automatically
	if (bound == FAIL)
		sysError(ERR_BIND);

	int listening = listen(_fdSocket, SOMAXCONN); // client can connect() from now on
	// its being ready, waiting, SOMAXCONN is the max value defined already for listen function
	if (listening == FAIL)
		sysError(ERR_LISTEN);

	// * update server's fd to the poll list for the idx 0
	struct pollfd temp_pollfd;
	temp_pollfd.fd = _fdSocket;
	temp_pollfd.events = POLLIN;
	temp_pollfd.revents = 0;
	
	std::vector<struct pollfd>::iterator it = _polling.begin();
	_polling.insert(it, temp_pollfd);
}

void sigHandler(int sig)
{
	(void)sig; // error: sig unused
    sigFlag = 1;
}

void sigSet(void)
{
    std::signal(SIGINT, sigHandler); // ctrl + c
    std::signal(SIGTERM, sigHandler); // turn off the process
    std::signal(SIGPIPE, SIG_IGN); // SIGPIPE management, when send() to a disconnected other side, not for the recv()
}

// void Server::debug_runServer(int flag)
// {
// 	if (flag == 1)
// 	{
// 		std::cout << "this is server fd: " << _fdSocket << std::endl;
// 		std::cout << "all the _polling 'fd' inc server fd on [0]: " << std::endl;
// 		std::vector<struct pollfd>::iterator it = _polling.begin();
// 		int idx = 0;
// 		while (it != _polling.end())
// 		{
// 			std::cout << "fd idx: " << idx << ": " << it->fd << std::endl;
// 			++it;
// 			++idx;
// 		}
// 	}
// 	if (flag == 2)
// 	{
// 		std::cout << "all the _polling 'revent flag' inc server on [0]: " << std::endl;
// 		std::vector<struct pollfd>::iterator it = _polling.begin();
// 		int idx = 0;
// 		while (it != _polling.end())
// 		{
// 			std::string revent_flag;
// 			if (it->revents == POLLIN)
// 				revent_flag = "POLLIN";
// 			if (it->revents == POLLOUT)
// 				revent_flag = "POLLOUT";
// 			if (it->revents == POLLHUP)
// 				revent_flag = "POLLHUP";
// 			std::cout << "revent idx: " << idx << ": " << revent_flag << std::endl;
// 			++it;
// 			++idx;
// 		}
// 	}
// }

void Server::runServer()
{
	sigSet();
	confServer();
	while (!sigFlag)
	{
		setPolling();
		int fdPerform = poll(_polling.data(), _polling.size(), 1000); // it waits for one of a set of file descriptors to become ready to perform I/O
		// data() returns direct pointer for the internally using memory array that vector uses for its elements
		// 1000 is timeout, msec so 1000 is one sec
		if (fdPerform < 0)
		{
			if (errno == EINTR)
				continue;
			else if (errno == EAGAIN || errno == ENOMEM) // EAGAIN diff from recv and send, not enough memory pour allouer la table des fd, and for the portability EAGAIN is for linux
			{	
				std::cerr << "Error_systemcall: " << "poll " << strerror(errno);
				continue;
			}
			else // EFAULT : fds points outside the process's accessible address space / EINVAL : The nfds value exceeds the maximum fd num that can be opened by this process / EIO : not even mentioned on many mans
				sysError(ERR_POLL);
		}
		if (fdPerform == 0) // system call time outed before any fd became ready
			continue ;
		if (_polling[0].revents & POLLIN) // revents is bitmask so &
			acceptNewClient();
		int i = 1;
		std::vector<struct pollfd>::iterator it = _polling.begin() + 1;
		while (it != _polling.end())
		{
			if (_polling[i].revents & POLLNVAL || _polling[i].revents & POLLERR)
				_todelFds.insert(_polling[i].fd);
			else
			{
				if (_polling[i].revents & POLLIN) // revents bitmask so can be several cases at the same time, so if not else if
					recvServ(_polling[i].fd , &i);
				if ((_polling[i].revents & POLLOUT) && _todelFds.find(_polling[i].fd) == _todelFds.end())
					sendServ(_polling[i].fd, &i);
				if (_polling[i].revents & POLLHUP)
					_todelFds.insert(_polling[i].fd);
			}
			
			std::map<int, Client*>::iterator client_it = _clients.find(_polling[i].fd);
			if (client_it != _clients.end())
			{
				Client* client = client_it->second;
				if (client->isToDisconnect() == true && client->getWriteBuffer().empty())
				{
					_todelFds.insert(_polling[i].fd);
				}
			}


			++it;
			++i;
		}
		disconnectClients();
	}
}

void Server::setPolling(void)
{
	for (std::vector<struct pollfd>::iterator it = _polling.begin() + 1; it != _polling.end(); ++it)
	{
		it->events &= ~POLLOUT; // init en enlevant bitmask POLLOUT qu'il avait
		std::map<int, Client*>::iterator c_it = _clients.find(it->fd);
		if (c_it != _clients.end())
		{
			Client* client = c_it->second;
			if (!(client->getWriteBuffer().empty()))
				it->events |= POLLOUT;
		}
	}
}
