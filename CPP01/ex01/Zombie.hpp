# ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <fstream> //std::filebuf, std::ifstream
#include <sstream> //stringstream

class Zombie {
	private:

	std::string name;
	Zombie* _firstBorn;

	public:
	Zombie();
	// void 	initNames(int N, std::string name);
	void	announce();
	void	setName(std::string name);
	Zombie* getZombie();
};

Zombie* zombieHorde(int N, std::string name);

#endif