#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FlagTrap.hpp"

class DiamondTrap : public ScavTrap , public FragTrap{
	public:
		DiamondTrap(std::string name);
		~DiamondTrap();
		using ScavTrap::attack;
	private:
		std::string _name;
};

#endif