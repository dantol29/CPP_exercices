#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FlagTrap.hpp"

int main(void){
	ClapTrap luke("Luke");
	ClapTrap unknown;
	ScavTrap bob("Bob");
	FlagTrap john("John");

	unknown.takeDamage(5);
	luke.takeDamage(9);
	luke.attack(unknown.getName());
	bob.attack(luke.getName());
	john.attack(luke.getName());
	john.highFivesGuys();
}