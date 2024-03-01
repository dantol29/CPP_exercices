#include "Zombie.hpp"

Zombie::Zombie(){
	
}

Zombie::~Zombie(){
	std::cout << name << " was destructed" << std::endl;
}

void Zombie::setName(std::string newName){
	name = newName;
}

void Zombie::announce(void) const{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
