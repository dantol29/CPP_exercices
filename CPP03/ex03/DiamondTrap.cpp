#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name), FragTrap(name){
 
	this->_name = name;
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "Name constructor called (DiamondTrap)" << std::endl;
}

DiamondTrap::~DiamondTrap(){
	std::cout << "Destructor called (DiamondTrap)" << std::endl;
}

void DiamondTrap::whoAmI(){
	std::cout << "My name is " << this->_name << ", ClapTrap's name is " << ClapTrap::_name << std::endl;
}