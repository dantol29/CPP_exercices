#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void){
	ClapTrap luke("Luke");
	ClapTrap unknown;
	ScavTrap bob("Bob");
	FragTrap john("John");

	unknown.takeDamage(5);
	luke.takeDamage(9);
	luke.attack(unknown.getName());
	bob.attack(luke.getName());
	john.attack(luke.getName());
	john.highFivesGuys();
}