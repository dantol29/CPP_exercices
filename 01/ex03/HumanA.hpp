#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA{
	public:
		void attack();
		HumanA(std::string name, Weapon& obj);
	private:
		std::string name;
		Weapon& weapon;
};

#endif