// Author: Jameson Aranda
// Assignment: CS1410_Lab_13_jaranda
// Instructor: Craig Sharp
// Class: CS 1410 -- 002
// Date Written: 4/3/2017 6:41:51 PM
// Description: A class to demonstrate templates

// I declare that the following code was written by me or provided
// by the instructor for this project. I understand that copying source
// code from any other source constitutes cheating, and that I will receive 
// a zero on this project if I am found in violation of this policy. 

#include "stdafx.h"
#include <iostream>
#include "pair.h"
using namespace std;


int main()
{
	Pair<char> letters('a', 'd');
	cout << "\nThe first letter is: " << letters.getFirst();
	cout << "\nThe second letter is: " << letters.getSecond();

	cout << endl;
	cin.get();
}
