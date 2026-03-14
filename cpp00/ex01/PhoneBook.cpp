#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : idx(0), new_pos(0)
{	
}

void PhoneBook::do_add()
{
	if (idx > 7)
	{
		new_pos = idx % 8;
		contacts[new_pos].set_con();
	}
	else
		contacts[idx].set_con();
	idx++;
}

void PhoneBook:: do_search()
{
	int search_idx;

	if (idx == 0)
	{	
		std::cout << "SEARCH table is emptyyy" << std::endl;
		return ;
	}
	int	i = 0;
	std::cout << "|===========================================|" << std::endl;
	std::cout << "|     Index|" << "First name|" << " Last name|" << "  Nickname|" << std::endl;
	std::cout << "|===========================================|" << std::endl;
	while (i < 8)
	{	
		if (i >= idx)
			break;
		std::cout << "|" << std::setw(10) << i << "|";
		contacts[i].show_table();
		std::cout << std::endl;
		i++;
	}
	std::cout << "|===========================================|" << std::endl;
	std::cout << "Give me the index for its info: ";
	while (1)
	{
		if (!std::getline(std::cin, asked))
			return ;
		if (asked.empty())
		{	
			std::cout << "input is emptyyy give me the index: ";
			continue;
		}
		else
		{
			asked.erase(0, asked.find_first_not_of(" \t\v\f\r"));
			asked.erase(asked.find_last_not_of(" \t\v\f\r") + 1);
		}
		if (asked.length() == 1 && std::isdigit(asked[0]))
		{	
			search_idx = std::atoi(asked.c_str());
			if (search_idx > 7)
			{
				std::cout << "wrong input re enter the 0 - 7 index: ";
				continue;
			}
			else if (search_idx >= idx)
			{
				std::cout << "This index is not filled, enter another: ";
				continue;
			}
			break ;
		}
		else
		{	
			std::cout << "wrong input re enter the 0 - 7 index: ";
			continue ;
		}
	}
	contacts[search_idx].show_con();
}
