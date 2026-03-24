#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat default constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat (const WrongCat &orig)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = orig;
}

WrongCat& WrongCat::operator=(const WrongCat &orig)
{
	std::cout << "WrongCat assignment operator called" << std::endl;
	if (!(this == &orig))
		this->type = orig.type;
	return (*this); // 참조 반환
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "MiAoUoUoUoUoUoUmIaOuYeAh" << std::endl;
}
