#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain{
	public:
		Brain();
		~Brain();
		Brain(const Brain& obj);
		Brain& operator=(const Brain& obj);
		std::string getIdea(const int index) const;
		void setIdea(std::string idea);
	private:
		std::string _ideas[100];
};

#endif