#include "Fixed.hpp"

Fixed::Fixed() : _number(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& obj) : _number(obj._number)
{
	// std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& obj)
{
	if (this != &obj)
	{
		// std::cout << "Copy assignment constructor called" << std::endl;
		this->_number = obj._number;
	}
	return *this;
}

Fixed::Fixed(int const num)
{
	this->_number = num * (1 << this->_bits);
}

Fixed::Fixed(float const num)
{
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
	_number = raw;
}

int Fixed::getRawBits() const
{
	return (_number);
}

// Comparison operators

bool Fixed::operator>(const Fixed& obj) const
{
	return (this->_number > obj.getRawBits());
}

bool Fixed::operator<(const Fixed& obj) const
{
	return (this->_number < obj.getRawBits());
}

bool Fixed::operator>=(const Fixed& obj) const
{
	return (this->_number >= obj.getRawBits());
}

bool Fixed::operator<=(const Fixed& obj) const
{
	return (this->_number <= obj.getRawBits());
}

bool Fixed::operator==(const Fixed& obj) const
{
	return (this->_number == obj.getRawBits());
}

bool Fixed::operator!=(const Fixed& obj) const
{
	return (this->_number != obj.getRawBits());
}

// Arithmetic operators

Fixed Fixed::operator+(const Fixed& obj) const
{
	return (Fixed(this->toFloat() + obj.toFloat()));
}

Fixed Fixed::operator-(const Fixed& obj) const
{
	return (Fixed(this->toFloat() - obj.toFloat()));
}

Fixed Fixed::operator*(const Fixed& obj) const
{
	return (Fixed(this->toFloat() * obj.toFloat()));
}

Fixed Fixed::operator/(const Fixed& obj) const
{
	return (Fixed(this->toFloat() / obj.toFloat()));
}

// Increment/decrement

Fixed& Fixed::operator++(void)
{
	this->_number += 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->_number += 1;
	return (tmp);
}

Fixed& Fixed::operator--(void)
{
	this->_number -= 1;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->_number -= 1;
	return (tmp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return ((a < b) ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return ((a > b) ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return ((a > b) ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return ((a > b) ? a : b);
}

std::ostream& operator<<(std::ostream& out, const Fixed& obj)
{
	out << obj.toFloat();
	return (out);
}
