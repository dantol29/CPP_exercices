#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie{
	public:
		void announce(void);
		Zombie(std::string newName);
		~Zombie();
	private:
		std::string name;
};

#endif