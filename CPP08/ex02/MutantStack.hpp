#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <vector>
#include <deque>
#include <stack>

template <class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		typedef typename Container::iterator iterator;

		MutantStack();
		MutantStack(const MutantStack& obj);
		MutantStack& operator=(const MutantStack& obj);
		~MutantStack();

		iterator begin() { return (this->c.begin()); };
		iterator end() { return (this->c.end()); };
};

template <class T, class Container>
MutantStack<T, Container>::MutantStack()
{
}

template <class T, class Container>
MutantStack<T, Container>::MutantStack(const MutantStack& obj) : std::stack<T, Container>(obj)

{
}

template <class T, class Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack& obj)
{
	if (this != &obj)
		std::stack<T, Container>::operator=(obj);
	return (*this);
}

template <class T, class Container>
MutantStack<T, Container>::~MutantStack()
{
}



#endif
