#include "Enviroment.hpp"

AMateria* Enviroment::trash[4] = {NULL};

Enviroment::Enviroment(){
	std::cout << "Default constructor called (Enviroment)" << std::endl;
	for (int i = 0; i < 4; i++)
		trash[i] = NULL;
}

Enviroment::Enviroment(const Enviroment& obj){
	std::cout << "Copy constructor called (Enviroment)" << std::endl;
	for (int i = 0; i < 4; i++){
		if (trash[i])
			delete trash[i];
		trash[i] = obj.trash[i]->clone();
	}
}

Enviroment& Enviroment::operator=(const Enviroment& obj){
	std::cout << "Assignment operator called (Enviroment)" << std::endl;
	if (this != &obj){
		for (int i = 0; i < 4; i++){
			if (trash[i])
				delete trash[i];
			trash[i] = obj.trash[i]->clone();
		}
	}
	return (*this);
}

Enviroment::~Enviroment(){
	std::cout << "Destructor called (Enviroment)" << std::endl;
	for (int i = 0; i < 4; i++){
		if (trash[i])
			delete trash[i];
	}
}

void Enviroment::recycle(){
	for (int i = 0; i < 4; i++){
		if (trash[i]){
			delete trash[i];
			trash[i] = NULL;
		}
	}
}

void Enviroment::addTrash(AMateria* obj){
	int i = 0;
	while (i < 4 && trash[i])
		i++;
	if (i < 4 && trash[i] == NULL)
		trash[i] = obj;
	else
		Enviroment::recycle();
}