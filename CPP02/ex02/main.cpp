#include <iostream>
#include "Fixed.hpp"

void comparison_operators()
{
	Fixed const b( 10 );
	Fixed const c( 10.1f );
	
	bool more = c > b;
	std::cout << "10.1 > 10 = "<< more << std::endl;
	more = b > c;
	std::cout << "10 > 10.1 = "<< more << std::endl;
	bool less = b < c;
	std::cout << "10 < 10.1 = "<< less << std::endl;
	less = c < b;
	std::cout << "10.1 < 10 = "<< less << std::endl;
	more = c >= b;
	std::cout << "10.1 >= 10 = "<< more << std::endl;
	more = b >= c;
	std::cout << "10 >= 10.1 = "<< more << std::endl;
	less = b <= c;
	std::cout << "10 <= 10.1 = "<< less << std::endl;
	less = c <= b;
	std::cout << "10.1 <= 10 = "<< less << std::endl;
	bool equal = b == b;
	std::cout << "10 == 10 = "<< equal << std::endl;
	equal = b == c;
	std::cout << "10 == 10.1 = "<< equal << std::endl;
	equal = b != c;
	std::cout << "10 != 10.1 = "<< equal << std::endl;
	equal = b != b;
	std::cout << "10 != 10 = "<< equal << std::endl;
}

void arithmetic_operators()
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 10.1f );

	a = b + c;
	std::cout << "10 + 10.1 = "<< a.toFloat() << std::endl;
	a = c - b;
	std::cout << "10.1 - 10 = "<< a.toFloat() << std::endl;
	a = c * b;
	std::cout << "10 * 10.1 = "<< a.toFloat() << std::endl;
	a = c / b;
	std::cout << "10 / 10.1 = "<< a.toFloat() << std::endl;
}

int main( void ) {
	//comparison_operators();
	//arithmetic_operators();
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