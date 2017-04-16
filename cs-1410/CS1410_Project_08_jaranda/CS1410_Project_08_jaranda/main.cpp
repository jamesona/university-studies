// Author: Jameson Aranda
// Assignment: CS1410_Project_08_jaranda
// Instructor: Craig Sharp
// Class: CS 1410 -- 002
// Date Written: 4/16/2017 11:19:24 AM
// Description: 

// I declare that the following code was written by me or provided
// by the instructor for this project. I understand that copying source
// code from any other source constitutes cheating, and that I will receive 
// a zero on this project if I am found in violation of this policy.

#pragma once
#include "stdafx.h"
#include <iostream>
#include "DynArray.h"
using namespace std;

int main()
{
	// Create a default vector (cap = 2)
	DynArray sam;
	cout << "capacity = " << sam.capacity() << endl;

	// push some data into sam
	cout << "\nPushing three values into sam";
	sam.push_back(21);
	sam.push_back(31);
	sam.push_back(41);

	cout << "\nThe values in sam are: ";

	// test for out of bounds condition here
	for (int i = 0; i < sam.size() + 1; i++)
	{
		try
		{
			cout << sam.at(i) << " ";
		}
		catch (runtime_error& x)
		{
			cout << x.what() << endl;
		}
	}
	cout << "\n--------------\n";

	// clear sam and display its size and capacity
	sam.clear();
	cout << "\nsam has been cleared.";
	cout << "\nSam's size is now " << sam.size();
	cout << "\nSam's capacity is now " << sam.capacity() << endl;
	cout << "---------------\n";

	// Push 12 values into the vector - it should grow
	cout << "\nPush 12 values into sam.";
	for (int i = 0; i < 12; i++)
		sam.push_back(i);

	cout << "\nSam's size is now " << sam.size();
	cout << "\nSam's capacity is now " << sam.capacity() << endl;
	cout << "---------------\n";

	cout << "\nTest to see if contents are correct...";
	// display the values in the vector
	for (int i = 0; i < sam.size(); i++)
	{
		cout << sam.at(i) << " ";
	}
	cout << "\n--------------\n";

	cout << "\nDriver Complete...";

	cout << endl;
	cin.get();
}