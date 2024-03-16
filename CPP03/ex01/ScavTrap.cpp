#include "ScavTrap.hpp"

void ScavTrap::guardGate(){
	std::cout << "ScavTrap is in gate keeper mode" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
 
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "Name constructor called (ScavTrap)" << std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout << "Destructor called (ScavTrap)" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& obj) : ClapTrap(obj){
 
	_name = obj._name;
	_hitPoints = obj._hitPoints;
	_energyPoints = obj._energyPoints;
	_attackDamage = obj._attackDamage;
	std::cout << "Copy constructor called (ScavTrap)" << std::endl;
}

ScavTrap::ScavTrap() : ClapTrap(){
	_name = "unknown creature";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "Default constructor called (ScavTrap)" << std::endl;
}

void ScavTrap::attack(const std::string& target){
	if (this->_hitPoints == 0)
		std::cout << this->_name <<  ": I am dead!" << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << this->_name << ": No more energy Sir..." << std::endl;
	else{
		std::cout << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage (ScavTrap)" << std::endl;
	}
}