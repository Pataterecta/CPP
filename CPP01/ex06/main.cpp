#include "Harl.hpp"

int	main(int ac, char **av)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	Harl harl;

	if (ac != 2)
	{
		std::cout << "ac should be 2" << std::endl;
		return (1);
	}
	std::string happy = av[1];
	if (happy != "DEBUG" && happy != "INFO" && happy != "WARNING" && happy != "ERROR")
	{
		std::cout << "wrong input" << std::endl;
		return (1);
	}
	int i = 0;
	for (; i < 4; i++)
	{
		if(levels[i] == av[1])
			break;
	}
	int checker = i + 1;
	switch(checker)
	{
		case 1:
			harl.complain("DEBUG");
		case 2:
			harl.complain("INFO");
		case 3:
			harl.complain("WARNING");
		case 4: 
		{	
			harl.complain("ERROR");
			break ;
		}
	}
	return (0);
}