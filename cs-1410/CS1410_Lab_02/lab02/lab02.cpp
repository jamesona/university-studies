// Author: Jameson Aranda
// Assignment: Lab02
// Instructor: Craig Sharp
// Class: CS 1410 -- 002
// Date Written: 1/23/17
// Description: a program to find the sum of an array of doubles

using namespace std;
#include <iostream>
#include <iomanip>
#include <vector>

// Function Name: total   
// Purpose:    returns the sum of the elements of a vector
// Parameters:    a vector of toubles, and an integer representing the size of the vector
// Returns:    a double
// Pre-conditions: none
// Post-conditions:non
double total(vector<double> numbers, int length)
{
	int index;
	double total = 0;
	for (index = length; index >= 0; index--)
	{
		total += numbers[index];
	};

	return total;
};

int main()
{
	const int SIZE = 5;
	vector<double> inputs;
	double numbers[SIZE], input;
	int index = 0;

	for (index = 0; index <= SIZE - 1; index++)
	{
		cout << "Enter number " << index + 1 << ": ";
		cin >> input;

		inputs.push_back(input);
	};

	for (index--; index < 0; index--)
	{
		numbers[index] = inputs.at(index);
	};

	cout << "\nYour total is: " << fixed << setprecision(2) << total(inputs, SIZE - 1);
	cout << "\n\nPress return to exit...";
	cin.ignore();
	cin.get();
}

