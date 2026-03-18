// ref keyword copy constructor : 복사 생성자

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <climits>
#include <cmath>

class Fixed {

	private:

	int fixed_point; // 고정 소수점 //An integer to store the fixed-point number value.
	static const int nb_fracbits = 8; //to store the number of fractional bits. of value integer literal 8.

	public:
	Fixed();
	Fixed(const int im_ci);
	Fixed(const float im_floatpn); 
	// 부동 소수점 방식은 항상 오차가 존재한다는 단점이 존재한다. 이러한 단점이 존재하는 이유는 무엇일까?
	// ± M x 2ᴱ⁻¹²⁷ 공식을 사용하면 표현할 수 있는 범위는 늘지만, 10진수를 정확하게 표현할 수 없기 때문이다.
	Fixed(const Fixed& orig); // ?? A copy constructor.??
	Fixed& operator=(const Fixed& orig);// A copy assignment operator overload.
	// a = b 의 경우 a.operator+(b); 로 바뀜
	// a + b -> operator+(a, b), a << b -> operator<<(a, b)
	// + 같은 대칭 연산자는 한쪽에 종속되지 않게 만드는 게 더 자연스럽다고 함
	// 만약 std::cout << obj; 의 경우 왼쪽은 std::cout 오른쪽은 MyClass 라서 operator<<(std::cout, obj); 라서 외부 함수 정의 필요
	~Fixed(); //destructor done

	float toFloat(void)const;
	int toInt(void)const;
};
std::ostream & operator<<(std::ostream & o, const Fixed &fixed);

#endif

// 만약에 MyClass a; int x = 10; 경우 a + x; 는 int->MyClass 로 바꿔주면 가능 
/*
class MyClass {
Public: 
int value;
MyClass(int v) : value(v){} 변환 생성자
}
a.operator+(MyClass(x));
x.operator+(a); 는 불가..
외부 함수면 둘 다 됨..
*/
//x + a; 는 걍 안 됨