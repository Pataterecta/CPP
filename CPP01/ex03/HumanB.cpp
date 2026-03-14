#include "HumanB.hpp"

HumanB::HumanB(std::string jim)
{
	this->jim = jim;
}

HumanB::~HumanB(){

}

void	HumanB::setWeapon(Weapon &wea_ptr)
{
	this->wea_ptr = &wea_ptr;
}

void HumanB::attack()
{
	std::cout << this->jim << " goes and crack his leg with this " << this->wea_ptr->getType() << std::endl; 
}
