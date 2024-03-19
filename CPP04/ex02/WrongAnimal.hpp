#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string.h>

class WrongAnimal{
	public:
		WrongAnimal();
		~WrongAnimal();
		WrongAnimal(const WrongAnimal& obj);
		WrongAnimal& operator=(const WrongAnimal& obj);
		std::string getType() const;
		void makeSound() const;
	protected:
		std::string _type;
};

#endif