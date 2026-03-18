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

	Fixed& operator>(const Fixed& val);
	Fixed& operator<(const Fixed& val);
	Fixed& operator>=(const Fixed& val);
	Fixed& operator<=(const Fixed& val);
	Fixed& operator==(const Fixed& val);
	Fixed& operator!=(const Fixed& val);

	Fixed& operator+(const Fixed& val);
	Fixed& operator-(const Fixed& val);
	Fixed& operator*(const Fixed& val);
	Fixed& operator/(const Fixed& val);

	Fixed& operator++(); // 전위
	Fixed operator++(int); // 후위
	Fixed& operator--();
	Fixed operator-- (int);

	static Fixed& min(int &fixP1, int &fixP2);
	static Fixed& min(const int &fixP1, const int &fixP2);
	static Fixed& max(int &fixP1, int &fixP2);
	static Fixed& max(const int &fixP1, int &fixP2);
};
std::ostream &operator<<(std::ostream &o, const Fixed &fixed);

#endif