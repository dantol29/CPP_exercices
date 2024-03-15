#include "Fixed.hpp"

Fixed::Fixed() : _number(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj){
	std::cout << "Copy constructor called" << std::endl;
	this->_number = obj.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &obj){
	if (this != &obj)
	{
		std::cout << "Copy assignment operator called" << std::endl;
		this->_number = obj.getRawBits();
	}
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_number);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_number = raw;
}