#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string.h>

class Animal{
	public:
		Animal();
		virtual ~Animal();
		Animal(const Animal& obj);
		Animal& operator=(const Animal& obj);
		std::string getType() const;
		virtual void makeSound() const;
	protected:
		std::string _type;
};

#endif