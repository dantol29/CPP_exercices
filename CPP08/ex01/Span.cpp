#include "Span.hpp"
#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <limits>

Span::Span()
{
}

Span::Span(const unsigned int n) :  _size(n)
{
}

Span::Span(const Span& obj) : _array(obj._array), _size(obj._size)
{
}

Span::~Span()
{
}

Span& Span::operator=(const Span& obj)
{
	if (this != &obj){
		_size = obj._size;
		_array = obj._array;
	}
	return (*this);
}

const std::vector<int>& Span::getArray() const
{
	return (_array);
}

void Span::addNumber(const unsigned int number)
{
	if (_array.size() + 1 > _size)
		throw std::runtime_error("No space left");
	_array.push_back(number);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	for (std::vector<int>::iterator it = begin; it != end; ++it)
		addNumber(*it);
}

unsigned int Span::longestSpan() const
{
	if (_array.size() < 2)
		throw std::runtime_error("Not enough numbers");

	int min = *std::min_element(_array.begin(), _array.end());
	int max = *std::max_element(_array.begin(), _array.end());
	return (max - min);
}

unsigned int Span::shortestSpan() const
{
	int min = std::numeric_limits<int>::max();
	int distance;
	
	if (_array.size() < 2)
		throw std::runtime_error("Not enough numbers");

	std::vector<int> sortedArray = _array;
	std::sort(sortedArray.begin(), sortedArray.end());

	for (unsigned int i = 1; i < _array.size(); ++i)
	{
		distance = std::abs(_array[i] - _array[i - 1]);
		if (distance < min)
			min = distance;
	}
	return (min);
}