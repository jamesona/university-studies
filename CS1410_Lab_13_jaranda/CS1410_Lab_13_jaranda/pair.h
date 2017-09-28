#pragma once

template <class T>
class Pair
{
	T values[2];
public:
	Pair(T first, T second)
	{
		values[0] = first; 
		values[1] = second;
	}
	T getFirst();
	T getSecond();
};

// Function Name: getFirst
// Purpose: return the first member
// Parameters: none
// Returns: <T> member
// Pre-conditions: none
// Post-conditions: none
template <class T> T Pair<T>::getFirst()
{
	return values[0];
}

// Function Name: getSecond
// Purpose: return the second member
// Parameters: none
// Returns: <T> member
// Pre-conditions: none
// Post-conditions: none
template <class T> T Pair<T>::getSecond()
{
	return values[1];
}