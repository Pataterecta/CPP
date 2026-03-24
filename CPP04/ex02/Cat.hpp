#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{

	private:
	Brain* _brain;

	public:
	Cat();
	Cat (const Cat &orig);
	Cat &operator=(const Cat &orig);
	~Cat();
	Brain* getBrain();
	std::string getIdea(int idx) const;
	void setIdea(int idx, const std::string& input);
	void makeSound() const;
};

#endif