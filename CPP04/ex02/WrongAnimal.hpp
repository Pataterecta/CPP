#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
	protected:

	std::string type;

	public:

	WrongAnimal();
	WrongAnimal (const WrongAnimal &orig);
	WrongAnimal &operator=(const WrongAnimal &orig);
	virtual ~WrongAnimal();

	std::string getType() const;
	void makeSound() const;
};

#endif