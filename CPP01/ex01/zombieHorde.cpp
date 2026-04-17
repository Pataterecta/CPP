#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	// vaut mieux proteger cette valeur de N pas de moins.. pas de overflow..
	Zombie* _firstBorn = new Zombie[N];
	
	for (int i = 0; i < N; i++)
	{
		std::stringstream ss;
		ss << i + 1;
		std::string i_str;
		ss >> i_str;

		_firstBorn[i].setName(name + i_str);
	}
	std::stringstream ss;
	ss << N;
	std::string N_str;
	ss >> N_str;	
	std::cout << "*Num 1 to " << N_str << " zombiesss init and got his own name with NUM*" << std::endl;
	std::cout << "(I set their name with the number so not just printing it separately so cooool)" << std::endl;
	std::cout << std::endl << "....wait" << std::endl;
	return(_firstBorn);
}
