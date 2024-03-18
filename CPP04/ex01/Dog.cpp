#include "Dog.hpp"

Dog::Dog() : Animal(){
	std::cout << "Default constructor called (Dog)" << std::endl;
	_type = "Dog";
}

Dog::~Dog(){
	std::cout << "Destructor called (Dog)" << std::endl;
}

Dog::Dog(const Dog& obj){
	std::cout << "Copy constructor called (Dog)" << std::endl;
	this->_type = obj._type;
}

Dog& Dog::operator=(const Dog& obj){
	std::cout << "Assignment operator overload called (Dog)" << std::endl;
	if (this != &obj)
		this->_type = obj._type;
	return (*this);
}

void Dog::makeSound() const{
	std::cout << "WUF! WUF! I am a dog!" << std::endl;
}