# include "ScalarConverter.hpp"

#include <cerrno>
// implicit cast allowed only with promotion, Example float = int

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& obj)
{
	*this = obj;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj)
{
	if (this != &obj)
		*this = obj;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

bool onlyNumbers(const std::string& element)
{
	for (unsigned int i = 0; i < element.length() - 1; ++i)
	{
		if (!(element[i] >= '0' && element[i] <= '9') && element[i] != '.')
			return (false);
	}
	return (true);
}
void ScalarConverter::convert(std::string& element)
{

	std::cout << std::fixed << std::setprecision(1);

	//CHAR
	int number = std::atoi(element.c_str());
	if (number > 0)
		std::cout << "Char: '" << static_cast<char>(number) << "'" << std::endl;
	else
		std::cout << "Char: non displayable" << std::endl;
	
	//INT
	if (number != 0 || (element.size() == 1 && element[0] == '0'))
		std::cout << "Int: " << number << std::endl;
	else
		std::cout << "Int: non displayable" << std::endl;

	if (!element.empty() && element.at(element.size() - 1) == 'f' && onlyNumbers(element))
		element.erase(element.size() - 1);

	//FLOAT
	char *end_f;
	std::strtof(element.c_str(), &end_f);
	float f = std::atof(element.c_str());
	if (errno == 0 && *end_f == '\0')
		std::cout << "Float: " << f << "f" << std::endl;
	else
		std::cout << "Float: non displayable" << std::endl;
	
	//DOUBLE
	char *end_d;
	double d = std::strtod(element.c_str(), &end_d);
	if (errno == 0 && *end_d == '\0')
		std::cout << "Double: " << d << std::endl;
	else
		std::cout << "Double: non displayable" << std::endl;
}