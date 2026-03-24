#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {

	private:

	public:
	Dog();
	Dog (const Dog &orig);
	Dog &operator=(const Dog &orig);
	~Dog ();
	void makeSound() const;
};

#endif