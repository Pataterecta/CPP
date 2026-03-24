#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <sstream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

	private:

	public:
	FragTrap();
	// setter 없어도 initilizer list 로 가능
	// !!! protected 로 바꿔도 즉 접근 제한자랑 관련 없이 반드시 호출 되어야 함
	FragTrap(std::string Name);
	FragTrap(const FragTrap &orig); // 구현에서 상속 실현
	FragTrap &operator=(const FragTrap &orig); // 구현에서 상속 실현
	~FragTrap(); // ~ScavTrap(); 로 하면 구현 따로 필요 없이 자동으로 부모까지 호출 됨 더블 방지

	void highFivesGuys();
};

#endif
