#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp" // 필수
#include <iostream>

class Ice : public AMateria {

	// private:
	// std::string _type; <<< 필요 없음!!!!!!!	
	public:
	Ice();
	Ice (const Ice &orig);
	Ice &operator=(const Ice &orig);
	~Ice();
	AMateria* clone() const;
	//use
	void use(ICharacter& target);
};

#endif