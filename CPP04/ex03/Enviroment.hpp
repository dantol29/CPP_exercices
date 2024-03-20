#ifndef ENVIROMENT_HPP
# define ENVIROMENT_HPP

#include "AMateria.hpp"
#include <iostream>

class Enviroment{
	private:
		static AMateria* trash[4];
	public:
		Enviroment();
		~Enviroment();
		Enviroment(const Enviroment& obj);
		Enviroment& operator=(const Enviroment& obj);
		static void addTrash(AMateria* obj);
		static void recycle();
};

#endif