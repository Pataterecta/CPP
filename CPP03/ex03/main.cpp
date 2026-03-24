// #include "ClapTrap.hpp"
// #include "ScavTrap.hpp"
// #include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	ClapTrap jgl("i dont want a lot for christmas");
	DiamondTrap Supp("NAMI");
	jgl.attack("happycat");
	std::cout << "********************" << std::endl;
	std::cout << "********************" << std::endl;

	Supp.whoAmI();
	std::cout << "********************" << std::endl;

	Supp.attack("draven");
	std::cout << "remaining ep is : " << Supp.toStr(Supp.getEp()) << std::endl;
	Supp.attack("elder drake");
	Supp.takeDamage(1);
	std::cout << "remaining hp is : " << Supp.toStr(Supp.getHp()) << std::endl;
	std::cout << "********************" << std::endl;
	std::cout << "********************" << std::endl;

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

	std::cout << "********************" << std::endl;
	std::cout << "********************" << std::endl;
	Supp.whoAmI();
	std::cout << "********************" << std::endl;
	return (0);
}

// int	main(void)
// {
// 	DiamondTrap Supp("NAMI");
// 	FragTrap Adc("Lucian");

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
// 	std::cout << "REAL TESTS FOR THE SUBJECT" << std::endl;
// 	std::cout << "REAL TESTS FOR THE SUBJECT" << std::endl;
// 	std::cout << "REAL TESTS FOR THE SUBJECT" << std::endl;
// 	for (int i = 0; i < 50; i++)
// 	{
// 		Adc.attack("draven");
// 		std::cout << "remaining ep is : " << Adc.toStr(Adc.getEp()) << std::endl;
// 	}
// 	Adc.beRepaired(100);
// 	std::cout << "remaining hp is : " << Adc.toStr(Adc.getHp()) << std::endl;
// 	Adc.beRepaired(100);
// 	std::cout << "remaining hp is : " << Adc.toStr(Adc.getHp()) << std::endl;
// 	return (0);
// }
