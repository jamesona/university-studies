#include "stdafx.h"
#include "DynArray.h"

DynArray::DynArray()
{
	_array = new int[2];
	_capacity = 2;
	_size = 0;
}

DynArray::DynArray(int n)
{
	_array = new int[n];
	_capacity = n;
	_size = 0;
}

int DynArray::size()
{
	return _size;
}

int DynArray::capacity()
{
	return this->_capacity;
}

void DynArray::resize(int s)
{
	if (s <= _capacity) return;

	int* _newArr = new int[s];

	for (int i = 0; i < _capacity; ++i)
	{
		_newArr[i] = _array[i];
	}

	_capacity = s;
	delete[] _array;
	_array = _newArr;
}

void DynArray::clear()
{
	for (int i = 0; i < _size; ++i)
	{
		_array[i] = NULL;
	}

	_size = 0;
}

void DynArray::push_back(int n)
{
	if (_size >= _capacity) resize(_capacity * 1.5);
	_array[_size] = n;
	_size++;
}

void DynArray::pop_back()
{
	_array[_size] = NULL;
	_size--;
}

int DynArray::at(int i)
{
	if (i > _size - 1) throw std::runtime_error("Index is out of range");
	return _array[i];
}