#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"


int main()
{
	//Animal b; 
	//Abstract classes cannot be instantiated directly; 
	//they can only be used as base classes for other classes. 
	//Any class that inherits from an abstract class
	//must provide implementations for all the pure virtual functions of the base class
	Animal* a = new Dog();
	Animal* c = new Cat();
	a->makeSound();
	c->makeSound();
	delete a;
	delete c;
	return 0;
}