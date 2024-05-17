# include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./PmergeMe \"number1 number2 number3 ...\"" << std::endl;
		return (1);
	}

	PmergeMe p;
	if (!p.sortWithVector(argv[1]))
		return (1);
	if (!p.sortWithList(argv[1]))
		return (1);
	
	std::vector<int> unsorted = p.getUnsorted();
	std::vector<int> sorted = p.getSorted();

	std::cout << "Before: ";
	for (std::vector<int>::const_iterator it = unsorted.begin(); it != unsorted.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "After: ";
	for (std::vector<int>::const_iterator it = sorted.begin(); it != sorted.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << unsorted.size() << " elements with vector: ";
	p.printTime(p.getVectorTime());

	std::cout << "Time to process a range of " << unsorted.size() << " elements with list  : ";
	p.printTime(p.getListTime());
	return (0);
}