#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <sstream>
# include <iostream>

class RPN
{
	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();
		std::stack<int> getStack() const;
		bool calculate(std::string str);
		bool handleOperation(char operation);
	private:
		std::stack<int> _stack;
};

#endif