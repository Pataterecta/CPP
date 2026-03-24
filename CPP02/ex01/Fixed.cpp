#include "Fixed.hpp"

Fixed::Fixed() : fixed_point(0)
{
	std::cout << "Default constructor called" << std::endl;
	// this->fixed_point = 0; 이건 대입이다 초기화 리스트가 권장이구, const 멤버 변수나 reference (&) 멤버는 무조건 이닛리스트
}

Fixed::Fixed(const int im_ci)
{
	std::cout << "Int constructor called" << std::endl;
	// it converts it to the corresponding fixed-point value
	this->fixed_point = im_ci << nb_fracbits; // n * 2의8승(256)
}

Fixed::Fixed(const float im_cfloatpn){
	std::cout << "Float constructor called" << std::endl;
	// It converts it to the corresponding fixed-point value.
	this->fixed_point = roundf(im_cfloatpn * (1 << nb_fracbits));
}
// float 에서 int 로 변환할 때 소수 처리 필요해서 roundf 로 반올림 해야함
// 결과를 반올림 하지 않으면 값 다 날아가유~~

Fixed::Fixed(const Fixed &orig)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = orig;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}


Fixed& Fixed::operator=(const Fixed &orig)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (!(this == &orig))
		this->fixed_point = orig.fixed_point;
	return (*this);
}
//An overload of the insertion («) operator that inserts a floating-point representation
// of the fixed-point number into the output stream object passed as a parameter.

float Fixed::toFloat(void)const // 함수는 변화 안시키구 리턴만이 플롯이다~ 아마 인트를 보구 플롯으로 바꾸겠지
{
	return ((float)this->fixed_point / (1 << nb_fracbits));
}
// that converts the fixed-point value to a floating-point value.
// 여기선 왜 roundf 가 아니냐면, 이미 fixed_point 는 정수이기 때문에 이걸 float 으로 바꾸는 건 그냥 스케일 복원
// 나누기 전에 하나를 플롯으로 바꿔주면 float 연산이 되니까 ㅋㅋ


int Fixed::toInt(void)const{

	return (this->fixed_point >> nb_fracbits);
}
//that converts the fixed-point value to an integer value.

std::ostream& operator<<(std::ostream & o, const Fixed &fixed) 
{
	// 고정 소수점 숫자를 실수 형태(float)로 바꿔서 출력 스트림에 넣는 연산자 만들기
	o << fixed.toFloat();
	return o;
}
//An overload of the insertion («) operator that inserts a floating-point representation
// of the fixed-point number into the output stream object passed as a parameter.
