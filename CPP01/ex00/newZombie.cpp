#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie *born = new Zombie(name);
	return (born);
}
