#ifndef CLAPPTRAP_HPP
# define CLAPPTRAP_HPP

#include <iostream>
#include <string.h>

class ClapTrap{
	public:
		ClapTrap();
		ClapTrap(const ClapTrap& obj);
		ClapTrap& operator=(const ClapTrap& obj);
		~ClapTrap();
		ClapTrap(const std::string name);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		std::string getName() const;
	private:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
};

#endif