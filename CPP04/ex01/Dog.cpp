#include "Dog.hpp"

Brain* Dog::getBrain() const{
	return (_brain);
}

Dog::Dog() : Animal(){
	std::cout << "Default constructor called (Dog)" << std::endl;
	_type = "Dog";
	_brain = new Brain();
}

Dog::~Dog(){
	std::cout << "Destructor called (Dog)" << std::endl;
	delete _brain;
}

Dog::Dog(const Dog& obj){
	std::cout << "Copy constructor called (Dog)" << std::endl;
	this->_type = obj._type;
	this->_brain = new Brain(*obj._brain);
}

Dog& Dog::operator=(const Dog& obj){
	std::cout << "Assignment operator overload called (Dog)" << std::endl;
	if (this != &obj){
		this->_type = obj._type;
		delete _brain;
		this->_brain = new Brain(*obj._brain);
	}
	return (*this);
}

void Dog::makeSound() const{
	std::cout << "WUF! WUF! I am a dog!" << std::endl;
}