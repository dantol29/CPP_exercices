#include "Array.hpp"
#include <iostream>
#include <string>

struct Test
{
	std::string str;
	int randomInt;
};


int main()
{
	std::cout << "my array\n" << std::endl;
	Array<int> a(5);
	for (unsigned int i = 0; i < 5; i++)
		std::cout << a[i] << std::endl;

	// trying to access index out of bounds
	try{
		std::cout << a[5] << std::endl; //exception (out of bounds)
	}
	catch(std::exception error){
		std::cout << "\nException caught: " << error.what() << std::endl;
	}
	
	std::cout << "\noriginal array\n" << std::endl;
	int *a_orig = new int[5];
	for (unsigned int i = 0; i < 5; i++)
		std::cout << a_orig[i] << std::endl;

	std::cout << "\nmy array default constructor\n" << std::endl;
	Array<int> c;
	std::cout << c[0] << std::endl;

	try{
		std::cout << c[1] << std::endl; //exception (out of bounds)
	}
	catch(std::exception error){
		std::cout << "\nException caught: " << error.what() << std::endl;
	}
	
	std::cout << "\noriginal array\n" << std::endl;
	int* i = new int();
	std::cout << i[0] << std::endl;


	std::cout << "\nmy array with complex data structure\n" << std::endl;
	Array<Test> d(5);
	for (unsigned int i = 0; i < 5; ++i){
		std::cout << d[i].str << std::endl;
		std::cout << d[i].randomInt << std::endl;
	}


	std::cout << "\noriginal array with complex data structure\n" << std::endl;
	Test* arr = new Test[5];

	for (unsigned int i = 0; i < 5; ++i){
		std::cout << arr[i].str << std::endl;
		std::cout << arr[i].randomInt << std::endl;
	}

	delete i;
	delete[] a_orig;
	delete[] arr;
}