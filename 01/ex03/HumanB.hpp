#include "Weapon.hpp"

class HumanB{
	public:
		void attack();
		void setWeapon(Weapon& newWeapon);
		HumanB(std::string newName);
	private:
		std::string name;
		Weapon* weapon;
};