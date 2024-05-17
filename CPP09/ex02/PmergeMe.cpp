# include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	(void)other;
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

int PmergeMe::stringToInt(std::string str) const
{
	int result;

	std::stringstream ss(str);
	ss >> result;
	if (ss.fail())
	{
		std::cerr << "Error: " << str << " is not a number" << std::endl;
		return (-1);
	}
	return (result);
}

bool PmergeMe::storeArgs(const std::string &args, bool isVector)
{
	int number;
	unsigned int start;

	for (unsigned int i = 0; i < args.length(); ++i)
	{
		while (i < args.length() && args[i] == ' ')
			++i;
		if (i == args.length())
			break;

		start = i;
		while (i < args.length() && args[i] != ' ')
			++i;

		number = stringToInt(args.substr(start, i - start));
		if (number == -1)
			return (std::cout << "Error: invalid number" << std::endl, false);

		if (isVector)
			_vector.push_back(number);
		else
			_list.push_back(number);
	}
	return (true);
}

std::vector<int> PmergeMe::getUnsorted() const
{
	return (_vector);
}

std::vector<int> PmergeMe::getSorted() const
{
	return (_smallVector);
}

clock_t PmergeMe::getListTime() const
{
	return (_listTime);
}

clock_t PmergeMe::getVectorTime() const
{
	return (_vectorTime);
}

void PmergeMe::printTime(clock_t argTime) const
{
	std::cout << std::fixed << std::setprecision(10) << (float)argTime/CLOCKS_PER_SEC << " seconds" << std::endl;
}

void PmergeMe::printContainer(bool isVector) const
{
	if (isVector)
	{
		for (std::vector<int>::const_iterator it = _smallVector.begin(); it != _smallVector.end(); ++it)
			std::cout << *it << " ";
	}
	else
	{
		for (std::list<int>::const_iterator it = _smallList.begin(); it != _smallList.end(); ++it)
			std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::createPairs(bool isVector)
{
	if (isVector)
	{
		for (unsigned int i = 0; i < _vector.size(); i += 2)
		{
			if (i + 1 < _vector.size())
			{
				if (_vector[i] <= _vector[i + 1])
				{
					_smallVector.push_back(_vector[i]);
					_bigVector.push_back(_vector[i + 1]);
				}
				else
				{
					_smallVector.push_back(_vector[i + 1]);
					_bigVector.push_back(_vector[i]);
				}
			}
			else
				_smallVector.push_back(_vector[i]);
		}
	}
	else
	{
		std::list<int>::iterator it = _list.begin();
		std::list<int>::iterator nextIt;

		while (it != _list.end())
		{
			nextIt = it;
    		++nextIt;
			if (nextIt != _list.end())
			{
				if (*it <= *nextIt)
				{
					_smallList.push_back(*it);
					_bigList.push_back(*nextIt);
				}
				else
				{
					_smallList.push_back(*nextIt);
					_bigList.push_back(*it);
				}
				std::advance(it, 2);
			}
			else
			{
				_smallList.push_back(*it);
				++it;
			}
		}
	}
}

void PmergeMe::insertionSort(bool isVector)
{
	int tmp;
	unsigned int j;

	if (isVector)
	{
		if (_smallVector.size() < 2)
			return ;

		for (unsigned int i = 1; i < _smallVector.size(); ++i)
		{
			tmp = _smallVector[i];
			j = i;
			
			// shift elements to the right until find smaller element
			while (j > 0 && _smallVector[j - 1] > tmp)
			{
				_smallVector[j] = _smallVector[j - 1];
				--j;
			}
			_smallVector[j] = tmp;
		}
	}
	else
	{
		std::list<int>::iterator it = _smallList.begin();
		std::list<int>::iterator prevIt = _smallList.begin();
		std::list<int>::iterator currentIt;
		if (_smallList.size() < 2)
			return ;

		// skip first element
		++it;
		for (int i = 1; it != _smallList.end(); ++it, ++i)
		{
			tmp = *it;
			j = i;
			
			// shift elements to the right until find smaller element
			currentIt = it;
			while (j > 0 && *prevIt > tmp)
			{
				*currentIt = *prevIt;
				--currentIt;
				--prevIt;
				--j;
			}
			*currentIt = tmp;
			prevIt = it;
		}
	}
}

void PmergeMe::binarySearch(bool isVector)
{
	unsigned int mid;

	
	if (isVector)
	{
		if (_bigVector.size() < 2)
			return ;
		for (unsigned int i = 0; i < _bigVector.size(); ++i)
		{
			mid = (_smallVector.size() - 1) / 2;
			
			if (_bigVector[i] < _smallVector[mid])
			{
				while (mid > 0 && _bigVector[i] < _smallVector[mid])
					--mid;
			}
			else
			{
				while (mid < _smallVector.size() && _bigVector[i] > _smallVector[mid])
					++mid;
			}
			_smallVector.insert(_smallVector.begin() + mid, _bigVector[i]);
		}
	}
	else
	{
		if (_bigList.size() < 2)
			return ;
		std::list<int>::iterator sm = _smallList.begin();

		for (std::list<int>::iterator it = _bigList.begin(); it != _bigList.end(); ++it)
		{
			mid = (_smallList.size() - 1) / 2;
			sm = _smallList.begin();
			std::advance(sm, mid);

			if (*it < *sm)
			{
				while (mid > 0 && *it < *sm)
				{
					--mid;
					--sm;
				}
			}
			else
			{
				while (mid < _smallList.size() && *it > *sm)
				{
					++mid;
					++sm;
				}
			}
			_smallList.insert(sm, *it);
		}
	}
}

/* 
1. store the numbers in a vector
2. create pairs of numbers
3. push the smallest number from each pair into a small vector
4. push the biggest number from each pair into a big vector
5. sort the small vector using insertion sort
6. insert the big vector into the small vector using binary search
*/
bool PmergeMe::sortWithVector(const std::string &args)
{
	_vectorTime = clock();
	// 1. store the numbers in a vector
	if (!storeArgs(args, true))
		return (false);

	// 2. create pairs of numbers
	// 3. push the smallest number from each pair into a small vector
	// 4. push the biggest number from each pair into a big vector
	createPairs(true);

	// 5. sort the small vector using insertion sort
	insertionSort(true);

	// 6. insert the big vector into the small vector using binary search
	binarySearch(true);

	_vectorTime = clock() - _vectorTime;
	return (true);
}

bool PmergeMe::sortWithList(const std::string &args)
{
	_listTime = clock();
	// 1. store the numbers in a list
	if (!storeArgs(args, false))
		return (false);
	
	// 2. create pairs of numbers
	// 3. push the smallest number from each pair into a small list
	// 4. push the biggest number from each pair into a big list
	createPairs(false);

	// 5. sort the small list using insertion sort
	insertionSort(false);

	// 6. insert the big list into the small list using binary search
	binarySearch(false);

	_listTime = clock() - _listTime;
	return (true);
}