#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal(){
	std::cout << "Default constructor called (WrongCat)" << std::endl;
	_type = "WrongCat";
}

WrongCat::~WrongCat(){
	std::cout << "Destructor called (WrongCat)" << std::endl;
}

WrongCat::WrongCat(const WrongCat& obj){
	std::cout << "Copy constructor called (WrongCat)" << std::endl;
	this->_type = obj._type;
}

WrongCat& WrongCat::operator=(const WrongCat& obj){
	std::cout << "Assignment operator overload called (WrongCat)" << std::endl;
	if (this != &obj)
		this->_type = obj._type;
	return (*this);
}

void WrongCat::makeSound() const{
	std::cout << "Meow! Meow! I am a WrongCat!" << std::endl;
}
