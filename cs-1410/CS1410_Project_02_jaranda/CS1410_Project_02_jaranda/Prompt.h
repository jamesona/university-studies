// Author: Jameson Aranda
// Date Written: 2/5/2017 4:53:48 PM
// Description: A class of static helper functions for prompting user input

#pragma once
#include <string>

using std::string;


class Prompt
{
private:
	static const int MIN = INT_MIN, MAX = INT_MAX;
public:
	// Function Name: getInt
	// Purpose: Prompt user for an integer
	// Parameters: string prompt, optional int min, optional int max
	// Returns: a positive integer
	// Pre-conditions: none
	// Post-conditions: none
	static int getInt(string prompt, int min = MIN, int max = MAX);

	// Function Name: promptChoice
	// Purpose: Prompts the user for a choice
	// Parameters: str prompt, char option 1, char option 2
	// Returns: a boolean value representing user choice
	// Pre-conditions: none
	// Post-conditions: none
	static bool getChoice(string prompt, char opt_1, char opt_2);
};

