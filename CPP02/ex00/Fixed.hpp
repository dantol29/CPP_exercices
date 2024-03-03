#include <iostream>

class Fixed{
	public:
		Fixed();
		Fixed(const Fixed &obj);
		Fixed& operator=(const Fixed &obj);
	private:
		int _number;
		static const int bits = 8;
};