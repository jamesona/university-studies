// Author: Jameson Aranda
// Assignment: CS1410_Lab_05_jaranda
// Instructor: Craig Sharp
// Class: CS 1410 -- 002
// Date Written: 2/9/2017 3:22:04 PM
// Description: 

// I declare that the following code was written by me or provided
// by the instructor for this project. I understand that copying source
// code from any other source constitutes cheating, and that I will receive 
// a zero on this project if I am found in violation of this policy.

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept>

using namespace std;


// Function Name: calculateSquare
// Purpose: square a positive int
// Parameters: int sqrVal
// Returns: int
// Pre-conditions: none
// Post-conditions: none
int calculateSquare(int sqrVal)
{
	try
	{
		if (sqrVal > 0)
		{
			return sqrVal * sqrVal;
		}
		else
		{
			cout << "You entered: " << sqrVal ;
			throw runtime_error("\nYou didn't read the prompt....");
		}
	}
	catch (runtime_error& e)
	{
		cout << "System Error: " << e.what() << endl;
	}
}

int main()
{
	int sqrVal;

	cout << "Enter a whole number greater than 0: ";
	cin >> sqrVal;

	cout << calculateSquare(sqrVal) << endl;

	cin.clear();
	cin.ignore();
	cin.get();
}

