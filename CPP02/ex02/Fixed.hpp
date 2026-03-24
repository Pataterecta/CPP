#ifndef FIXED_HPP
# define FIXED_HPP

# include <climits>
# include <cmath>
# include <iostream>

class Fixed
{
  private:
	int fixed_point;
	static const int nb_fracbits = 8;

  public:
	Fixed();
	Fixed(const int im_ci);
	Fixed(const float im_floatpn);

	Fixed(const Fixed &orig);
	Fixed &operator=(const Fixed &orig);
	~Fixed();

	float toFloat(void) const;
	int toInt(void) const;

	bool operator>(const Fixed& val) const;
	bool operator<(const Fixed& val) const;
	bool operator>=(const Fixed& val) const;
	bool operator<=(const Fixed& val) const;
	bool operator==(const Fixed& val) const;
	bool operator!=(const Fixed& val) const;

	Fixed operator+(const Fixed& val) const; // 레퍼런스로 하면 지역 변수로 반환이니까.. 함수 끝나면 dangling ref
	Fixed operator-(const Fixed& val) const; // 새 객체를 만들어서 반환한다
	Fixed operator*(const Fixed& val) const;
	Fixed operator/(const Fixed& val) const;

	// Fixed operator/(const Fixed& val); 이렇게 썼다가 const 달아줌 
	// 새로운 객체 만들어내는거랑 기존 것들 this, val 안건드리니까.. 

	Fixed& operator++(); // 전위
	Fixed operator++(int); // 후위
	Fixed& operator--();
	Fixed operator-- (int);

	static Fixed& min(Fixed& fixP1, Fixed& fixP2);
	static const Fixed& min(const Fixed& fixP1, const Fixed& fixP2);
	static Fixed& max(Fixed &fixP1, Fixed &fixP2);
	static const Fixed& max(const Fixed& fixP1, const Fixed& fixP2);
};
std::ostream &operator<<(std::ostream &o, const Fixed &fixed);

#endif