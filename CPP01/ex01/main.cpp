#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main()
{
	Zombie* objs;
	objs = zombieHorde(3, "Smith");
	objs[0].announce();
	objs[1].announce();
	objs[2].announce();
	delete[] objs;
}