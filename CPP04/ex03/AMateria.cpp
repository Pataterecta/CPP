#include "AMateria.hpp"

AMateria::AMateria()
{
}

AMateria::AMateria(std::string const & type) : _type(type)
{
}

AMateria::AMateria(const AMateria& orig) : _type(orig._type)
{
	*this = orig;
}

AMateria& AMateria::operator=(const AMateria &orig)
{
	if (!(this == &orig))
	{
		this->_type = orig._type;
	}
	return (*this);
}


AMateria::~AMateria()
{
}


std::string const & AMateria::getType() const //Returns the materia type
{
	return (this->_type);
}

// ICharacter : virtual void use(int idx, ICharacter& target) = 0;
// Ice: "* shoots an ice bolt at <name> *"
// Cure: "* heals <name>’s wounds *"
// name is the target 
// me->use(0, *bob);
// Character 가 use 하면 내부적으로 

void AMateria::use(ICharacter& target) // 공통 기본 동작
{
	(void)target;
	// Ice
	// Cure
	// void(target); header problem
	// I prefer this function as pure abstract but subject
}

// if not for the object of the subject 
// i can go dynamic cast and check if its Ice or Cure by downcasting..