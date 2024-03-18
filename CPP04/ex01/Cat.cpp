#include "Cat.hpp"

Cat::Cat() : Animal(){
	std::cout << "Default constructor called (Cat)" << std::endl;
	_type = "Cat";
}

Cat::~Cat(){
	std::cout << "Destructor called (Cat)" << std::endl;
}

Cat::Cat(const Cat& obj){
	std::cout << "Copy constructor called (Cat)" << std::endl;
	this->_type = obj._type;
}

Cat& Cat::operator=(const Cat& obj){
	std::cout << "Assignment operator overload called (Cat)" << std::endl;
	if (this != &obj)
		this->_type = obj._type;
	return (*this);
}

void Cat::makeSound() const{
	std::cout << "Meow! Meow! I am a cat!" << std::endl;
}
