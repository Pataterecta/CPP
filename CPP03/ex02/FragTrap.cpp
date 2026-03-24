#include "ClapTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	//디폴트 생성자가 ClapTrap 에 있어서 자동으로 ClapTrap() 호출됨
	// 자기 자신이 ClapTrap 이기도 함
	// 데이터와 기능을 자기 내부에 포함한 채 상속 규칙에 따라 사용하고 자기만의 요소를 덧붙임
	this->Hit_p = 100;
	this->Energy_p = 100;
	this->A_dam = 30;
	this->hpMax = 100;
	std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->Hit_p = 100;
	this->Energy_p = 100;
	this->A_dam = 30;
	this->hpMax = 100;
	// 부모 부분 생성 -> 생성자 본문 진입 -> 존재하는 부모값에 대입
	std::cout << "FragTrap Parameterized constructor called" << std::endl;
	std::cout << "FragTrap player created : " << this->Name << " with MAX HP: " << toStr(this->Hit_p) << " MAX EP: " << toStr(this->Energy_p) << " Attack dmg: " << toStr(this->A_dam) << std::endl;
	// this 안 써도 되긴 함
}

FragTrap::FragTrap(const FragTrap &orig) : ClapTrap(orig)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &orig)
{
	if (!(this == &orig))
	{	
		FragTrap::operator=(orig);
		// Scav 고유 멤버 있을시 복사
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
	std::cout << "FragTrap " << "ByeBye " << this->Name << std::endl;
}

void FragTrap::highFivesGuys()
{
	if (noHp())
		return ;
	std::cout << "FragTrap " << this->Name << " says give me high five hehe" << std::endl;
}
