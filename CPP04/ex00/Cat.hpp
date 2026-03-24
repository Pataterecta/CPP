#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal{

	private:

	public:
	Cat();
	Cat (const Cat &orig);
	Cat &operator=(const Cat &orig);
	~Cat();
	void makeSound() const;
};

#endif