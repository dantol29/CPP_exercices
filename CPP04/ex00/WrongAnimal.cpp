#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("unknown"){
	std::cout << "Default constructor called (WrongAnimal)" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj){
	std::cout << "Copy contructor called (WrongAnimal)" << std::endl;
	this->_type = obj._type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj){
	std::cout << "Assignment operator overload called" << std::endl;
	if (this != &obj)
		_type = obj._type;
	return (*this);
}

WrongAnimal::~WrongAnimal(){
	std::cout << "Destructor called (WrongAnimal)" << std::endl;
}

std::string WrongAnimal::getType() const{
	return (_type);
}

void WrongAnimal::makeSound() const{
	std::cout << "WrongAnimal sound..." << std::endl;
}