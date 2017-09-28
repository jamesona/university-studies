#include <stdexcept>

template <typename T>
class DynArray
{
private:
	int _size, _capacity;
	T* _array;

	// Function Name: resize
	// Purpose: resize the array to a capacity of at least n
	// Parameters: T size
	// Returns: none
	// Pre-conditions: none
	// Post-conditions: none
	void resize(int s);

public:
	// Function Name: DynArray
	// Purpose: create a new DynArray with starting capacity of 2
	// Parameters: none
	// Returns: DynArray
	// Pre-conditions: none
	// Post-conditions: none
	DynArray();

	// Function Name: DynArray
	// Purpose: create a new DynArray with starting capacity n
	// Parameters: int
	// Returns: DynArray
	// Pre-conditions: none
	// Post-conditions: none
	DynArray(int n);

	// Function Name: DynArray
	// Purpose: create a new DynArray as a clone of existing DynArray
	// Parameters: T n
	// Returns: DynArray
	// Pre-conditions: none
	// Post-conditions: none
	DynArray(const DynArray<T>&);

	// Function Name: size
	// Purpose: return the current size
	// Parameters: none
	// Returns: int size
	// Pre-conditions: none
	// Post-conditions: none
	int size() const;

	// Function Name: capacity
	// Purpose: return the current capacity
	// Parameters: none
	// Returns: int capacity
	// Pre-conditions: none
	// Post-conditions: none
	int capacity() const;

	// Function Name: clear
	// Purpose: empty the DynArray
	// Parameters: none
	// Returns: none
	// Pre-conditions: none
	// Post-conditions: none
	void clear();

	// Function Name: front
	// Purpose: return the first item of the array
	// Parameters: none
	// Returns: first item
	// Pre-conditions: none
	// Post-conditions: none
	T& front();

	// Function Name: back
	// Purpose: return the last item of the array
	// Parameters: none
	// Returns: last item
	// Pre-conditions: none
	// Post-conditions: none
	T& back();

	// Function Name: last
	// Purpose: alias for back
	// Parameters: none
	// Returns: last item
	// Pre-conditions: none
	// Post-conditions: none
	T& last();

	// Function Name: push_back
	// Purpose: add an Teger to the back of the array
	// Parameters: T n
	// Returns: none
	// Pre-conditions: none
	// Post-conditions: none
	void push_back(T n);

	// Function Name: pop_back
	// Purpose: remove the last item from the array
	// Parameters: none
	// Returns: none
	// Pre-conditions: none
	// Post-conditions: none
	void pop_back();

	// Function Name: at
	// Purpose: returns the item at index i
	// Parameters: T i
	// Returns: T n
	// Pre-conditions: none
	// Post-conditions: none
	T& at(int i) const;

	T& operator[](int i) const;
};

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
		this->push_back(oldArray.at(_size));
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