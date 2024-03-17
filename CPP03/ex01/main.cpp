#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void){
	ClapTrap luke("Luke");
	ClapTrap unknown;
	ScavTrap bob("Bob");

	unknown.takeDamage(5);
	luke.takeDamage(9);
	luke.attack(unknown.getName());
	bob.attack(luke.getName());
	bob.beRepaired(1);
}