#include "Cat.hpp"

Brain* Cat::getBrain() const{
	return (_brain);
}

Cat::Cat() : Animal(){
	std::cout << "Default constructor called (Cat)" << std::endl;
	_type = "Cat";
	_brain = new Brain();
}

Cat::~Cat(){
	std::cout << "Destructor called (Cat)" << std::endl;
	delete _brain;
}

Cat::Cat(const Cat& obj){
	std::cout << "Copy constructor called (Cat)" << std::endl;
	this->_type = obj._type;
	this->_brain = new Brain(*obj._brain);
}

Cat& Cat::operator=(const Cat& obj){
	std::cout << "Assignment operator overload called (Cat)" << std::endl;
	if (this != &obj){
		this->_type = obj._type;
		this->_brain = new Brain(*obj._brain);
	}
	return (*this);
}

void Cat::makeSound() const{
	std::cout << "Meow! Meow! I am a cat!" << std::endl;
}
