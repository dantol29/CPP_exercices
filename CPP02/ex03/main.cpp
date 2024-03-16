#include "Point.hpp"

int main( void ) {
	Point a(7, 7);
	Point b(11, 1);
	Point c(2, 2);
	Point point_inside(7, 2);
	if (bsp(a, b, c, point_inside))
		std::cout << "point is inside of the trinagle" << std::endl;
	else
		std::cout << "point is not inside of the trinagle" << std::endl;
}