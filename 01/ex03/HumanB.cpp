#include "HumanB.hpp"
#include <iostream>

void HumanB::attack(){
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& newWeapon){
	weapon = &newWeapon;
}

HumanB::HumanB(std::string newName){
	name = newName;
}