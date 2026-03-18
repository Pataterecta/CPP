#include "Harl.hpp"

int	main(void)
{
	Harl Harl;
	std::cout << "its a demonstration of how Harl_adc is harling" << std::endl << std::endl;

	Harl.complain("DEBUG");
	Harl.complain("INFO");
	Harl.complain("WARNING");
	Harl.complain("ERROR");

	std::string asked;
	std::cout <<std::endl << "this version is only for a personal training and mandatory is already done on the upper side" << std::endl;
	while (true)
	{
		std::cout << "enter the command: " << std::endl;
		if (!std::getline(std::cin, asked))
			break ;
		if (asked.empty())
		{std::cout << "input is emptyy give me the right command: ";
			continue;
		}
		if (asked == "EXIT")
			break;
		Harl.complain(asked);
		// if (asked == "DEBUG")
		// 	Harl.complain("DEBUG");
		// else if (asked == "INFO")
		// 	Harl.complain("INFO");
		// else if (asked == "WARNING")
		// 	Harl.complain("WARNING");
		// else if (asked == "ERROR")
		// 	Harl.complain("ERROR");
		// else
		// 	std::cout << "wrong input continue with DEBUG INFO WARNING ERROR: " << std::endl;
	}
	return (0);
}
