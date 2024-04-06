#include "Array.hpp"
#include <iostream>
int main(){
	Array<int> a(5);
	std::cout << "size: " << a.size() << std::endl;
	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << a[i] << std::endl;
	// std::cout << a[5] << std::endl; //exception (out of bounds)
	Array<char> b;
	std::cout << "size: " << b.size() << std::endl;
	for (unsigned int i = 0; i < b.size(); i++)
		std::cout << b[i] << std::endl;
}