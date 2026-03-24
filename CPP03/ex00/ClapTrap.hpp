#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <sstream>

class ClapTrap {

	// ClapTrap instances should not interact directly with one another
	// and the parameters will not refer to another instance of ClapTrap
	private:

	std::string Name;
	int Hit_p;
	int Energy_p;
	int A_dam;

	public:
	ClapTrap();
	ClapTrap(std::string Name);
	ClapTrap(const ClapTrap &orig);
	ClapTrap &operator=(const ClapTrap &orig);
	~ClapTrap();

	int getHp(void)const;
	std::string toStr(int)const;
	int getEp(void)const;
	bool noHp();
	bool noEp();
	// if no hit point or energy point do nth
	void attack(const std::string& target); // 문자열 리터럴도 받을 수 있음!
	// It causes its target to lose <attack damage> hit points.
	// cause one energy p
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	// It regains <amount> hit points.
	// cause one energy p
};

#endif