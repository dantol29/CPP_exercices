#include "Span.hpp"
#include <stdexcept>
#include <cstdlib>
#include <iostream>

Span::Span(){

}

Span::Span(const unsigned int n) :  _size(n){

}

Span::Span(const Span& obj) : _array(obj._array), _size(obj._size){
}

Span::~Span(){

}

Span& Span::operator=(const Span& obj){
	if (this != &obj){
		_size = obj._size;
		_array = obj._array;
	}
	return (*this);
}

const std::vector<int>& Span::getArray() const{
	return (_array);
}

void Span::addNumber(const unsigned int number){
	try {
		if (_array.size() + 1 > _size)
			throw std::runtime_error("No space left");
	}
	catch (std::runtime_error& e){
		std::cout << "Exception caught: "<< e.what() << std::endl;
	}
	_array.push_back(number);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end){
	for (std::vector<int>::iterator it = begin; it != end; ++it){
		addNumber(*it);
	}
}

unsigned int Span::longestSpan() const{
	unsigned int max = 0;
	unsigned int distance;
	
	try {
		if (_array.size() < 2)
			throw std::runtime_error("Not enough numbers");
	}
	catch (std::runtime_error& e){
		std::cout << "Exception caught: "<< e.what() << std::endl;
	}
	for (unsigned int i = 1; i < _array.size(); ++i){
		distance = std::abs(_array[i] - _array[i - 1]);
		if (distance > max)
			max = distance;
	}
	return (max);
}

unsigned int Span::shortestSpan() const{
	unsigned int min;
	unsigned int distance;
	
	try {
		if (_array.size() < 2)
			throw std::runtime_error("Not enough numbers");
	}
	catch (std::runtime_error& e){
		std::cout << "Exception caught: "<< e.what() << std::endl;
	}
	for (unsigned int i = 1; i < _array.size(); ++i){
		distance = std::abs(_array[i] - _array[i - 1]);
		if (i == 1)
			min = distance;
		else if (distance < min)
			min = distance;
	}
	return (min);
}