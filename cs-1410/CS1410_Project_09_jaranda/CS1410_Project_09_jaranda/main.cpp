// Author: Jameson Aranda
// Assignment: CS1410_Project_09_jaranda
// Instructor: Craig Sharp
// Class: CS 1410 -- 002
// Date Written: 4/24/2017 8:56:36 PM
// Description: 

// I declare that the following code was written by me or provided
// by the instructor for this project. I understand that copying source
// code from any other source constitutes cheating, and that I will receive 
// a zero on this project if I am found in violation of this policy.


// Driver code
// CS 1410
// Project 13
// Author: Roger deBry
// Date last modified: november 2014
// -----------------------------------------
#include "stdafx.h"
#include <iostream>
#include "DynArray.h"
using namespace std;

int main()
{
	const char START = 'A';
	const int MAX = 12;

	// create a vector of doubles
	DynArray<char> vectD;

	// push some values into the vector
	for (int i = 0; i < MAX; i++)
	{
		vectD.push_back(START + i);
	}

	// remove the last element
	vectD.pop_back();

	// add another value
	vectD.push_back('Z');

	// test memory management
	DynArray<char> vectD2 = vectD;
	// display the contents
	cout << "\n[";
	for (int i = 0; i < vectD2.size() - 1; i++)
	{
		cout << vectD2[i] << ", ";
	}

	cout << "..., " << vectD2.last() << "]\n";
	cin.get();
}
