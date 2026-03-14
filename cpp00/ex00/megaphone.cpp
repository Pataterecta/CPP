// $>./megaphone "shhhhh... I think the students are asleep..."
// SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
// $>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
// DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
// $>./megaphone
// * LOUD AND UNBEARABLE FEEDBACK NOISE *
// $>

#include <iostream>
#include <string>

int	main(int ac, char **av)
{
	if (ac != 2 && ac != 1)
		return 0;
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	if (ac == 2)
	{	
		for (int i = 0; av[1][i]; i++)		
			std::cout << (char)std::toupper((unsigned char)av[1][i]);
		std::cout << std::endl;
	}
	return 0;
}
