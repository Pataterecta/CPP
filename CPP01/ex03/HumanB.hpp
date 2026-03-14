//jim
#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB {

	private:

	std::string jim;
	Weapon *wea_ptr;

	public:
	HumanB(std::string jim);
	~HumanB();
	void setWeapon(Weapon &wea_ptr);
	void attack();

};

#endif