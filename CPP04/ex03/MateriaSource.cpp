#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
	std::cout << "Default constructor called (MateriaSource)" << std::endl;
	for (int i = 0; i < 4; i++)
		materials[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& obj){
	std::cout << "Copy constructor called (MateriaSource)" << std::endl;
	for (int i = 0; i < 4; i++){
		if (materials[i])
			delete materials[i];
		materials[i] = obj.materials[i]->clone();
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& obj){
	std::cout << "Assignment operator called (MateriaSource)" << std::endl;
	if (this != &obj){
		for (int i = 0; i < 4; i++){
			if (materials[i])
				delete materials[i];
			materials[i] = obj.materials[i]->clone();
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource(){
	std::cout << "Destructor called (MateriaSource)" << std::endl;
	for (int i = 0; i < 4; i++){
		if (materials[i])
			delete materials[i];
	}
}

void MateriaSource::learnMateria(AMateria* obj){
	int i = 0;
	while (i < 4 && materials[i])
		i++;
	if (i < 4 && materials[i] == NULL){
		materials[i] = obj;
		std::cout << obj->getType() << " added to the materials" << std::endl;
	}
	else
		std::cout << "No more space for materials!" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type){
	int i = 0;
	while (i < 4 && materials[i]){
		if (materials[i]->getType() == type)
			return (materials[i]->clone());
		i++;
	}
	return (0);
}