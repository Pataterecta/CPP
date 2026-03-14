#include "HumanA.hpp"

HumanA::HumanA(std::string bob, Weapon &wea_ref)
: bob(bob), wea_ref(wea_ref)
{
}

HumanA::~HumanA(){

}

void HumanA::attack()
{
	std::cout << this->bob << "go hit that guy with: " << this->wea_ref.getType() << std::endl;
}