#include <vector>

class Span{
	public:
		Span(const unsigned int n);
		Span(const Span& obj);
		Span& operator==(const Span& obj);
		~Span();
		void addNumber(const unsigned int number);
		void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
		const std::vector<int>& getArray() const;
	private:
		Span();
		std::vector<int>	_array;
		unsigned int		_size;
};