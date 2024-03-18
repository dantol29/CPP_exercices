#include "Brain.hpp"

std::string Brain::getIdea(int index) const{

}

void Brain::setIdea(){
	
}

Brain::Brain(){
	std::cout << "Default constructor called (Brain)" << std::endl;
}

Brain::Brain(const Brain& obj){
	std::cout << "Copy contructor called (Brain)" << std::endl;
}

Brain& Brain::operator=(const Brain& obj){
	std::cout << "Assignment operator overload called" << std::endl;
	return (*this);
}

Brain::~Brain(){
	std::cout << "Destructor called (Brain)" << std::endl;
}
