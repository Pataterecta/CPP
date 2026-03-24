#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp" // 필수
#include <iostream>

class Cure : public AMateria {

	// private:

	// std::string _type; <<< 필요 없음!!!!!!!!!

	public:
	Cure();
	Cure (const Cure &orig);
	Cure &operator=(const Cure &orig);
	~Cure();
	AMateria* clone() const;
	// use
	void use(ICharacter& target);
};

#endif