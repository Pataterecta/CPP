#include "Fixed.hpp"
#include <iostream>
int main( void ) {

// std::cout << "*this ex00 is only to learn grammar so it doesnt rlly make proper value but only assignment operator..*" << std::endl;
Fixed a;
Fixed b( a ); // 이 순간 복사 생성자가 호출됨 복사 생성자 안에서 *this = other; 
// *this 는 지금 생성중인 b, other = a 실제 의미는 b.operator=(a);
Fixed c;
c = b;
std::cout << a.getRawBits() << std::endl;
std::cout << b.getRawBits() << std::endl;
std::cout << c.getRawBits() << std::endl;
return 0;
}