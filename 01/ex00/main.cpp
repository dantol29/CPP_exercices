#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main()
{
	Zombie* obj;

	randomChump("Joey!");
	obj = newZombie("Finn!");
	obj->announce();
	delete obj;
}