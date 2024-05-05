#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data* d = new Data;

	// serialized pointers are often used instead of raw memory addresses 
	// when you need to store information about memory locations
	std::cout << Serializer::serialize(d) << std::endl;

	// we serialize pointer and then deserialize to compare with the original pointer
	Data* d_new = Serializer::deserialize(Serializer::serialize(d));

	std::cout << d << ", " << d_new << std::endl;
	delete d;
}