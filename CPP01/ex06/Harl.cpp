#include "Harl.hpp"

Harl::Harl(){

}
Harl::~Harl(){

}

void Harl::debug( void ){

	std::cout << "jgl diff jgl diff" << std::endl;
}

void Harl::info ( void ){
	std::cout << "supp diff supp diff fffff" << std::endl;
}

void Harl::warning ( void ){
	std::cout << "top diff top diff u have tp no?" << std::endl;
}

void Harl::error ( void ){
	std::cout << "team diff 10k gold diff never saw" << std::endl;
}

void Harl::complain( std::string level ){
	// without if else...

	// if not member function -> void(*fp[4])(void);
	void (Harl::*fp[4])(void) =
	{
		&Harl::debug, &Harl::info, &Harl::warning, &Harl::error
	};
	// find function is forbidden cuz in algorithm lib map is forbidden.. no other choice
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		// 외부에선 (harlrl.*fp[0])(); 형태일거니까..
		if (levels[i] == level)
			(this->*fp[i])();
	}
}
