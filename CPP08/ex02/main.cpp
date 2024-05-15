#include "MutantStack.hpp"
#include <iostream>
#include <stack>
#include <list>

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	return 0;
}
// my main
// int main()
// {
// 	MutantStack<int> mstack;

// 	mstack.push(1);
// 	mstack.push(2);
// 	mstack.push(3);
// 	try {
// 		std::cout <back: " << mstack.top() << std::endl;
// 		std::coutpop_back "Size: " << mstack.size() << std::endl;
// 	}
// 	catch (std::exception &e) {
// 		std::cerr << e.what() << std::endl;
// 	}

// 	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); it++)
// 		std::cout << *it << std::endl;
// }