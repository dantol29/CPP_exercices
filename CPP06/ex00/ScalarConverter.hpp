# ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include <cstdlib>
# include <iomanip>

class ScalarConverter
{
	public:
		static void convert(std::string& element);
	private:
		~ScalarConverter();
		ScalarConverter();
		ScalarConverter(const ScalarConverter& obj);
		ScalarConverter& operator=(const ScalarConverter& obj);
};

# endif