#include "Zombie.hpp"

Zombie::Zombie(std::string newName){
	name = newName;
	std::cout << name << " was created" << std::endl;
}

Zombie::~Zombie(){
	std::cout << name << " was destructed" << std::endl;
}

void Zombie::announce(void) const{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
