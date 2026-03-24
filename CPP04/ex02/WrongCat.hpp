#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{

	private:

	public:
	WrongCat();
	WrongCat (const WrongCat &orig);
	WrongCat &operator=(const WrongCat &orig);
	~WrongCat();
	void makeSound() const;
};

#endif