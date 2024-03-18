#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain{
	public:
		Brain();
		~Brain();
		Brain(const Brain& obj);
		Brain& operator=(const Brain& obj);
		std::string getIdea(int index) const;
		void setIdea();
	private:
		std::string ideas[100];
};

#endif