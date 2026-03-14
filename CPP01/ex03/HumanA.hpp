	//bob
#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA {

	private:
	
	std::string bob;
	Weapon &wea_ref;

	public:
	HumanA(std::string bob, Weapon &wea_ref);
	~HumanA();
	void attack();
};

#endif