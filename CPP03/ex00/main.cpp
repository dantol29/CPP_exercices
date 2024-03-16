#include "ClapTrap.hpp"

int main(void){
	ClapTrap luke("Luke");
	ClapTrap unknown;

	unknown.takeDamage(5);
	luke.takeDamage(9);
	unknown.takeDamage(20);
	luke.attack(unknown.getName());
	luke.takeDamage(0);
	luke.beRepaired(1);
	luke.beRepaired(1);
	luke.beRepaired(1);
	luke.beRepaired(1);
	luke.beRepaired(1);
	luke.beRepaired(1);
	luke.beRepaired(1);
	luke.beRepaired(1);
	luke.beRepaired(1);
	luke.beRepaired(1);
	luke.beRepaired(1);
	luke.beRepaired(1);
	luke.beRepaired(1);
	unknown.takeDamage(20);
	unknown.takeDamage(20);
}