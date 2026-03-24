#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	_brain = new Brain();
	// 사실 클래스에서는 () 있으나 없으나 기본 생성자 호출이라 ㄱㅊ
	// 기본형 (int 등)에서는 차이 있음
	// int* a = new int; -> 초기화 안됨 (쓰레기 값)
	// int* b = new int(); -> 0으로 초기화
}

Cat::Cat(const Cat& orig) : _brain(new Brain(*orig._brain))
{
	std::cout << "Cat copy constructor called" << std::endl;
}
// Cat::Cat(const Cat& orig) : Animal(orig), _brain(new Brain(*orig._brain))
// 쪽이 더 명시적이긴 함..

// 대입 방식
// Cat::Cat (const Cat &orig) // 아직 아무것도 없음
// {
// 	std::cout << "Cat copy constructor called" << std::endl;
// 	this->_brain = new Brain(*orig._brain);
// 	 아 근데 캣에 타입 없음 ㅋㅋㅋㅋ this->type = orig.type; // 이 경우 호출은 std::string::operator= 가 호출됨
// }
// *this = orig 경우는 클래스 전체 복사라 operator= 이 일어나고
// 멤버 하나 복사의 경우 해당 멤버의 operator= 가 일어남
// const 랑 reference 는 대입 불가능 const int x; int& ref; 같은 경우 -> 즉 생성할 떄 초기화 리스트 필수

Cat& Cat::operator=(const Cat &orig) // 이미 객체가 존재함
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (!(this == &orig))
	{
		delete _brain;
		this->_brain = new Brain(*orig._brain);		
	}
	return (*this); // 참조 반환
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
	// if ideas was heap : _brain 이 프리 담당 ex rules of three delete _brain->Brain destructor -> delete[] ideas
}


Brain* Cat::getBrain()
{
	return (this->_brain);
}
// 이건 외부 코드가 Brain 내부까지 만져서 좋은 함수는 아니라 하네.. 
// cat 이 Brain 을 가지고 있다는게 보여서 / 또 구현에 의존해서

std::string Cat::getIdea(int idx) const
{
	return _brain->getIdea(idx);
}

void Cat::setIdea(int idx, const std::string& input)
{
	_brain->setIdea(idx, input);
}

void Cat::makeSound() const
{
	std::cout << "MiAoUoUoUoUoUoUmIaOuYeAh" << std::endl;
}
