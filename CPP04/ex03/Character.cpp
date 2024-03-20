#include "Character.hpp"
#include "Enviroment.hpp"

Character::Character(){
	std::cout << "Default constructor called (Character)" << std::endl;
	_name = "unknown";
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(const Character& obj){
	std::cout << "Copy constructor called (Character)" << std::endl;
	_name = obj._name;
	for (int i = 0; i < 4; i++){
		if (inventory[i])
			delete inventory[i];
		inventory[i] = obj.inventory[i]->clone();
	}
}

Character& Character::operator=(const Character& obj){
	std::cout << "Assignment operator called (Character)" << std::endl;
	if (this != &obj){
		_name = obj._name;
		for (int i = 0; i < 4; i++){
			if (inventory[i])
				delete inventory[i];
			inventory[i] = obj.inventory[i]->clone();
		}
	}
	return (*this);
}

Character::~Character(){
	std::cout << "Destructor called (Character)" << std::endl;
	for (int i = 0; i < 4; i++){
		if (inventory[i]){
			delete inventory[i];
		}
	}
	Enviroment::recycle();
}

Character::Character(std::string const name){
	std::cout << "Name constructor called (Character)" << std::endl;
	_name = name;
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

std::string const& Character::getName() const{
	return (_name);
}

void Character::equip(AMateria* m){
	int i = 0;
	while (i < 4 && inventory[i])
		i++;
	if (i < 4 && inventory[i] == NULL){
		inventory[i] = m;
		std::cout << m->getType() << " added to the inventory" << std::endl;
	}
	else
		std::cout << "Your inventory is full!" << std::endl;
}

void Character::unequip(int idx){
	if (idx < 4){
		if (inventory[idx]){
			Enviroment::addTrash(inventory[idx]);
			inventory[idx] = NULL;			
			return ;
		}			
	}
	std::cout << "Material does not exist" << std::endl;
}

void Character::use(int idx, ICharacter& target){
	if (idx < 4){
		if (inventory[idx]){
			inventory[idx]->use(target);	
			return ;
		}			
	}
	std::cout << "Material does not exist" << std::endl;
}