#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
	protected:

	std::string type;

	public:

	Animal();
	Animal (const Animal &orig);
	Animal &operator=(const Animal &orig);
	virtual ~Animal();

	std::string getType() const;
	virtual void makeSound() const;
};

#endif