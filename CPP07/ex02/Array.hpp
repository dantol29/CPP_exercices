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
	_array = new Array(*obj._array);
	_size = obj.size;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& obj){
	if (this != &obj){
		_array = new Array(*obj._array);
		_size = obj._size;
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