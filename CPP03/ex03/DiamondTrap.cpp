#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
	//디폴트 생성자가 ClapTrap 에 있어서 자동으로 ClapTrap() 호출됨
	// 자기 자신이 ClapTrap 이기도 함
	// 데이터와 기능을 자기 내부에 포함한 채 상속 규칙에 따라 사용하고 자기만의 요소를 덧붙임
	ClapTrap::Name = "_clap_name";
	this->Hit_p = FragTrap::hpDefault;
	this->Energy_p = ScavTrap::engDefault;
	this->A_dam = FragTrap::dmgDefault;
	this->hpMax = FragTrap::hpDefault;
	std::cout << "DiamondTrap Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) // 클래스 부분을 초기화 하는 것
{
	// ClapTrap 은 DiamondTrap 이 직접 초기화, 나머지는 자기 부분 초기화
	this->Name = name;
	this->Hit_p = FragTrap::hpDefault;
	this->Energy_p = ScavTrap::engDefault;
	this->A_dam = FragTrap::dmgDefault;
	this->hpMax = FragTrap::hpDefault;
	// 부모 부분 생성 -> 생성자 본문 진입 -> 존재하는 부모값에 대입
	std::cout << "DiamondTrap Parameterized constructor called" << std::endl;
	std::cout << "DiamondTrap player created : " << this->Name << " with MAX HP: " << toStr(this->Hit_p) << " MAX EP: " << toStr(this->Energy_p) << " Attack dmg: " << toStr(this->A_dam) << std::endl;
	// this 안 써도 되긴 함
}

DiamondTrap::DiamondTrap(const DiamondTrap &orig) : ClapTrap(orig)
{
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &orig)
{
	if (!(this == &orig))
	{	
		DiamondTrap::operator=(orig);
		// Scav 고유 멤버 있을시 복사
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
	std::cout << "DiamondTrap " << "ByeBye " << this->Name << std::endl;
}

void DiamondTrap::whoAmI()
{
	if (noHp())
		return ;
	std::cout << "DiamondTrap NAME: " << this->Name << std::endl;
	std::cout << "ClapTrap NAME: " << ClapTrap::Name << std::endl;
}
