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
	private:
		T*	_array;
		unsigned int _size;
};

template <typename T>
Array<T>::Array() : _size(0){
	_array = new T[1];
	_array[0] = 0;
}

template <typename T>
Array<T>::~Array(){
	delete[] _array;
}

template <typename T>
Array<T>::Array(const Array& obj){
	_array = new T[obj._size];
	_size = obj._size;

	for (unsigned int i = 0; i < _size; i++)
		_array[i] = obj._array[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& obj){
	if (this != &obj){
		_array = new T[obj._size];
		_size = obj._size;

		for (unsigned int i = 0; i < _size; i++)
			_array[i] = obj._array[i];
	}
	return (*this);
}

template <typename T>
Array<T>::Array(unsigned int n){
	if (n == 0)
		throw std::exception();
	_array = new T[n];
	_size = n;
}

template <typename T>
T& Array<T>::operator[](unsigned int n){
	if (n == 0)
		return (_array[0]);
	if (n + 1 > _size)
		throw(std::exception());
	return (_array[n]);
}