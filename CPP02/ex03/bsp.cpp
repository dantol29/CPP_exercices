#include "Point.hpp"

double triangleArea(const Point& a, const Point& b, const Point& c) {
	Fixed first = (b.getX() - a.getX()) * (c.getY() - a.getY());
	Fixed second = (c.getX() - a.getX()) * (b.getY() - a.getY());
	Fixed result = first - second;
	if (result < 0)
		return (0.5 * -result.toFloat());
	return (0.5 * result.toFloat()); 
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	double totalArea = triangleArea(a, b, c);
	double areaPBC = triangleArea(point, b, c);
	double areaPAC = triangleArea(a, point, c);
	double areaPAB = triangleArea(a, b, point);
	double epsilon = 1e-6;
	if (totalArea - (areaPBC + areaPAC + areaPAB) < epsilon)
		return (true);
	return (false);
}
