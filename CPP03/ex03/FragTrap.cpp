#include "FragTrap.hpp"

void FragTrap::highFivesGuys(void){
	std::cout << "High Five!!!!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
 
	_name = name;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "Name constructor called (FragTrap)" << std::endl;
}

FragTrap::~FragTrap(){
	std::cout << "Destructor called (FragTrap)" << std::endl;
}

FragTrap::FragTrap(const FragTrap& obj) : ClapTrap(obj){
 
	_name = obj._name;
	_hitPoints = obj._hitPoints;
	_energyPoints = obj._energyPoints;
	_attackDamage = obj._attackDamage;
	std::cout << "Copy constructor called (FragTrap)" << std::endl;
}

FragTrap::FragTrap() : ClapTrap(){
	_name = "unknown creature";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "Default constructor called (FragTrap)" << std::endl;
}

void FragTrap::attack(const std::string& target){
	if (this->_hitPoints == 0)
		std::cout << this->_name <<  ": I am dead!" << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << this->_name << ": No more energy Sir..." << std::endl;
	else{
		std::cout << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage (FragTrap)" << std::endl;
	}
}