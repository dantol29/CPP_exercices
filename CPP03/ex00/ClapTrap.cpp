#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("unknown creature"), _hitPoints(10), _energyPoints(10), _attackDamage(10){
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj) : _name(obj._name), _hitPoints(obj._hitPoints), _energyPoints(obj._energyPoints), _attackDamage(obj._attackDamage){
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj){
	if (this != &obj){
		_name = obj._name;
		_hitPoints = obj._hitPoints;
		_attackDamage = obj._attackDamage;
		_energyPoints = obj._energyPoints;
	}
	return (*this);
}

ClapTrap::~ClapTrap(){
	std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(10){
	std::cout << "Name constructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target){
	if (this->_hitPoints == 0)
		std::cout << this->_name <<  ": I am dead!" << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << this->_name << ": No more energy Sir..." << std::endl;
	else{
		std::cout << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount){
	if (this->_hitPoints == 0)
		std::cout << this->_name <<  ": I am dead!" << std::endl;
	else if (amount == 0)
		std::cout << this->_name << ": Pathetic hit... I am disappointed" << std::endl;
	else{
		if (this->_hitPoints <= amount){
			std::cout << "R.I.P " << this->_name << " received " << amount << " damage and died" << std::endl;
			this->_hitPoints = 0;
		}
		else{
			std::cout <<  this->_name << " received " << amount << " damage" << std::endl;
			this->_hitPoints -= amount;
		}
		this->_energyPoints -= 1;
	}
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->_hitPoints == 0)
		std::cout << this->_name <<  ": I am dead!" << std::endl;
	else if (amount == 0)
		std::cout << "Repair amount must be at least 1" << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << this->_name << ": No more energy Sir..." << std::endl;
	else if (this->_hitPoints + amount > 10)
		std::cout << "You can't have more than 10 hit points" << std::endl;
	else{
		this->_energyPoints -= 1;
		this->_hitPoints += amount;
		std::cout << this->_name << " increased hit points by " << amount << std::endl;
	}
}

std::string ClapTrap::getName() const{
	return (this->_name);
}