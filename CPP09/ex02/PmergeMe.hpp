#ifndef PMERGE_HPP
# define PMERGE_HPP

#include <vector>
#include <list>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <ctime>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();
		bool sortWithVector(const std::string &args);
		bool sortWithList(const std::string &args);
		std::vector<int> getUnsorted() const;
		std::vector<int> getSorted() const;
		clock_t getListTime() const;
		clock_t getVectorTime() const;
		void printTime(clock_t argTime) const;

	private:

		bool storeArgs(const std::string &args, bool isVector);
		void createPairs(bool isVector);
		void insertionSort(bool isVector);
		void binarySearch(bool isVector);
		void printContainer(bool isVector) const;
		int stringToInt(std::string str) const;
		clock_t _listTime;
		clock_t _vectorTime;
		std::vector<int> _vector;
		std::vector<int> _bigVector;
		std::vector<int> _smallVector;
		std::list<int> _list;
		std::list<int> _bigList;
		std::list<int> _smallList;
};


#endif