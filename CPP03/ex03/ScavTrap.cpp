#include "ScavTrap.hpp"

// ScavTrap::ScavTrap() : ClapTrap("Scavito")
// {
//  // 가능한 문법
// 	// ScavTrap 을 만들 때 부모의 Name 을 Scav 로 초기화 하겠다
// 	// 자기 자신이 ClapTrap 이기도 함
// 	// 데이터와 기능을 자기 내부에 포함한 채 상속 규칙에 따라 사용하고 자기만의 요소를 덧붙임
// }

// !!!!!!!!!!!!!!!!!!!!!!!!!!!! 문제 상황!!!!!
// ScavTrap::ScavTrap() : ClapTrap
// {
// 	//디폴트 생성자가 ClapTrap 에 있어서 자동으로 ClapTrap() 호출됨
// 	// 자기 자신이 ClapTrap 이기도 함
// 	// 데이터와 기능을 자기 내부에 포함한 채 상속 규칙에 따라 사용하고 자기만의 요소를 덧붙임
// 	std::cout << "ScavTrap Default constructor called" << std::endl;
// }

// ScavTrap::ScavTrap(std::string name) : ClapTrap(name), Hit_p(100), Energy_p(50), A_dam(20)
// {
// 	std::cout << "ClapTrap Parameterized constructor called" << std::endl;
// 	std::cout << "ScavTrap player created : " << this->Name << " with MAX HP: " << toStr(this->Hit_p) << " MAX EP: " << toStr(this->Energy_p) << " Attack dmg: " << toStr(this->A_dam) << std::endl;
// } 초기화 리스트 이렇게 못씀.. / 처음에 이게 되는듯 보였던 이유는 변수들을 .hpp 에 다시 만들었어서 그럼
// 결국 각각 다른값에 난리 부르스를 친것임 (ex 부모는 넣은 이름 그대로 만들어지고 부모 디폴트 패러 같고 자식은 이름 없이 이닛한 값 갖고 ㅋㅋㅋ)
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

ScavTrap::ScavTrap() : ClapTrap()
{
	//디폴트 생성자가 ClapTrap 에 있어서 자동으로 ClapTrap() 호출됨
	// 자기 자신이 ClapTrap 이기도 함
	// 데이터와 기능을 자기 내부에 포함한 채 상속 규칙에 따라 사용하고 자기만의 요소를 덧붙임
	this->Hit_p = 100;
	this->Energy_p = 50;
	this->A_dam = 20;
	this->hpMax = 100;
	std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->Hit_p = 100;
	this->Energy_p = 50;
	this->A_dam = 20;
	this->hpMax = 100;
	// 부모 부분 생성 -> 생성자 본문 진입 -> 존재하는 부모값에 대입
	std::cout << "ScavTrap Parameterized constructor called" << std::endl;
	std::cout << "ScavTrap player created : " << this->Name << " with MAX HP: " << toStr(this->Hit_p) << " MAX EP: " << toStr(this->Energy_p) << " Attack dmg: " << toStr(this->A_dam) << std::endl;
	// this 안 써도 되긴 함
}

ScavTrap::ScavTrap(const ScavTrap &orig) : ClapTrap(orig)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &orig)
{
	if (!(this == &orig))
	{	
		ClapTrap::operator=(orig);
		// Scav 고유 멤버 있을시 복사
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
	std::cout << "ScavTrap " << "ByeBye " << this->Name << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (noHp() || noEp())
		return ;
	std::stringstream ss1;
	ss1 << this->A_dam;
	std::string dmg_str;
	ss1 >> dmg_str;
	this->Energy_p = this->Energy_p - 1;
	std::cout << "ScavTrap " << this->Name << " attacks " << target << " causing " << dmg_str << " points of damage!" << std::endl;
	// It causes its target to lose <attack damage> hit points.
	// cause one energy p
}

void ScavTrap::guardGate()
{
	if (noHp())
		return ;
	std::cout << "ScavTrap " << this->Name << " is now in Gate keeper mode" << std::endl;
}
