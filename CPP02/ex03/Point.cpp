#include "Point.hpp"

Point::Point() : _x(0) , _y(0){
}

Point::~Point(){
}

Point::Point(const Point& obj) : _x(obj._x), _y(obj._y){
}

Point::Point(const float x, const float y) : _x(x), _y(y){	
}

Point& Point::operator=(const Point& obj){
	if (this != &obj)
	{
		(Fixed)this->_x = obj.getX();
		(Fixed)this->_y = obj.getY();
	}
	return (*this);
}

Fixed Point::getX() const{
	return (this->_x);
}

Fixed Point::getY() const{
	return (this->_y);
}