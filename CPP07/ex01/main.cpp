#include "iter.hpp"
#include <iostream>
#include <string>

void	multiply(int& a){
	a = a * 2;
}
void	addNo(std::string& str){
	str = str + "NO";
}

int	main(){
	int a[] = {1, 2, 3, 4, 5};
	iter(a, 5, multiply);
	for (int i = 0; i < 5; i++)
		std::cout << a[i] << std::endl;

	std::string b[] = {"hello", "goodbye"};
	iter(b, 2, addNo);
	for (int i = 0; i < 2; i++)
		std::cout << b[i] << std::endl;
}