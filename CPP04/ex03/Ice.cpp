#include "Ice.hpp"
#include "ICharacter.hpp"
Ice::Ice() : AMateria(){
	std::cout << "Default constructor called (Ice)" << std::endl;
	_type = "ice";
}

Ice::Ice(const Ice& obj){
	std::cout << "Copy constructor called (Ice)" << std::endl;
	_type = obj._type;
}

Ice& Ice::operator=(const Ice& obj){
	std::cout << "Assignment operator called (Ice)" << std::endl;
	if (this != &obj)
		this->_type = obj._type;
	return (*this);
}

Ice::~Ice(){
	std::cout << "Destructor called (Ice)" << std::endl;
}

AMateria* Ice::clone() const{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target){
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}