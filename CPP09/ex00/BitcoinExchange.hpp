#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

struct Date
{
	int year;
	int month;
	int day;

	bool operator==(const Date &other) const
	{
		if (year == other.year && month == other.month && day == other.day)
			return true;
		return false;
	}
	bool operator<(const Date &other) const
	{
		if (year < other.year)
			return true;
		if (year == other.year && month < other.month)
			return true;
		if (year == other.year && month == other.month && day < other.day)
			return true;
		return false;
	}
};

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();
		bool parseDatabase(std::string filename);
		bool parsePrices(std::string filename);
	private:
		std::map<Date, float> _database;

		Date isValidDate(std::string date) const;
		bool isValidRate(std::string price) const;
		bool isValidValue(std::string str) const;
		bool isErrorDate(Date& date) const;
		std::string trimString(std::string str) const;
		bool printPrice(Date date, float price) const;
		int stringToInt(std::string str) const;
		float stringToFloat(std::string str) const;
};

#endif