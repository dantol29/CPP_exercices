#include "Cure.hpp"
#include "ICharacter.hpp"
Cure::Cure() : AMateria(){
	std::cout << "Default constructor called (Cure)" << std::endl;
	_type = "cure";
}

Cure::Cure(const Cure& obj){
	std::cout << "Copy constructor called (Cure)" << std::endl;
	_type = obj._type;
}

Cure& Cure::operator=(const Cure& obj){
	std::cout << "Assignment operator called (Cure)" << std::endl;
	if (this != &obj)
		this->_type = obj._type;
	return (*this);
}

Cure::~Cure(){
	std::cout << "Destructor called (Cure)" << std::endl;
}

AMateria* Cure::clone() const{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target){
	std::cout << "* shoots an cure bolt at " << target.getName() << " *" << std::endl;
}