#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <sstream>

class Animal {
	protected:

	std::string type;

	public:

	Animal();
	Animal (const Animal &orig);
	Animal &operator=(const Animal &orig);
	virtual ~Animal();

	std::string toStr(int value)const;

	std::string getType() const;
	virtual void makeSound() const = 0;
};

#endif