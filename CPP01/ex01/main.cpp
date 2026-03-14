#include "Zombie.hpp"

int	main(void)
{
	Zombie* _firstBorn;
	std::string name;

	name = "grrrombie";
	int how_many = 9;
	_firstBorn = zombieHorde(how_many, name);
	std::cout << "!!!SHOUT EVERY ZOMBITOS!!!" << std::endl;
	for (int i = 0; i < how_many; i++)
		_firstBorn[i].announce();
	delete []_firstBorn;
	std::cout << "WOW Sooo FuRiOuSsSs(the end)" << std::endl;
	return 0;
}
