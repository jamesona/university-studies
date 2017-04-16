#include <stdexcept>

class DynArray
{
private:
	int _size, _capacity;
	int* _array;

	// Function Name: resize
	// Purpose: resize the array to a capacity of at least n
	// Parameters: int size
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
	// Parameters: int n
	// Returns: DynArray
	// Pre-conditions: none
	// Post-conditions: none
	DynArray(int n);

	// Function Name: size
	// Purpose: return the current size
	// Parameters: none
	// Returns: int size
	// Pre-conditions: none
	// Post-conditions: none
	int size();

	// Function Name: capacity
	// Purpose: return the current capacity
	// Parameters: none
	// Returns: int capacity
	// Pre-conditions: none
	// Post-conditions: none
	int capacity();

	// Function Name: clear
	// Purpose: empty the DynArray
	// Parameters: none
	// Returns: none
	// Pre-conditions: none
	// Post-conditions: none
	void clear();

	// Function Name: push_back
	// Purpose: add an integer to the back of the array
	// Parameters: int n
	// Returns: none
	// Pre-conditions: none
	// Post-conditions: none
	void push_back(int n);

	// Function Name: pop_back
	// Purpose: remove the last item from the array
	// Parameters: none
	// Returns: none
	// Pre-conditions: none
	// Post-conditions: none
	void pop_back();

	// Function Name: at
	// Purpose: returns the item at index i
	// Parameters: int i
	// Returns: int n
	// Pre-conditions: none
	// Post-conditions: none
	int at(int i);
};