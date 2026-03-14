#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook phonebook;
	Contact contact;
	std::string command;

	while (1)
	{
		std::cout << "Write a command: ";
		if (!std::getline(std::cin, command))
			break ;
		if (command.empty())
			std::cout << "input is emptyyy" << std::endl;
		else
		{	
			command.erase(0, command.find_first_not_of(" \t\v\f\r"));
			command.erase(command.find_last_not_of(" \t\v\f\r") + 1);
		}
		if (command == "ADD")
		{	
			phonebook.do_add();
		}	
		else if (command == "SEARCH")
		{	
			phonebook.do_search();
		}
		else if (command == "EXIT")
			break ;
		else
		std::cout << "wrong command detected" << std::endl;
	}
	return (0);
}
