// Author: Jameson Aranda
// Assignment: Project 01
// Instructor: Craig Sharp
// Class: CS 1410 -- 002
// Date Written: 1/24/17
// Description: a program to find the sum of an array of doubles

using namespace std;
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>



// Function Name: getIncome   
// Purpose: Prompts the user for their taxable income
// Parameters: none
// Returns: a positive integer
// Pre-conditions: none
// Post-conditions: none
int getIncome()
{
	string input;
	int income;
	bool valid = false;
	
	// prompt the user
	cout << "Please enter your total taxable income: ";
	
	// until the iput is valid
	while (!valid)
	{
		// read the input
		cin >> income;

		// determine if we were able to store the input as a positive int
		if ( !cin.fail() && (cin.peek() == EOF || cin.peek() == '\n') && income >= 0 )
		{
			// mark valid
			valid = true;
		}

		else 
		{
			// invalid input, re-prompt the user
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Please enter a positive integer. (round down if needed): ";
		}
	}
	// return the income int
	return income;
}

// Function Name: promptChoice   
// Purpose: Prompts the user for filing status (joint or single)
// Parameters: str prompt, char option 1, char option 2
// Returns: a boolean value representing user choice
// Pre-conditions: none
// Post-conditions: none
bool promptChoice(string prompt, char opt_1, char opt_2)
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

// Function Name: taxesOwed
// Purpose: tetermines total taxes owed based on income and marital status
// Parameters: int income, bool marital status
// Returns: none
// Pre-conditions: none
// Post-conditions: none
void taxesOwed()
{

	const int NUMBER_OF_TIERS = 4,
		THRESHOLDS[][NUMBER_OF_TIERS] =
	{
		{ 0, 863, 2588, 4313 },
		{ 0, 1726, 5176, 8626 }
	},
		DEDUCTIONS[][NUMBER_OF_TIERS] =
	{
		{0, 863, 2588, 4313},
		{0, 1726, 5176, 8626}
	},
		FEES[][NUMBER_OF_TIERS] =
	{
		{0, 25, 85, 181},
		{0, 40, 175, 390}
	};

	const double RATES[] = { 0.023, 0.033, 0.052, 0.075 };

	// until we determine otherwise, assume we're single and rich
	int income = getIncome(), tier = NUMBER_OF_TIERS - 1, maritalStatus = 0, 
		// reserve some other names for calculation
		deduction, fee, taxableIncome;
	// we'll need these ones too.
	double total, rate, tax;

	// determine which set of numbers we're going to use
	if ( !promptChoice("Are you filing singly, or jointly?", 's', 'm') )
	{
		// Single defaults to the first set (index 0).
		// If we're married, use the second (index 1)
		maritalStatus = 1;
	}

	// determine which tax tier we're using
	while (income <= THRESHOLDS[maritalStatus][tier])
	{
		// if we made less than or equal to the current tier
		// decrement the tier
		tier--;
	};

	// after we know our status and tier, let's find the numbers
	deduction = THRESHOLDS[maritalStatus][tier];
	rate = RATES[tier];
	fee = FEES[maritalStatus][tier];

	// now that we know all the figures, we can start solving the total
	taxableIncome = income - deduction;
	tax = taxableIncome * rate;
	total = tax + fee;


	// this is some super verbose output I used while debugging
	cout << "\nBecause you earned more than $" << THRESHOLDS[maritalStatus][tier];
	cout << ", you fall in tax bracket " << tier + 1 << endl;
	cout << "Your tax rate is " << rate * 100 << "%.\n" << endl;

	cout << "You may make a standard deduction of $" << deduction << "." << endl;
	cout << "This means your taxable income is $" << taxableIncome << ".\n" << endl;

	cout << rate * 100 << "% of $" << taxableIncome << " is $" << tax << "." << endl;
	cout << "Your bracket has an additional fee of $" << fee << " bringing your total to $";
	cout << total << fixed << setprecision(2) << ".\n" << endl;
}

int main()
{
	bool prepareTaxes = true;

	while (prepareTaxes)
	{
		taxesOwed();
		prepareTaxes = promptChoice("Would you like to perform another tax calculation?", 'y', 'n');
		cout << endl;
	};

	system("pause");
}

