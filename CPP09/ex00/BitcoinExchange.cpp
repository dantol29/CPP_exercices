# include "BitcoinExchange.hpp"
# include <iostream>
# include <fstream>
# include <sstream>
# include <limits>
# include <cstdlib>

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	_database = other._database;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_database = other._database;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

int BitcoinExchange::stringToInt(std::string str) const
{
	int result;

	std::stringstream ss(str.c_str());
	ss >> result;
	if (ss.fail())
	{
		std::cerr << "Error: invalid integer format" << std::endl;
		return (-1);
	}
	return (result);
}

float BitcoinExchange::stringToFloat(std::string str) const
{
	float result;

	std::stringstream ss(str.c_str());
	ss >> result;
	if (ss.fail())
	{
		std::cerr << "Error: invalid float format" << std::endl;
		return (-1);
	}
	return (result);
}

std::string BitcoinExchange::trimString(std::string str) const
{
	unsigned int start = 0;
	unsigned int end = str.length() - 1;

	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			start = i;
			break;
		}
	}

	for (int i = str.length() - 1; i > 0; i--)
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			end = i;
			break;
		}
	}
	return (str.substr(start, end - start + 1));
}

// 2024-05-16 (YEAR-MONTH-DAY)
Date BitcoinExchange::isValidDate(std::string date) const
{
	Date dateStruct;
	Date error;

	error.year = 0;
	error.month = 0;
	error.day = 0;

	if (date.length() != 10)
		return (error);

	// YEAR
	dateStruct.year = stringToInt(date.substr(0, 4));
	if (dateStruct.year < 2008 || dateStruct.year > 2024)
	{
		std::cerr << "Error: invalid year value" << std::endl;
		return (error);
	}

	// -
	if (date[4] != '-')
		return (error);

	// MONTH
	dateStruct.month = stringToInt(date.substr(5, 2));
	if (dateStruct.month < 1 || dateStruct.month > 12)
	{
		std::cerr << "Error: invalid month value" << std::endl;
		return (error);
	}

	// -
	if (date[7] != '-')
		return (error);

	// DAY
	dateStruct.day = stringToInt(date.substr(8, 2));
	if (dateStruct.day < 1 || dateStruct.day > 31)
	{
		std::cerr << "Error: invalid day value" << std::endl;
		return (error);
	}
	return (dateStruct);
}

bool BitcoinExchange::isValidRate(std::string rate) const
{
	float rateFloat;

	rateFloat = stringToFloat(rate);
	if (rateFloat < 0)
	{
		std::cerr << "Error: invalid rate => " << rate << std::endl;
		return (false);
	}
	return (true);
}

bool BitcoinExchange::isValidValue(std::string rate) const
{
	float rateFloat;
	
	rateFloat = stringToFloat(rate);
	if (rateFloat < 0 || rateFloat > 1000)
	{
		std::cerr << "Error: invalid value => " << rate << std::endl;
		return (false);
	}
	return (true);
}

bool BitcoinExchange::isErrorDate(Date& date) const
{
	if (date.year == 0 || date.month == 0 || date.day == 0)
		return (true);
	return (false);
}

bool BitcoinExchange::printPrice(Date date, float price) const
{
	std::pair<Date, float> closest;
	size_t smallestDif = std::numeric_limits<size_t>::max();
	size_t difference;

	if (_database.size() < 1)
	{
		std::cerr << "Error: database is empty" << std::endl;
		return (false);
	}

	for (std::map<Date, float>::const_iterator it = _database.begin(); it != _database.end(); it++)
	{
		if (date == it->first)
		{
			std::cout << date.year << "-" << date.month << "-" << date.day << " => " << price << " = " << it->second * price << std::endl;
			return (true);
		}

		difference = abs(date.year - it->first.year) * 365 \
		+ abs(date.month - it->first.month) * 30 \
		+ abs(date.day - it->first.day);
		if (difference < smallestDif)
		{
			smallestDif = difference;
			closest = *it;
		}
	}

	if (smallestDif == std::numeric_limits<size_t>::max())
	{
		std::cerr << "Error: no closest date found" << std::endl;
		return (false);
	}

	std::cout << date.year << "-" << date.month << "-" << date.day << " => " << price << " = " << closest.second * price << std::endl;

	return (true);
}

bool BitcoinExchange::parseDatabase(std::string filename)
{
	std::ifstream file(filename.c_str());
	std::string line;
	
	if (!file.is_open())
	{
		std::cerr << "Error: cannot open database" << std::endl;
		return (false);
	}

	std::getline(file, line, '\n');

	if (line != "date,exchange_rate")
	{
		std::cerr << "Error: invalid header in the database: " << line << std::endl;
		return (false);
	}

	while (std::getline(file, line, '\n'))
	{
		Date date;
		std::string rate;
		size_t pos = line.find(',');

		if (pos == std::string::npos)
		{
			std::cerr << "Error: invalid line format in the database => " << line << std::endl;
			return (false);
		}

		date = isValidDate(trimString(line.substr(0, pos)));
		if (isErrorDate(date))
		{
			std::cerr << "Error: invalid date format in the database => " << trimString(line.substr(0, pos)) << std::endl;
			return (false);
		}

		rate = trimString(line.substr(pos + 1));

		if (!isValidRate(rate))
		{
			std::cerr << "Error: invalid rate format in the database => " << rate << std::endl;
			return (false);
		}
		_database.insert(std::make_pair(date, stringToFloat(rate)));
	}
	return (true);
}

// date | value
bool BitcoinExchange::parsePrices(std::string filename)
{
	std::string line;
	std::ifstream file(filename.c_str());

	if (!file.is_open())
	{
		std::cerr << "Error: cannot open database" << std::endl;
		return (false);
	}

	std::getline(file, line, '\n');

	if (line != "date | value")
	{
		std::cerr << "Error: invalid header in the database: " << line << std::endl;
		return (false);
	}

	while (std::getline(file, line, '\n'))
	{
		Date date;
		std::string value;
		size_t pos = line.find('|');

		if (pos == std::string::npos)
		{
			std::cerr << "Error: invalid line => " << line << std::endl;
			continue;
		}
		
		date = isValidDate(trimString(line.substr(0, pos)));
		if (isErrorDate(date))
		{
			std::cerr << "Error: invalid date => " << trimString(line.substr(0, pos)) << std::endl;
			continue;
		}

		value = trimString(line.substr(pos + 1));
		if (!isValidValue(value))
			continue;
		printPrice(date, stringToFloat(value));
	}
	return (true);
}