// filename, s1, s2 받음
// filename 오픈함
// filename.replace 에 그것들을 저장함(파일을 새로 만듦) 
// s1이란 스트링 발견시 s2로 바꾸기

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int	main(int ac, char **av)
{	
	(void)av;
	if (ac !=  4)
	{
		std::cout << "relaunch cuz not valable ac(put 4)" << std::endl;
		return (0);
	}
	std::string arg1 = av[1];
	std::string arg2 = av[2];
	std::string arg3 = av[3];

	std::stringstream s2(arg3);
	
	if (arg2.empty())
		return 1;
	std::ifstream arg1_get(arg1.c_str());
	if (!arg1_get)
	{
		std::cerr << "in file open failed\n";
		return 1;
	}
	std::string const new_name = arg1 + ".replace"; //확장자 생각해야함? 내 편의에 따른거 아닌가..
	std::fstream file(new_name.c_str(), std::ios::in | std::ios::out | std::ios::trunc);
	if (!file)
	{
		std::cerr << "out file open failed\n";
		return 1;
	}
	std::string line;
	while (getline (arg1_get, line))
	{
		size_t pos = line.find(arg2);
		
		while (pos != std::string::npos)
		{
			line.erase(pos, arg2.length());
			line.insert(pos, arg3);
			pos = line.find(arg2, pos + arg3.length());
		}
		file << line;
		if (!arg1_get.eof())
			file << std::endl;
	}
	arg1_get.close();
	file.close();
	return (0);
}
