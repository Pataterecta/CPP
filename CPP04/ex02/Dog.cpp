#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	_brain = new Brain();
}

Dog::Dog (const Dog &orig) : _brain(new Brain(*orig._brain))
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &orig)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (!(this == &orig))
	{	
		delete _brain;
		this->_brain = new Brain(*orig._brain);
	}
	return (*this); // 참조 반환
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

Brain* Dog::getBrain()
{
	return (this->_brain);
}
// 이건 외부 코드가 Brain 내부까지 만져서 좋은 함수는 아니라 하네.. 
// cat 이 Brain 을 가지고 있다는게 보여서 / 또 구현에 의존해서

std::string Dog::getIdea(int idx) const
{
	if (idx < 0 || idx >= 100)
		throw std::out_of_range("wrong idx to set: use IDX 0 to 99");
	return _brain->getIdea(idx);
}

void Dog::setIdea(int idx, const std::string& input)
{
	if (idx < 0 || idx >= 100)
	{	
		std::cout << "wrong idx to set: use IDX 0 to 99" << std::endl;
		return ;
	}
	_brain->setIdea(idx, input);
}

void Dog::makeSound() const
{
	std::cout << "woof woof" << std::endl;
}