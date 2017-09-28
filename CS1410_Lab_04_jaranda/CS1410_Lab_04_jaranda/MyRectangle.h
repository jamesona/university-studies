#pragma once
class MyRectangle
{
private: 
	int height;
	int width;
public:
	MyRectangle();

	// Function Name: MyRectangle
	// Purpose: Rectangle constructor
	// Parameters: int height, int width
	// Returns: MyRectangle
	// Pre-conditions: none
	// Post-conditions: none
	MyRectangle(int, int);

	// Function Name: getHeight
	// Purpose:  Returns the private height property of a rectangle
	// Parameters: none
	// Returns: int height
	// Pre-conditions: none
	// Post-conditions: none
	int getHeight();
	
	// Function Name: getWidth
	// Purpose:  Returns the private width property of a rectangle
	// Parameters: none
	// Returns: int width
	// Pre-conditions: none
	// Post-conditions: none
	int getWidth();
	
	// Function Name: getArea
	// Purpose: Returns the calculated area of a rectangle
	// Parameters: none
	// Returns: int area
	// Pre-conditions: none
	// Post-conditions: none
	int getArea();
};

