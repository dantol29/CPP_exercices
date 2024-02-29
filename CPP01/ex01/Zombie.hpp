#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie{
	public:
		void announce(void) const;
		Zombie(std::string newName);
		Zombie();
		~Zombie();
	private:
		std::string name;
};

#endif