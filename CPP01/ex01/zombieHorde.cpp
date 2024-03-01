#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ){
	Zombie* objs = new Zombie[N];

	for (int i = 0; i < N; ++i)
        objs[i].setName(name);
	return (objs);
}