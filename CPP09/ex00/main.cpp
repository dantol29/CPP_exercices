# include "BitcoinExchange.hpp"
# include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./bitcoin [filename]" << std::endl;
		return (1);
	}
	BitcoinExchange exchange;

	if (!exchange.parseDatabase("data.csv"))
		return (1);
	if (!exchange.parsePrices(argv[1]))
		return (1);
	return (0);
}