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