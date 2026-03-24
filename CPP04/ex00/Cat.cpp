#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat (const Cat &orig)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = orig;
}

Cat& Cat::operator=(const Cat &orig)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (!(this == &orig))
		this->type = orig.type;
	return (*this); // 참조 반환
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "MiAoUoUoUoUoUoUmIaOuYeAh" << std::endl;
}
