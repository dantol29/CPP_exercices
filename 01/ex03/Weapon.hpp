#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon{
	public:
		const std::string& getType();
		void setType(std::string newType);
		Weapon(std::string name);
		Weapon();
	private:
		std::string type;
};

#endif