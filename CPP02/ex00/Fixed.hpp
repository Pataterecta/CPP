// ref keyword copy constructor : 복사 생성자

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <climits>

class Fixed {

	private:

	int fixed_point; //An integer to store the fixed-point number value.
	static const int nb_fracbits; //to store the number of fractional bits. of value integer literal 8.

	public:
	Fixed(); // should initializes the fixed-point nb value to 0
	~Fixed(); //destructor done
	Fixed& operator=(const Fixed& orig);// A copy assignment operator overload.
	Fixed(const Fixed& orig); // ?? A copy constructor.??
	int getRawBits(void)const;
	void setRawBits( int const raw );
};

// Fixed 는 고정 소수점(fixed-point) 을 구현하는 클래스
// 예 소수 3.33 을 float 으로 저장하는게 아니라 정수로 변환해서 저장

#endif