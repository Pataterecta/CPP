#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* doggy = new Dog();
	const Animal* catty = new Cat();

	std::cout << doggy->getType() << " " << std::endl;
	std::cout << catty->getType() << " " << std::endl;
	catty->makeSound(); //will output the cat sound!
	doggy->makeSound();
	meta->makeSound();

	const WrongAnimal* human = new WrongAnimal();
	const WrongAnimal* hapicat = new WrongCat();

	std::cout << hapicat->getType() << " " << std::endl;
	std::cout << "**************" << std::endl;
	human->makeSound();
	hapicat->makeSound();

	std::cout << "****** yoyo ********" << std::endl;

	const Animal* newmal = new Animal();
	delete newmal;
	newmal = catty;
	newmal-> makeSound();

	std::cout << "******* hoho *******" << std::endl;

	const WrongCat* unhapicat = new WrongCat();
	unhapicat->makeSound();
	std::cout << "**************" << std::endl;

	Animal cow(*catty);
	Animal rabbit(*catty);
	Animal horse(*catty);

	cow = rabbit = horse;

	cow.makeSound();
	std::cout << "**************" << std::endl;

	delete meta;
	delete doggy;
	delete catty;
	delete human;
	delete hapicat;
	delete unhapicat;
	return 0;
}