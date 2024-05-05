#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base* generate()
{
	std::srand(std::time(NULL));

	int randomNumber = std::rand() % 3;
	if (randomNumber == 0)
	{
		A* a = new A;
		std::cout << "A generated" << std::endl;
		return (dynamic_cast<Base*>(a));
	}
	if (randomNumber == 1)
	{
		B* b = new B;
		std::cout << "B generated" << std::endl;
		return (dynamic_cast<Base*>(b));
	}
	if (randomNumber == 2)
	{
		C* c = new C;
		std::cout << "C generated" << std::endl;
		return (dynamic_cast<Base*>(c));
	}
	return (NULL);
}

// invalid dynamic_cast returns NULL
void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

// invalid dynamic_cast throws an exception
void identify(Base& p)
{
	try {
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch(...){
		//std::cout << "Exception caught: A" << std::endl;
		try{
			B& b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "B" << std::endl;
		}
		catch(...){
			//std::cout << "Exception caught: B" << std::endl;
			try{
				C& c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "C" << std::endl;
			}
			catch(...){
				std::cout << "Exception caught: C" << std::endl;
			}
		}
	}
}

int main()
{
	// dynamic_cast is used convert polymorhpic types
	// from Derived -> Base (upcasting)
	// from Base -> Derived (downcasting)
	// !! is used during runtime, not compilation!
	Base* p = generate();
	identify(p);
	identify(*p);
	delete p;
}