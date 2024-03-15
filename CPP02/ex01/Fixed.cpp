#include "Fixed.hpp"

Fixed::Fixed() : _number(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& obj) : _number(obj._number)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& obj)
{
	if (this != &obj)
	{
		std::cout << "Copy assignment constructor called" << std::endl;
		this->_number = obj._number;
	}
	return *this;
}

Fixed::Fixed(int const num)
{
	std::cout << "Int constructor called" << std::endl;
	this->_number = num * (1 << this->_bits);
}

Fixed::Fixed(float const num)
{
	std::cout << "Float constructor called" << std::endl;
	this->_number = roundf(num * (1 << this->_bits));
}

float Fixed::toFloat(void) const
{ 
	return (roundf(this->_number) / (1 << this->_bits));
}

int Fixed::toInt(void) const
{
	return (this->_number >> this->_bits);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_number = raw;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_number);
}

std::ostream& operator<<(std::ostream& out, const Fixed& obj)
{
	out << obj.toFloat();
	return (out);
}
