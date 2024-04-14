#include <list>
#include <algorithm>

template <typename T>
bool	easyfind(const T& container, const int number)
{
	typename T::const_iterator result;

	result = std::find(container.begin(), container.end(), number);
	if (result != container.end())
		return (true);
	return (false);
}
