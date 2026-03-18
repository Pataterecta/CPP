#include "Fixed.hpp"

Fixed::Fixed() : fixed_point(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int im_ci)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixed_point = im_ci << nb_fracbits;
}

Fixed::Fixed(const float im_cfloatpn)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixed_point = roundf(im_cfloatpn * (1 << nb_fracbits));
}

Fixed::Fixed(const Fixed &orig)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = orig;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &orig)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (!(this == &orig))
		this->fixed_point = orig.fixed_point;
	return (*this);
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

Fixed &Fixed::min(int &fixP1, int &fixP2){

}
static min(const int &fixP1, const int &fixP2);
static max(int &fixP1, int &fixP2);
static max(const int &fixP1, int &fixP2);
