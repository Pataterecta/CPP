#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal (const Animal &orig) : type(orig.type)
{
	std::cout << "Animal Parameterized constructor called" << std::endl;
	*this = orig;
}

Animal& Animal::operator=(const Animal &orig)
{
	std::cout << "Animal assignment operator called" << std::endl;
	if (!(this == &orig))
		this->type = orig.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called" << std::endl;
}

std::string Animal::toStr(int value)const
{
	std::stringstream ss;
	ss << value;
	std::string value_str;
	ss >> value_str;
	return (value_str);
}

std::string Animal::getType() const
{
	return (this->type);
}

void Animal::makeSound() const
{
	// std::cout << "(ANI SILENCE: LEGENDS NEVER DIEEEEEE)" << std::endl;
}
