#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	// Animal 포인터로 가리키고 있어도, 실제 객체는 Dog 라서 브레인 있음
	// 하지만 Animal 타입 안에는 없어서 접근 불가
	// 이 경우 cat 에다가도 getBrain 을 만들면 해결! 다운 캐스팅도 가능하나 권장x
	// ex : Cat *yoCat = (Cat*)cato; yoCat->_brain->setIdea(...);
	// 포인터 타입이 아닌 실제 생성된 객체 타입이 중요함
	delete j;//should not create a leak
	delete i;

	std::cout << "**********just some extra********" << std::endl;
	Animal* hapiCat = new Cat(); // Dog 으로 넣으면 작동 안된다구~ 근데 dynamic cast 없이 하면 UB 에러 각이어도 작동은 하더라
	hapiCat-> makeSound();
	Cat *yoCat = dynamic_cast<Cat*>(hapiCat);
	if (yoCat)
	{
		yoCat->getBrain()->setIdea(0, "im happycat");
		yoCat->setIdea(2, "say hi");
		std::cout << yoCat->getIdea(0) << std::endl;
		std::cout << yoCat->getIdea(2) << std::endl;
		yoCat-> makeSound();
	
		delete hapiCat;
		std::cout << "*********" << std::endl;
	}
	else
		delete yoCat; // just to show that only pointer for the add so same as hapiCat effect
	
	std::cout << "*****deep copy show ******" << std::endl;
	Dog* deepDog = new Dog();
	Dog* copiedDog = new Dog();
	copiedDog ->setIdea(0, "lets copycopy me");
	*deepDog = *copiedDog;
	std::cout << deepDog->getIdea(0) << std::endl;
	delete deepDog;
	delete copiedDog;
	std::cout << "*** deep copy part end ******" << std::endl;
	std::cout << "*****deep copy show2*********************** ******" << std::endl;
	Cat* copiedCat = new Cat();
	copiedCat ->setIdea(101, "lets copycopycopycopycopy memememe");
	Cat* deepCat = new Cat(*copiedCat);
	std::cout << deepCat->getIdea(101) << std::endl;
	delete copiedCat;
	delete deepCat;
	std::cout << "*****deep copy show2 end*********************** ******" << std::endl;
	std::cout << "****just some wrong animal for in case*****" << std::endl;
	const WrongCat* unhapicat = new WrongCat();
	unhapicat->makeSound();
	delete unhapicat;
	std::cout << "*********" << std::endl;
	Animal *farm[8];
	for (int i = 0; i < 4; i++)
		farm[i] = new Cat();
	for (int i = 4; i < 8; i++)
		farm[i] = new Dog();
	for (int i = 0; i < 8; i++)
		delete farm[i];

	return 0;
}

// int main()
// {
// 	const Animal* meta = new Animal();
// 	const Animal* doggy = new Dog();
// 	const Animal* catty = new Cat();

// 	std::cout << doggy->getType() << " " << std::endl;
// 	std::cout << catty->getType() << " " << std::endl;
// 	catty->makeSound(); //will output the cat sound!
// 	doggy->makeSound();
// 	meta->makeSound();

// 	const WrongAnimal* human = new WrongAnimal();
// 	const WrongAnimal* hapicat = new WrongCat();

// 	std::cout << hapicat->getType() << " " << std::endl;
// 	std::cout << "**************" << std::endl;
// 	human->makeSound();
// 	hapicat->makeSound();

// 	std::cout << "****** yoyo ********" << std::endl;

// 	const Animal* newmal = new Animal();
// 	delete newmal;
// 	newmal = catty;
// 	newmal-> makeSound();

// 	std::cout << "******* hoho *******" << std::endl;

// 	const WrongCat* unhapicat = new WrongCat();
// 	unhapicat->makeSound();
// 	std::cout << "**************" << std::endl;

// 	Animal cow(*catty);
// 	Animal rabbit(*catty);
// 	Animal horse(*catty);

// 	cow = rabbit = horse;

// 	cow.makeSound();
// 	std::cout << "**************" << std::endl;

// 	delete meta;
// 	delete doggy;
// 	delete catty;
// 	delete human;
// 	delete hapicat;
// 	delete unhapicat;
// 	return 0;
// }