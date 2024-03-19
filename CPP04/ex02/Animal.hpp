#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string.h>

class Animal{
	public:
		//Base destructor is declared as virtual
		//the C++ knows that the object being deleted 
		//may be an instance of a derived class
		//Therefore, it calls the appropriate destructor based on the dynamic type of the object.
		//The destructor of the Derived class is called first
		//followed by the destructor of the Base class.
		// (If destructor is not virtual, it destroys only the Base class)
		// (It does not call the destructor of the Derived class and it may lead to the memory leaks)
		// (keyword virtual says C++ that we must call the destructor of Derived class first)
		Animal();
		virtual ~Animal();
		Animal(const Animal& obj);
		Animal& operator=(const Animal& obj);
		std::string getType() const;
		virtual void makeSound() const = 0; // this is pure virtual function and it makes the class abstract
	protected:
		std::string _type;
};

#endif