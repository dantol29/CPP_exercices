#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(){
	std::cout << "Default constructor called (AMateria)" << std::endl;
	_type = "AMateria";
}

AMateria::AMateria(const AMateria& obj){
	std::cout << "Copy constructor called (AMateria)" << std::endl;
	_type = obj._type;
}

AMateria& AMateria::operator=(const AMateria& obj){
	std::cout << "Assignment operator called (AMateria)" << std::endl;
	if (this != &obj)
		this->_type = obj._type;
	return (*this);
}

AMateria::~AMateria(){
	std::cout << "Destructor called (AMateria)" << std::endl;
}

AMateria::AMateria(std::string const& type){
	_type = type;
}

std::string const& AMateria::getType() const{
	return (_type);
}

void AMateria::use(ICharacter& target){
	std::cout << "* unknown material at " << target.getName() << " *" << std::endl;
}