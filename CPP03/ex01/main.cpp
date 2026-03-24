#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap Supp("NAMI");

	Supp.guardGate();
	Supp.attack("draven");
	std::cout << "remaining ep is : " << Supp.toStr(Supp.getEp()) << std::endl;
	Supp.attack("elder drake");
	Supp.takeDamage(1);
	std::cout << "remaining hp is : " << Supp.toStr(Supp.getHp()) << std::endl;
	Supp.beRepaired(1);
	std::cout << "remaining hp is : " << Supp.toStr(Supp.getHp()) << std::endl;
	Supp.takeDamage(1);
	std::cout << "remaining hp is : " << Supp.toStr(Supp.getHp()) << std::endl;
	Supp.takeDamage(1);
	std::cout << "remaining hp is : " << Supp.toStr(Supp.getHp()) << std::endl;
	Supp.takeDamage(1);
	std::cout << "remaining hp is : " << Supp.toStr(Supp.getHp()) << std::endl;
	Supp.beRepaired(100);
	std::cout << "remaining hp is : " << Supp.toStr(Supp.getHp()) << std::endl;
	Supp.attack("evil jgl");
	std::cout << "remaining ep is : " << Supp.toStr(Supp.getEp()) << std::endl;
	Supp.takeDamage(10);
	std::cout << "remaining hp is : " << Supp.toStr(Supp.getHp()) << std::endl;
	Supp.takeDamage(1);
	std::cout << "remaining hp is : " << Supp.toStr(Supp.getHp()) << std::endl;
	Supp.attack("cs");
	std::cout << "remaining hp is : " << Supp.toStr(Supp.getHp()) << std::endl;
	Supp.takeDamage(10);
	std::cout << "remaining hp is : " << Supp.toStr(Supp.getHp()) << std::endl;
	for (int i = 0; i < 9; i++)
	{
		Supp.takeDamage(10);
		std::cout << "remaining hp is : " << Supp.toStr(Supp.getHp()) << std::endl;
	}
	Supp.attack("evil jgl");
	std::cout << "remaining ep is : " << Supp.toStr(Supp.getEp()) << std::endl;
	Supp.beRepaired(100);
	std::cout << "remaining hp is : " << Supp.toStr(Supp.getHp()) << std::endl;
	Supp.guardGate();
	return (0);
}

// int	main(void)
// {
// 	ClapTrap Supp("NAMI");

// 	for (int i = 0; i < 50; i++)
// 	{
// 		Supp.attack("draven");
// 		std::cout << "remaining ep is : " << Supp.toStr(Supp.getEp()) << std::endl;
// 	}
// 	Supp.beRepaired(100);
// 	std::cout << "remaining hp is : " << Supp.toStr(Supp.getHp()) << std::endl;
// 	Supp.beRepaired(100);
// 	std::cout << "remaining hp is : " << Supp.toStr(Supp.getHp()) << std::endl;
// 	return (0);
// }
