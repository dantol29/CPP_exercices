# include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &other)
{
	_stack = other._stack;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		_stack = other._stack;
	return (*this);
}

RPN::~RPN()
{
}

std::stack<int> RPN::getStack() const
{
	return (_stack);
}

bool RPN::handleOperation(char operation)
{
	int a;
	int b;

	if (_stack.size() < 2)
		return (std::cerr << "Not enough operands" << std::endl, false);

	a = _stack.top();
	_stack.pop();
	b = _stack.top();
	_stack.pop();

	switch (operation)
	{
		case '+':
			_stack.push(b + a);
			break;
		case '-':
			_stack.push(b - a);
			break;
		case '*':
			_stack.push(b * a);
			break;
		case '/':
			if (a == 0)
				return (std::cerr << "Division by zero" << std::endl, false);
			_stack.push(b / a);
			break;
		default:
			std::cerr << "Invalid operation: " << operation << std::endl;
			return (false);
	}
	return (true);
}

bool RPN::calculate(std::string str)
{
	int number;

	for (unsigned int i = 0; i < str.length(); ++i)
	{
		// skip whitespaces
		while (i < str.length() && str[i] == ' ')
			i++;
		if (i == str.length())
			break;

		number = str[i];
		if (number >= '0' && number <= '9')
			_stack.push(number - '0');
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
		{
			if (!handleOperation(str[i]))
				return (false);
		}
		else
			return (std::cerr << "Invalid character: " << str[i] << std::endl, false);
	}
	return (true);
}