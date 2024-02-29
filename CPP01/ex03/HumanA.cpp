#include "HumanA.hpp"
#include <iostream>

void HumanA::attack() const{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}

HumanA::HumanA(std::string newName, Weapon& obj): name(newName), weapon(obj){
}