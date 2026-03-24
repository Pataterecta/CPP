#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap jgl("i dont want a lot for christmas");
	ScavTrap Supp("NAMI");
	FragTrap Adc("Lucian");
	jgl.attack("happycat");
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
	


	std::cout << "REAL TESTS FOR THE SUBJECT" << std::endl;
	std::cout << "REAL TESTS FOR THE SUBJECT" << std::endl;
	std::cout << "REAL TESTS FOR THE SUBJECT" << std::endl;

	Adc.highFivesGuys();
	Adc.highFivesGuys();
	Adc.highFivesGuys();
	Adc.attack("draven");
	std::cout << "remaining ep is : " << Adc.toStr(Adc.getEp()) << std::endl;
	Adc.attack("elder drake");
	Adc.takeDamage(1);
	std::cout << "remaining hp is : " << Adc.toStr(Adc.getHp()) << std::endl;
	Adc.beRepaired(1);
	std::cout << "remaining hp is : " << Adc.toStr(Adc.getHp()) << std::endl;
	Adc.takeDamage(1);
	std::cout << "remaining hp is : " << Adc.toStr(Adc.getHp()) << std::endl;
	Adc.takeDamage(1);
	std::cout << "remaining hp is : " << Adc.toStr(Adc.getHp()) << std::endl;
	Adc.takeDamage(1);
	std::cout << "remaining hp is : " << Adc.toStr(Adc.getHp()) << std::endl;
	Adc.beRepaired(100);
	std::cout << "remaining hp is : " << Adc.toStr(Adc.getHp()) << std::endl;
	Adc.attack("evil jgl");
	std::cout << "remaining ep is : " << Adc.toStr(Adc.getEp()) << std::endl;
	Adc.takeDamage(10);
	std::cout << "remaining hp is : " << Adc.toStr(Adc.getHp()) << std::endl;
	Adc.takeDamage(1);
	std::cout << "remaining hp is : " << Adc.toStr(Adc.getHp()) << std::endl;
	Adc.attack("cs");
	std::cout << "remaining hp is : " << Adc.toStr(Adc.getHp()) << std::endl;
	Adc.takeDamage(10);
	std::cout << "remaining hp is : " << Adc.toStr(Adc.getHp()) << std::endl;
	for (int i = 0; i < 9; i++)
	{
		Adc.takeDamage(10);
		std::cout << "remaining hp is : " << Adc.toStr(Adc.getHp()) << std::endl;
	}
	Supp.attack("evil jgl");
	std::cout << "remaining ep is : " << Adc.toStr(Adc.getEp()) << std::endl;
	Supp.beRepaired(100);
	std::cout << "remaining hp is : " << Adc.toStr(Adc.getHp()) << std::endl;
	Adc.highFivesGuys();

	return (0);
}

// int	main(void)
// {
// 	ClapTrap Supp("NAMI");
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
