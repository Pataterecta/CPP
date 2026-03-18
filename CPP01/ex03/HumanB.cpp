#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->weapon = NULL;
	this->name = name;
}

HumanB::~HumanB(){

}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void HumanB::attack()
{
	if (this -> weapon == NULL)
	{
		std::cout << "ATTACK WITH HANDSSSS" << std::endl;
	}
	else
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl; 
}
