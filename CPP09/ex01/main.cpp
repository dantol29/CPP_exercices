# include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./RPN [expression]" << std::endl;
		return (1);
	}

	RPN rpn;

	rpn.calculate(argv[1]);

	std::stack<int> result = rpn.getStack();

	for (size_t i = 0; i < result.size(); i++)
	{
		std::cout << result.top() << std::endl;
		result.pop();
	}
}