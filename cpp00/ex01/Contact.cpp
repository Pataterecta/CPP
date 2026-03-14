#include "Contact.hpp"

void Contact::set_con()
{
	std::string input;
	int	i = 0;	
	while (i < 5)
	{
		while (1){
		std::cout << "prenom plz: ";		
		if (!std::getline(std::cin, input))
			return ;
		if (input.empty())
		{
			std::cout << "input is emptyyy" << std::endl;
			continue;
		}
		else
		{
			input.erase(0, input.find_first_not_of(" \t\v\f\r"));
			input.erase(input.find_last_not_of(" \t\v\f\r") + 1);
		}
		prenom = input;
		break ;
		}
		i++;
		while (1){
		std::cout << "surnom plz: ";		
		if (!std::getline(std::cin, input))
			return ;
		if (input.empty())
		{	
			std::cout << "input is emptyyy" << std::endl;
			continue;
		}
		else
		{
			input.erase(0, input.find_first_not_of(" \t\v\f\r"));
			input.erase(input.find_last_not_of(" \t\v\f\r") + 1);
		}
		surnom = input;
		break ;
		}
		i++;
		while (1){
		std::cout << "nickname plz: ";		
		if (!std::getline(std::cin, input))
			return ;
		if (input.empty())
		{	
			std::cout << "input is emptyyy" << std::endl;
			continue ;
		}
		else
		{
			input.erase(0, input.find_first_not_of(" \t\v\f\r"));
			input.erase(input.find_last_not_of(" \t\v\f\r") + 1);
		}
		nicknom = input;
		break ;
		}
		i++;
		while (1){
		std::cout << "phone number plz: ";		
		if (!std::getline(std::cin, input))
			return ;
		if (input.empty())
		{	
			std::cout << "input is emptyyy" << std::endl;
			continue ;
		}
		else
		{
			input.erase(0, input.find_first_not_of(" \t\v\f\r"));
			input.erase(input.find_last_not_of(" \t\v\f\r") + 1);
		}
		p_num = input;
		break ;
		}
		i++;
		while(1){
		std::cout << "dark secret plz: ";		
		if (!std::getline(std::cin, input))
			return ;
		if (input.empty())
		{	
			std::cout << "input is emptyyy" << std::endl;
			continue ;
		}
		else
		{
			input.erase(0, input.find_first_not_of(" \t\v\f\r"));
			input.erase(input.find_last_not_of(" \t\v\f\r") + 1);
		}
		dsecret = input;
		break ;
		}
		i++;				
	}
	return ;
}

static void print_elements(const std::string& str)
{
	if (str.length() > 10)
		std::cout << str.substr(0, 9) << '.';
	else
		std::cout << std::setw(10) << str;
}

void Contact::show_table()
{
	print_elements(prenom);
	std::cout << "|";
	print_elements(surnom);
	std::cout << "|";
	print_elements(nicknom);
	std::cout << "|";
}
void Contact::show_con()
{
	std::cout << "First name: " << prenom << std::endl;
	std::cout << "Surname: "<< surnom << std::endl;
	std::cout << "Nickname: " << nicknom << std::endl;
	std::cout << "Phonenumber: " << p_num << std::endl;
	std::cout << "Darkest secret: " << dsecret << std::endl;
	return ;
}
