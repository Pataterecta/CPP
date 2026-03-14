#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {

	private:
	
	std::string type;
	
	public:
	Weapon(std::string type);
	~Weapon();
	const std::string &getType()const;	
	Weapon getType();
	void setType(std::string);
};

#endif