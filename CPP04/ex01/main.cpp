#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void brainCheck(){
	Dog d;
	Cat c;
	
	d.getBrain()->setIdea("Wuf");
	d.getBrain()->setIdea("You are my hero");
	std::cout << d.getBrain()->getIdea(0) << std::endl;
	std::cout << d.getBrain()->getIdea(1) << std::endl;
	std::cout << d.getBrain()->getIdea(2) << std::endl;
	c.getBrain()->setIdea("Meow");
	c.getBrain()->setIdea("I am your God");
	std::cout << c.getBrain()->getIdea(0) << std::endl;
	std::cout << c.getBrain()->getIdea(1) << std::endl;
	std::cout << c.getBrain()->getIdea(2) << std::endl;
	for (int i = 0; i < 100; i++)
		c.getBrain()->setIdea("I am just a cat... Meow");
}

void shallowTest(){
	// Copy constructor
	Dog basic;
	{
		// At the end of the scope Dog tmp will be deleted
		// If the copy is shallow tmp and basic share the same Brain
		// And the Brain will be deleted for both of them
		// shallow copy: this->_brain = obj._brain (they share the same memory address)
		// deep copy: this->_brain = new Brain(*obj._brain) (new Brain is allocated for deep copy)
		Dog tmp = basic;
	}
	// Assignment operator overload
	{
		// same deep copy, but before this->_brain = new Brain(*obj._brain)
		// we have to deallocate previous Brain, because it was allocated in the constructor
		Dog tmp;
		tmp = basic;
	}
}

int main()
{
	brainCheck();
	Animal* animals[4];
	animals[0] = new Dog();
	animals[1] = new Dog();
	animals[2] = new Cat();
	animals[3] = new Cat();
	animals[0]->makeSound();
	animals[3]->makeSound();
	for (int i = 0; i < 4; i++)
		delete animals[i];
	shallowTest();
	return 0;
}