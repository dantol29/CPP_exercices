#include "Weapon.hpp"

class HumanB{
	public:
		void attack() const;
		void setWeapon(Weapon& newWeapon);
		HumanB(std::string newName);
	private:
		std::string name;
		Weapon* weapon;
};