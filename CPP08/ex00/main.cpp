#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <map>

int main(){
	std::list<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	std::cout << easyfind(a, 3) << std::endl;
	std::cout << easyfind(a, 4) << std::endl;

	std::vector<int> b;
	b.push_back(1);
	b.push_back(2);
	b.push_back(3);
	std::cout << easyfind(b, 3) << std::endl;
	std::cout << easyfind(b, 4) << std::endl;
}