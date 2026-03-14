#include "Zombie.hpp"

Zombie::Zombie() : _firstBorn(NULL)
{
}

Zombie* Zombie::getZombie()
{
	return (_firstBorn);
}

void	Zombie::setName(std::string name)
{
	this->name = name;
	return ;
}

// void	Zombie::initNames(int N, std::string name)
// {
// 	for (int i = 0; i < N; i++)
// 	{
// 		std::stringstream ss;
// 		ss << i;
// 		std::string i_str;
// 		ss >> i_str;

// 		_firstBorn[i].setName(name + i_str);
// 	}
// 	return ;
// }

void	Zombie::announce()
{
	// std::stringstream ss;
	// ss << idx;
	// std::string idx_str;
	// ss >> idx_str;
	
	std::cout << this->name << " says" ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}
