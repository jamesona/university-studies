// Author: Jameson Aranda
// Assignment: CS1410_Project_03_jaranda
// Instructor: Craig Sharp
// Class: CS 1410 -- 002
// Date Written: 2/14/2017 2:08:27 PM
// Description: 

// I declare that the following code was written by me or provided
// by the instructor for this project. I understand that copying source
// code from any other source constitutes cheating, and that I will receive 
// a zero on this project if I am found in violation of this policy.

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

// Function Name: mySort
// Purpose: sort an array of integers
// Parameters: int[] nums, int nelems, int begin
// Returns: none
// Pre-conditions: a populated array is required
// Post-conditions: the array is sorted in ascending order
void mySort(int* nums, int nelems, int begin = 0)
{
	int oldVal = nums[begin], minIndex, iterator = begin;

	while (iterator < nelems)
	{
		if (iterator == begin || nums[iterator] < nums[minIndex])
		{
			minIndex = iterator;
		}
		iterator++;
	}

	nums[begin] = nums[minIndex];
	nums[minIndex] = oldVal;
	
	if (++begin != nelems)
	{
		mySort(nums, nelems, begin);
	}
}

// Function Name: hiloLogic
// Purpose: perform recursive logic for the hilo function
// Parameters: int lower, int upper
// Returns: none
// Pre-conditions: none
// Post-conditions: none
void hiloLogic(int lower, int upper)
{
	const int TWO = 2;
	int midpoint = lower + ((upper - lower) / TWO);
	char response;
	bool valid = false;

	cout << "I guess " << midpoint << ". Is that correct, high, or low? [y/h/l] ";

	while (!valid)
	{
		cin >> response;
		if (response == 'y' || response == 'h' || response == 'l')
		{
			valid = true;

			if (response != 'y' && lower >= upper)
			{
				cout << "You cheated!" << endl;
				return;
			}
		}
		else
		{
			cout << endl << "Invalid response. Please enter y, h, or l. ";
		}
	}

	switch (response)
	{
		case 'y':
		{
			cout << "I got it right!" << endl;
			break;
		}

		case 'h':
		{
			hiloLogic(lower, --midpoint);
			break;
		}
		case 'l':
		{
			hiloLogic(++midpoint, upper);
			break;
		}
	} // end switch

	return;
}

// Function Name: hilo
// Purpose: a guessing game based on lambda calculus
// Parameters: int size
// Returns: none
// Pre-conditions: none
// Post-conditions: none
void hilo(int size)
{
	hiloLogic(1, size);
}

void printArray(int* array, int size)
{
	int i = 0;
	cout << '[';
	while (i < size)
	{
		cout << array[i];
		if (i != size - 1)
		{
			cout << ',';
		}
		i++;
	}
	cout << ']' << endl;
}

int main()
{
	int array[] = { 3, 2, 1, 6, 5, 4, 9, 7, 8, 0 }, size = sizeof(array) / sizeof(*array);

	cout << "Unsorted array: ";
	printArray(array, size);

	mySort(array, size);
	
	cout << "Sorted array: ";
	printArray(array, size);

	hilo(size);

	cin.ignore();
	cin.get();
}
