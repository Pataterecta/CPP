#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : Hit_p(10), Energy_p(10), A_dam(0), hpMax(10)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string Name) : Name(Name), Hit_p(10), Energy_p(10), A_dam(0), hpMax(10)
{
	std::cout << "ClapTrap Parameterized constructor called" << std::endl;
	std::cout << "ClapTrap player created : " << this->Name << " with MAX HP: " << toStr(this->Hit_p) << " MAX EP: " << toStr(this->Energy_p) << " Attack dmg: " << toStr(this->A_dam) << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &orig)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;

	*this = orig;
}

/* 더 나은 방식 
ClapTrap::ClapTrap(const ClapTrap &orig): Name(orig.Name), Hit_p(orig.Hit_p), Energy_p(orig.Energy_p), A_dam(orig.A_dam)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
}
*/

ClapTrap& ClapTrap::operator=(const ClapTrap &orig)
{
	if (!(this == &orig)) // 같은 객체인지 확인, 주소 비교 / 자기 자신 대입하면 문제 생길 수 있음
	{	
		this->Name = orig.Name;
		this->Hit_p = orig.Hit_p;
		this->Energy_p = orig.Energy_p;
		this->A_dam = orig.A_dam;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
	std::cout << "ClapTrap " << "ByeBye " << this->Name << std::endl;
}


int ClapTrap::getHp(void)const
{
	// std::cout << "getHp member function called" << std::endl;
	return (this->Hit_p);
}

int ClapTrap::getEp(void)const
{
	// std::cout << "getEp member function called" << std::endl;
	return (this->Energy_p);
}

bool ClapTrap::noHp()
{
	if (this->Hit_p == 0)
	{	
		std::cout << "ClapTrap " << this->Name << " has no HIT POINT" << std::endl;
		return (true);
	}
	return (false);
}

bool ClapTrap::noEp()
{
	if (this->Energy_p == 0)
	{
		std::cout << "ClapTrap " << this->Name << " has no ENERGY POINT" << std::endl;
		return (true);
	}
	return (false);
}

std::string ClapTrap::toStr(int value)const
{
	std::stringstream ss;
	ss << value;
	std::string value_str;
	ss >> value_str;
	return (value_str);
}

// if no hit point or energy point do nth
void ClapTrap::attack(const std::string& target)
{
	if (noHp() || noEp())
		return ;
	std::stringstream ss1;
	ss1 << this->A_dam;
	std::string dmg_str;
	ss1 >> dmg_str;
	this->Energy_p = this->Energy_p - 1;
	std::cout << "ClapTrap " << this->Name << " attacks " << target << " causing " << dmg_str << " points of damage!" << std::endl;
	// It causes its target to lose <attack damage> hit points.
	// cause one energy p
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::stringstream ss2;
	ss2 << amount;
	std::string take_str;
	ss2 >> take_str;
	if (this->Hit_p == 0)
	{	
		std::cout << "ClapTrap " << this->Name << " got dmg but Already DEAD" << std::endl;
		return ;
	}
	if ((int)amount >= this->Hit_p)
		this->Hit_p = 0;
	else
		this->Hit_p = this->Hit_p - (int)amount;
	std::cout << "ClapTrap " << this->Name << " got " << take_str << " amount of dmg!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (noHp() || noEp())
		return ;

	std::stringstream ss3;
	ss3 << amount;
	std::string rep_str;
	ss3 >> rep_str;
	if (amount + this->Hit_p > this->hpMax)
	{
		std::cout << "ClapTrap " << this->Name << " tried a lot for " << rep_str << " points but Heal max to " << toStr(hpMax)  << " tho!(hit points repaired to hpMax)" << std::endl;
		this->Hit_p = this->hpMax;
		return ;
	}
	else
		this->Hit_p = this->Hit_p + amount;
	this->Energy_p = this->Energy_p - 1;
	std::cout << "ClapTrap " << this->Name << " repairs itself " << rep_str << " hit points!" << std::endl;
	// It regains <amount> hit points.
	// cause one energy p
}
