#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
	public:
		Fixed();
		Fixed(const Fixed& obj);
		Fixed& operator=(const Fixed& obj);
		~Fixed();
		Fixed(int const num);
		Fixed(float const num);
		float toFloat(void) const;
		int toInt(void) const;
		int getRawBits(void) const;
		void setRawBits(int const raw);
	private:
		int _number;
		static const int _bits = 8;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif