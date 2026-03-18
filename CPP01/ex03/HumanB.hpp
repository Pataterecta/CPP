//jim
#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB {

	private:

	std::string name;
	Weapon *weapon;

	public:
	HumanB(std::string name);
	~HumanB();
	void setWeapon(Weapon &weapon);
	// Weapon 객체룰 레퍼런스로 받아서 이후 클래스 휴먼비에서 얘를 가르키도록 만드는 것임
	// Weapon &weapon : 외부 Weapon 객체
	// this->weapon HumanB 가 가진 포인터
	// &weapon Weapon 객체 주소
	void attack();

};

#endif  