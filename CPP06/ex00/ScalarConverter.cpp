# include "ScalarConverter.hpp"

// implicit cast allowed only with promotion, Example float = int

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& obj)
{
}

ScalarConverter& ScalarConverter::operator==(const ScalarConverter& obj)
{
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(const std::string& element)
{
	//CHAR
	if (element.size() == 1)
	{
		char c = static_cast<char>(element[0]);
		std::cout << "Char: " << c << std::endl;
	}
	else
		std::cout << "Char:  non displayable" << std::endl;
	
	//INT
	if (element.size() == 1 && element[0] == '0')
		std::cout << "Int: 0" << std::endl;
	else
	{
		int number = std::atoi(element.c_str());
		if (number == 0)
			std::cout << "Int:  non displayable" << std::endl;
		else
			std::cout << "Int: " << number << std::endl;
	}

	//FLOAT
	//double
	return ;
}