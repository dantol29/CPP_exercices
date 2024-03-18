#include "Animal.hpp"

Animal::Animal() : _type("unknown"){
	std::cout << "Default constructor called (Animal)" << std::endl;
}

Animal::Animal(const Animal& obj){
	std::cout << "Copy contructor called (Animal)" << std::endl;
	this->_type = obj._type;
}

Animal& Animal::operator=(const Animal& obj){
	std::cout << "Assignment operator overload called" << std::endl;
	if (this != &obj)
		_type = obj._type;
	return (*this);
}

Animal::~Animal(){
	std::cout << "Destructor called (Animal)" << std::endl;
}

std::string Animal::getType() const{
	return (_type);
}

void Animal::makeSound() const{
	std::cout << "Animal sound..." << std::endl;
}