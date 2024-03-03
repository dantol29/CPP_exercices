#include "Fixed.hpp"

Fixed::Fixed() : _number(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj){
	std::cout << "Copy constructor called" << std::endl;
	_number = obj._number;
}

Fixed& Fixed::operator=(const Fixed &obj){
	if (this != &obj)
	{
		std::cout << "Copy assignment operator called" << std::endl;
		_number = obj._number;
	}
	return *this;
}