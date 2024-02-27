#include "Weapon.hpp"
#include "HumanA.hpp"

int main()
{
	Weapon club = Weapon("crude spiked club");
	HumanA bob("BOB", club);
	bob.attack();
	club.setType("other type");
	bob.attack();
}