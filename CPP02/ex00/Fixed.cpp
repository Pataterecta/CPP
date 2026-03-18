#include "Fixed.hpp"

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	this->fixed_point = 0;
 //A default constructor that initializes the fixed-point number value to 0.
}

Fixed::Fixed(const Fixed& orig){

	std::cout << "Copy constructor called" << std::endl;
	// this->fixed_point = orig.fixed_point; <<<<< *** 이건 대입 연산자 사용이 아님 : 멤버 직접 복사 // 같은 클래스니까 가능한 방식
	*this = orig; // 대입 연산자 재사용하는 방식
	// 는 this->operator=(other); 여전히 대입 연산자
	// this->fixed_point = orig.getRawBits(); 복사생성자에서 직접 복사하는 방식
// ?? A copy constructor.??
}

Fixed::~Fixed(){
 //done
 std::cout << "Destructor called" << std::endl;
}

const int Fixed::nb_fracbits = 8; // this is not a global just a syntax that init value on cpp cuz static its possible
// 왜 여기선 static이 안붙느냐? 
// static 은 이건 클래스 소속이다라는 것이고.hpp는 이런 static 멤버가 있다는 선언
// .cpp 는 변수의 실체를 만듦 

Fixed& Fixed::operator=(const Fixed& orig){
	std::cout << "Copy assignment operator called" << std::endl;
	if (!(this == &orig))
		this->fixed_point = orig.getRawBits(); // ne met pas const quand on call 안됨!!
	return (*this);
}
//Fixed& 반환 타입, Fixed:: 는 Fixed클래스의 멤버 함수 operator 는 함수 이름..
// A copy assignment operator overload.
// 참조형 반환 이유 -> a=b=c=d 무한 루프 안걸리도록

// int	check_minmax(int num)
// {
// 	if (num > INT_MAX)
// 	{
// 		std::cout << "overflow occured" << std::endl;
// 		return -1;
// 	}
// 	else if (num < INT_MIN)
// 	{
// 		std::cout << "underflow occured" <<std::endl;
// 		return -1;
// 	}
// 	else
// 		return (num);	
// }

int Fixed::getRawBits(void)const{
	//returns the raw value of the fixed-point value
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_point);
}

void Fixed::setRawBits( int const raw){
	this->fixed_point = raw;
}

// void Fixed::setRawBits( int const raw ){
// 	long long temp = (long long)raw * (1 << nb_fracbits);
// 	fixed_point = check_minmax(temp);
// 	//that sets the raw value of the fixed-point number.
// }
// i leave it cuz i want to memorize how i wasnt understanding the subject lol X(
