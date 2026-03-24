#include "Fixed.hpp"

Fixed::Fixed() : fixed_point(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int im_ci)
{
	// std::cout << "Int constructor called" << std::endl;
	this->fixed_point = im_ci << nb_fracbits;
}

Fixed::Fixed(const float im_cfloatpn)
{
	// std::cout << "Float constructor called" << std::endl;
	this->fixed_point = roundf(im_cfloatpn * (1 << nb_fracbits));
	// float 값을 가장 가까운 정수로 반올림 함
	// 소숫점 0.5 이상이면 절댓값이 커지는 방향으로 반올림
}

Fixed::Fixed(const Fixed &orig)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = orig;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &orig)
{
	// a = b; a.operator=(b); / this 는 왼쪽 객체 orig 는 오른쪽 객체
	// std::cout << "Copy assignment operator called" << std::endl;
	if (!(this == &orig)) // 같은 객체인지 확인, 주소 비교 / 자기 자신 대입하면 문제 생길 수 있음
		this->fixed_point = orig.fixed_point; 
	// 인트끼리 기본 대입 오퍼레이터 아님
	// 그러나 *this = orig; 같은 거 쓰면 오퍼레이터 호출이라 무한 재귀(타입..)
	return (*this);
	// *** 자기 자신 대입하면 문제 생기는 경우 : 
	// 기존 메모리 삭제 등의 경우 삭제된 메모리 접근 등.. 지우고 복사 구조에서 메모리 깨뜨릴 수 있음
}

// bool 리턴

bool Fixed::operator>(const Fixed &val) const
{
	// a.operator>(b)
	if ((this->fixed_point > val.fixed_point))
		return true;
	return false;
}

bool Fixed::operator<(const Fixed &val) const
{
	if ((this->fixed_point < val.fixed_point))
		return true;
	return false;
}

bool Fixed::operator>=(const Fixed &val) const
{
	if ((this->fixed_point >= val.fixed_point))
		return true;
	return false;
}

bool Fixed::operator<=(const Fixed &val) const
{
	if ((this->fixed_point <= val.fixed_point))
		return true;
	return false;
}

bool Fixed::operator==(const Fixed &val) const
{
	if ((this->fixed_point == val.fixed_point))
		return true;
	return false;
}

bool Fixed::operator!=(const Fixed &val) const
{
	if ((this->fixed_point != val.fixed_point))
		return true;
	return false;
}

// 새 객체를 만들어서 반환할 땐 값 반환으로..

Fixed Fixed::operator+(const Fixed &val) const
{
	Fixed newVal;
	newVal.fixed_point = (this->fixed_point + val.fixed_point);
	return (newVal);
}

Fixed Fixed::operator-(const Fixed &val) const
{
	Fixed newVal;
	newVal.fixed_point = (this->fixed_point - val.fixed_point);
	return (newVal);
}

Fixed Fixed::operator*(const Fixed &val) const
{
	Fixed newVal;
	// std::cout << "this->fixed point" << std::endl;
	// std::cout << this->fixed_point << std::endl;
	// std::cout << "val.fixed point" << std::endl;
	// std::cout << val.fixed_point << std::endl;
	long long int temp; // long long 으로 해도 되는데 걍.. 정수형으로 이용할거라구 표현 위함
	temp = (long long int)(this->fixed_point * val.fixed_point);
	newVal.fixed_point = (int)(temp >> nb_fracbits);
	return (newVal);
}

Fixed Fixed::operator/(const Fixed &val) const
{
	Fixed newVal;
	long long int temp;
	temp = (long long int)(this->fixed_point << nb_fracbits / val.fixed_point);
	newVal.fixed_point = (int)(temp);
	return (newVal);
}

// 자기 자신을 반환해야 할 경우 ref

Fixed& Fixed::operator++() // 전위 bit 연산용 값 올리기
{
	this->fixed_point++;
	return *this;
}

Fixed Fixed::operator++(int) // 후위 연산자 표시용으로 dummy parameter 라고 부름
{
	Fixed temp(*this);
	this->fixed_point++;
	return temp;
}

Fixed& Fixed::operator--()
{
	this->fixed_point--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	// *this 를 넣어야 copy constructor 가 Fixed
	// this 넣으면 Fixed* 
	// (현재 객체를 가리키는 포인터) Fixed* this; 컴파일러가 넣어주는 포인터, 멤버 함수를 호출한 객체의 주소
	// &this 를 넣으면 Fixed** 이기 때문에..
	this->fixed_point--;
	return temp;
}

float Fixed::toFloat(void) const
{
	return ((float)this->fixed_point / (1 << nb_fracbits));
}

int Fixed::toInt(void) const
{
	return (this->fixed_point >> nb_fracbits);
}

std::ostream &operator<<(std::ostream &o, const Fixed &fixed)
{
	o << fixed.toFloat();
	return (o);
}


Fixed& Fixed::min(Fixed &fixP1, Fixed &fixP2)
{
	// 피연산자가 Fixed 타입이면 
	// 컴파일러는 Fixed 용 오퍼레이터 먼저 찾고 있으면 그걸 사용
	// 없으면 에러 낸다 기존 int 비교법이 아닌 정의된 규칙을 찾는다
	// 오버로딩 헀다고 모든 상황에 내가 지정한 연산자를 쓰는 건 아니고
	// 형변환 연산자가 있을 경우 컴파일러가 변환해 내장 연산자를 쓸 수도 있다
	if (fixP1 < fixP2)
		return fixP1;
	return fixP2;
}

// static 들은 this 가 없으니까 xxx const xxx

const Fixed & Fixed::min(const Fixed& fixP1, const Fixed& fixP2)
{
	if (fixP1 < fixP2)
		return fixP1;
	return fixP2;
}

Fixed& Fixed::max(Fixed& fixP1, Fixed& fixP2)
{
	if (fixP1 > fixP2)
		return fixP1;
	return fixP2;
}

const Fixed& Fixed::max(const Fixed& fixP1, const Fixed& fixP2)
{
	if (fixP1 > fixP2)
		return fixP1;
	return fixP2;
}

