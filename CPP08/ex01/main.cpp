#include "Span.hpp"
#include "iostream"
#include <numeric>

void aLotOfNumbers()
{
	Span sp = Span(10000);

	std::vector<int> numbersToAdd(10000, 1);
	sp.addNumber(numbersToAdd.begin(), numbersToAdd.end());
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	// std::vector<int> newArray = sp.getArray();
	// std::vector<int>::iterator it;

	// for (it = newArray.begin(); it != newArray.end(); ++it)
	// 	std::cout << *it << std::endl;
}

int main()
{
	try {
		Span sp = Span(5);
		//std::cout << sp.longestSpan() << std::endl; // exception
		sp.addNumber(6); // 1
		sp.addNumber(3); // 2
		sp.addNumber(17); // 3
		sp.addNumber(9); // 4
		sp.addNumber(11); // 5
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		sp.addNumber(11); // 6 - exception
	}
	catch (std::runtime_error& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	aLotOfNumbers();
	return 0;
}
