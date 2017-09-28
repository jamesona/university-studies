// Author: Jameson Aranda
// Assignment: CS1410_Lab_06_jaranda
// Instructor: Craig Sharp
// Class: CS 1410 -- 002
// Date Written: 2/13/2017 10:18:37 PM
// Description: 

// I declare that the following code was written by me or provided
// by the instructor for this project. I understand that copying source
// code from any other source constitutes cheating, and that I will receive 
// a zero on this project if I am found in violation of this policy.

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

const int ARRAY_SIZE = 100;

int main()
{
	int i = 0, numberOfValues;
	double voltage, sum = 0, voltages [ARRAY_SIZE];

	ifstream file;
	file.open("voltages.txt");

	if (file.is_open())
	{
		while (!file.eof())
		{
			file >> voltages[i++];
		}
	}

	numberOfValues = --i;

	cout << "File read complete! Imported " << numberOfValues << " values." << endl;

	while (i > 0)
	{
		sum += voltages[--i];
	}

	cout << "The average voltage was " << sum / numberOfValues << endl;

	cout << "\n\nPress any key to continue. . ." << endl;
	cin.get();
}

