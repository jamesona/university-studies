// Author: Jameson Aranda
// Assignment: CS1410_Lab_04_jaranda
// Instructor: Craig Sharp
// Class: CS 1410 -- 002
// Date Written: 1/28/2017 11:24:26 PM
// Description: 

// I declare that the following code was written by me or provided
// by the instructor for this project. I understand that copying source
// code from any other source constitutes cheating, and that I will receive 
// a zero on this project if I am found in violation of this policy.

// Function Name: 
// Purpose: 
// Parameters: 
// Returns: 
// Pre-conditions: 
// Post-conditions: 

#include "stdafx.h"
#include "MyRectangle.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

int main()
{
	const int WIDTH = 4, HEIGHT = 7;

	MyRectangle rectangle = MyRectangle::MyRectangle(WIDTH, HEIGHT);
	cout << "Rectangle width: " << rectangle.getWidth() << endl;
	cout << "Rectangle height: " << rectangle.getHeight() << endl;
	cout << "Rectangle area: " << rectangle.getArea() << endl;
	cin.get();
	return 0;
}

