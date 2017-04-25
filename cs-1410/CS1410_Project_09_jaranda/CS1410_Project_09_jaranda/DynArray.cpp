#include "stdafx.h"
#include "DynArray.h"

template <typename T>
DynArray<T>::DynArray()
{
	_array = new T[2];
	_capacity = 2;
	_size = 0;
}

template <typename T>
DynArray<T>::DynArray(int n)
{
	_array = new T[n];
	_capacity = n;
	_size = 0;
}

template <typename T>
DynArray<T>::DynArray(const DynArray<T> &oldArray)
{
	int oldCap = oldArray.capacity(),
		oldSize = oldArray.size();

	_size = 0;
	_array = new T[oldCap];
	_capacity = oldCap;

	for (_size; _size < oldSize; _size++)
	{
		this->push_back(oldVal);
	}
}

template <typename T>
int DynArray<T>::size() const
{
	return _size;
}

template <typename T>
int DynArray<T>::capacity() const
{
	return this->_capacity;
}

template <typename T>
void DynArray<T>::resize(int s)
{
	if (s <= _capacity) return;

	T* _newArr = new T[s];

	for (int i = 0; i < _capacity; ++i)
	{
		_newArr[i] = _array[i];
	}

	_capacity = s;
	delete[] _array;
	_array = _newArr;
}

template <typename T>
void DynArray<T>::clear()
{
	for (int i = 0; i < _size; ++i)
	{
		_array[i] = NULL;
	}

	_size = 0;
}

template <typename T>
T& DynArray<T>::front()
{
	if (_size < 1) throw std::runtime_error("Array is empty");
	else return _array[0];
}

template <typename T>
T& DynArray<T>::back()
{
	if (_size < 1) throw std::runtime_error("Array is empty");
	else return _array[_size - 1];
}

template <typename T>
T& DynArray<T>::last()
{
	if (_size < 1) throw std::runtime_error("Array is empty");
	else return _array[_size - 1];
}

template <typename T>
void DynArray<T>::push_back(T n)
{
	if (_size >= _capacity) resize(_capacity * 1.5);
	_array[_size] = n;
	_size++;
}

template <typename T>
void DynArray<T>::pop_back()
{
	_array[_size] = NULL;
	_size--;
}

template <typename T>
T& DynArray<T>::at(int i) const
{
	if (i > _size - 1) throw std::runtime_error("Index is out of range");
	else return _array[i];
}

template <typename T>
T& DynArray<T>::operator[](int i) const
{
	if (i > _size - 1) throw std::runtime_error("Index is out of range");
	else return _array[i];
}