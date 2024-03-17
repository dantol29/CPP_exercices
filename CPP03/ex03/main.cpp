#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void){
	DiamondTrap diamond("diamond");
	FragTrap john("John");
	
	john.highFivesGuys();
	diamond.attack(john.getName());
	diamond.whoAmI();
}