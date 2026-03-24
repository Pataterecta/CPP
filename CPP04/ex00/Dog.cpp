#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
}

Dog::Dog (const Dog &orig)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = orig;
}

Dog& Dog::operator=(const Dog &orig)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (!(this == &orig))
		this->type = orig.type;
	return (*this); // 참조 반환
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}


void Dog::makeSound() const
{
	std::cout << "woof woof" << std::endl;
}