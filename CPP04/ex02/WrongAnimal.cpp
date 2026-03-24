#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Wrong Animal Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal (const WrongAnimal &orig) : type(orig.type)
{
	std::cout << "Wrong Animal Parameterized constructor called" << std::endl;
	*this = orig;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &orig)
{
	std::cout << "Wrong Animal assignment operator called" << std::endl;
	if (!(this == &orig))
		this->type = orig.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Wrong Animal Destructor called" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "(WRONG ANI SILENCE: Im a human and wrong animal)" << std::endl;
}
