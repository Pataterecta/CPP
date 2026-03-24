#include "Fixed.hpp"
#include <iostream>
int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
return 0;
}


/*
int main( void ) {
Fixed a;
Fixed b;
std::cout << "lets see: " << b << std::endl;
Fixed const c( Fixed( 5.05f ) * Fixed( 256 ) );
// roundf(1292.8) -> 1293
Fixed const d( Fixed(-0.8f) * Fixed(1));
// roundf(-0.8) -> -1
// -0.8 * 256 = -204.8 roudnf(-204.8) = -205 // 소숫점 0.5 이상이면 절댓값이 커지는 방향으로 반올림
// fixed_point = -205 (int)
// (float)-205 / 256 = -0.80078125 cout가 소수점 이하 6개만 남겨지니까 / 0 들어가면 다름 그래서 위랑 차이 
// cout 출력 -> -0.800781
// 내부 표현 int fixed_point
// 외부 표현 float (toFloat)
std::cout << c << std::endl;
std::cout << d << std::endl;

std::cout << "minus minus --" << std::endl;
std::cout << a-- << std::endl;
std::cout << a-- << std::endl;
std::cout << a-- << std::endl;
std::cout << a-- << std::endl;
std::cout << a-- << std::endl;
std::cout << a-- << std::endl;
std::cout << a << std::endl;
std::cout << "to show bit calcul a to --a and ++a to back" << std::endl;
std::cout << a << std::endl;
std::cout << --a << std::endl;
std::cout << ++a << std::endl;




std::cout << "max min" << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
std::cout << Fixed::max( a, d ) << std::endl;
std::cout << Fixed::min( a, d ) << std::endl;

std::cout << "bool" << std::endl;
std::cout << (a < b) << std::endl;
std::cout << (a > b) << std::endl;
std::cout << (a == b) << std::endl;
std::cout << (a <= b) << std::endl;
std::cout << (a >= b) << std::endl;
std::cout << (a < c) << std::endl;
std::cout << (a > c) << std::endl;
std::cout << (a != c) << std::endl;




return 0;
}
*/