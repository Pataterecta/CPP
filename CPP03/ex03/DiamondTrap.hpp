#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include <sstream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {

	private:
	std::string Name;

	public:
	DiamondTrap();
	// setter 없어도 initilizer list 로 가능
	// !!! protected 로 바꿔도 즉 접근 제한자랑 관련 없이 반드시 호출 되어야 함
	DiamondTrap(std::string Name);
	DiamondTrap(const DiamondTrap &orig); // 구현에서 상속 실현
	DiamondTrap &operator=(const DiamondTrap &orig); // 구현에서 상속 실현
	~DiamondTrap(); // ~ScavTrap(); 로 하면 구현 따로 필요 없이 자동으로 부모까지 호출 됨 더블 방지

	void whoAmI();
};

#endif

// 소멸자 관련하여 : virtual ~ClapTrap() 해두면 Scav Frag Dia 전부 모두 virtual 소멸자 체인
// 규칙 : 부모의 함수가 virtual 이면 자식에서 override 한 것도 자동으로 virtual
// ex : ClapTrap* ptr = new DiamondTrap("NAMI"); delete ptr; 경우 
// 호출 순서 ~Dia ~Scav ~Frag ~Clap (Scav Frag 순서는 어케 짰냐에 따라 조금 다르겠지먼)
// 상속 트리 전체에 적용됨 = virtual destructor 는 최상위 부모에 한번만