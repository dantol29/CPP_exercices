#ifndef FLAGTRAP_HPP
# define FLAGTRAP_HPP

#include "ClapTrap.hpp"

class FlagTrap : ClapTrap{
	public:
		FlagTrap(std::string name);
		FlagTrap();
		FlagTrap(const FlagTrap& obj);
		~FlagTrap();
		void attack(const std::string& target);
		void highFivesGuys(void);
};

#endif