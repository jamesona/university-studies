#include "stdafx.h"
#include "Prompt.h"
#include <iostream>
#include <limits>

using std::string;
using std::cin;
using std::cout;

int Prompt::getInt(string prompt, int min, int max)
{
	int input;
	bool valid = false;

	// prompt the user
	cout << prompt;

	// until the iput is valid
	while (!valid)
	{
		// read the input
		cin >> input;

		// determine if we were able to store the input as an int > min and < max
		if (!cin.fail() && (cin.peek() == EOF || cin.peek() == '\n') && input >= min && input <= max)
		{
			// mark valid
			valid = true;
		}

		else
		{
			// invalid input, re-prompt the user
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Please enter an integer number: ";
		}
	}

	return input;
}

bool Prompt::getChoice(string prompt, char opt_1 = 'y', char opt_2 = 'n')
{
	char response;
	bool valid = false, status = true;

	// prompt the user
	cout << prompt << " [" << opt_1 << "/" << opt_2 << "] ";

	// until we have a valid input
	while (!valid)
	{
		// read user input
		cin >> response;

		// check if it's one of the response characters
		if (!cin.fail() && response == opt_1 || response == opt_2)
		{
			// if it is, we're valid. Yay.
			valid = true;
		}

		else
		{
			// we're not valid. clear the input buffer, and re-prompt
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Please enter either '" << opt_1 << "' or '" << opt_2 << "': ";
		}
	}
	// return whether or not the first option was chosen
	return response == opt_1;
}