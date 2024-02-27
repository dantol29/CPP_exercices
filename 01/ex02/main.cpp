#include <string>
#include <iostream>

int main()
{
	std::string test = "HI THIS IS BRAIN";
	std::string* testPTR = &test;
	std::string& testREF = test;

	std::cout << "The memory address of the string variable: " << &test << std::endl;
	std::cout << "The memory address held by stringPTR: " << testPTR << std::endl;
	std::cout << "The memory address held by stringREF: " << &testREF << std::endl;
	std::cout << "The value of the string variable: " << test << std::endl;
	std::cout << "The value pointed by stringPTR: " << *testPTR << std::endl;
	std::cout << "The value pointed by stringREF: " << testREF << std::endl;
}