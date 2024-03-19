#include "Brain.hpp"

std::string Brain::getIdea(const int index) const{
	if (!_ideas[index].empty())
		return (_ideas[index]);
	std::cout << "Idea " << index << " does not exist" << std::endl;
	return ("Error");
}

void Brain::setIdea(std::string idea){
	int i = 0;
	while (!_ideas[i].empty() && i < 100)
		i++;
	if (i == 100)
		std::cout << "Brain does not have any space left" << std::endl;
	else
		_ideas[i] = idea;
}

Brain::Brain(){
	std::cout << "Default constructor called (Brain)" << std::endl;
}

Brain::Brain(const Brain& obj){
	std::cout << "Copy contructor called (Brain)" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = obj._ideas[i];
}

Brain& Brain::operator=(const Brain& obj){
	std::cout << "Assignment operator overload called" << std::endl;
	if (this != &obj){
		for (int i = 0; i < 100; i++)
			_ideas[i] = obj._ideas[i];
	}
	return (*this);
}

Brain::~Brain(){
	std::cout << "Destructor called (Brain)" << std::endl;
}
