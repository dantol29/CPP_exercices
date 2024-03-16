#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed{
	public:
		Fixed();
		Fixed(const Fixed &obj);
		Fixed& operator=(const Fixed &obj);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
	private:
		int _number;
		static const int bits = 8;
};

#endif