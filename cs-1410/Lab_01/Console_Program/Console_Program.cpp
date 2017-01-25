// Lab One Programming Exercise
// CS 1410
// Jameson Aranda
// CS 1410 -- 002
// --------------------------


#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	// declarations
	int age;
	float value;
	string name;

	// Prompt the user for their age
	cout << "\nHow old are you? ";

	// Get their age and store it in the variable age
	cin >> age;

	// Prompt the user for how much money they have
	cout << "\nHow much money do you have? ";

	// Get the amount of money and store it in the variable value
	cin >> value;

	// Prompt the user to enter their full name.
	cout << "\nHello, what is your name? ";

	// Get their name and store it in the string variable name
	getline(cin.ignore(), name);

	// Now display the following:
	//    The person's name. You must display the full name
	cout << "\nThank you, " << name << ".";

	//    The person's age
	cout << "\nYou are " << age << " years old, and you have";

	//    The money the person has. Display a dollar sign and two digits 
	cout << " $" << fixed << setprecision(2) << value << " in your pocket.";

	cout << "\n\nPress any key to continue...";
	cin.get();
}