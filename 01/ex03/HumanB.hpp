#include "Weapon.hpp"

class HumanB{
	public:
		void attack();
		HumanB(std::string newName);
	private:
		std::string name;
		Weapon weapon;
};