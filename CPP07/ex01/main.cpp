#include "iter.hpp"
#include <iostream>

void	multiply(int& a){
	a = a * 2;
}

int	main(){
	int a[] = {1, 2, 3, 4, 5};
	iter(a, 5, multiply);
	for (int i = 0; i < 5; i++)
		std::cout << a[i] << std::endl;

	int b[] = {'1', '2', '3', '4', '5'};
	iter(b, 5, multiply);
	for (int i = 0; i < 5; i++)
		std::cout << b[i] << std::endl;
}