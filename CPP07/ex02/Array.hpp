#include <exception>
#include <iostream>

template <typename T>
class Array{
	public:
		Array();
		Array(const Array& obj);
		Array<T>& operator=(const Array& obj);
		~Array();
		Array(unsigned int n);
		T& operator[](unsigned int n);
		unsigned int	size() const;
	private:
		T*	_array;
};

template <typename T>
Array<T>::Array(){
	_array = new T[1];
	_array[0] = 0;
}

template <typename T>
Array<T>::~Array(){
	delete[] _array;
}

template <typename T>
Array<T>::Array(const Array& obj){
	_array = new Array(*obj._array);
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& obj){
	if (this != &obj)
		_array = new Array(*obj._array);
	return (*this);
}

template <typename T>
Array<T>::Array(unsigned int n){
	if (n == 0)
		throw std::exception();
	_array = new T[n];
	for (unsigned int i = 0; i < n; i++)
		_array[i] = i + 1;
}

template <typename T>
unsigned int Array<T>::size() const{
	unsigned int size = 0;

	while (_array[size])
		size++;
	return (size);
}

template <typename T>
T& Array<T>::operator[](unsigned int n){
	unsigned int size = Array::size();
	try{
		if (n + 1 > size)
			throw std::exception();
	}
	catch (std::exception){
		std::cout << "Index out of bounds!" << std::endl;
		throw std::exception();
	}
	return (_array[n]);
}