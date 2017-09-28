// Author: Jameson Aranda
// Assignment: CS1410_Lab_07_jaranda
// Instructor: Craig Sharp
// Class: CS 1410 -- 002
// Date Written: 3/6/2017 5:49:10 PM
// Description: This program will take an input char (string) and use only pointers to reverse the string


// I declare that the following code was written by me or provided
// by the instructor for this project. I understand that copying source
// code from any other source constitutes cheating, and that I will receive 
// a zero on this project if I am found in violation of this policy.




#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


char myString;

// Function Name: reverser
// Purpose: reverse a character array
// Parameters: char *mystring
// Returns: char *mystring
// Pre-conditions: none
// Post-conditions: none
char reverser(char *myString)
{
	char tempChar = 'X';
	int numChars = 0;
	char *pointerBeg = myString;
	char *pointerEnd;
	
	while (tempChar != '\0')
	{
		tempChar = myString[numChars];
		numChars++;
	}



	pointerEnd = myString + --numChars - 1;

    while (pointerBeg < pointerEnd) {
        tempChar = *pointerBeg;
        *pointerBeg++ = *pointerEnd;
        *pointerEnd-- = tempChar;
    }

	return *myString;
}

	



int main()
{

	char myString[]= "Hello World!";
	cout << myString << "\n";
	reverser(myString);
	cout << "The reversed string is: " << myString << "\n";//H
	cin.get();

}