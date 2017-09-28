// Author: Jameson Aranda
// Assignment: CS1410_Project_04_jaranda
// Instructor: Craig Sharp
// Class: CS 1410 -- 002
// Date Written: 3/7/2017 8:49:39 PM
// Description: 

// I declare that the following code was written by me or provided
// by the instructor for this project. I understand that copying source
// code from any other source constitutes cheating, and that I will receive 
// a zero on this project if I am found in violation of this policy. 

#include "stdafx.h"
#include "main.h"

using namespace std;

const string COMPANY_NAME = "FluffShuffle Electronics",
			 BANK_NAME = "United Bank of Eastern Orem";
const int JUSTIFY_WIDTH = 80;

string centerText(int width, const string& str, char fill = ' ') {
	int len = str.length();
	if (width < len) { return str; }

	int diff = width - len;
	int pad1 = diff / 2;
	int pad2 = diff - pad1;
	return string(pad1, fill) + str + string(pad2, fill);
}

void printCheck(Employee employee)
{
	const string PAYTEXT = "Pay to the order of ";
	string name = employee.name(), 
		   wage = to_string(employee.calcPay());

	cout << centerText(JUSTIFY_WIDTH, COMPANY_NAME, '-') << endl << endl;

	cout << PAYTEXT << left
		 << setw(JUSTIFY_WIDTH - PAYTEXT.length() - name.length())
		 << setfill('.') << name << '$';

	cout << fixed << setprecision(2) << employee.calcPay() << endl << endl << endl;

	cout << BANK_NAME << endl;
	cout << centerText(JUSTIFY_WIDTH, "", '-') << endl;

	cout << "Hours Worked: " << fixed << setprecision(2) << employee.hoursWorked() << endl;
	cout << "Hourly Rate: " << fixed << setprecision(2) << employee.hourlyWage() << endl;
}

int main()
{
	Employee myEmployee, defaultEmployee = Employee();

	defaultEmployee.hourlyWage(10);
	defaultEmployee.addHours(45);

	myEmployee = Employee("Jane Doe", "123 Other St.", "(980) 765-432", 12.5, 30);

	printCheck(defaultEmployee);

	cout << "\n\n\nPress any key to exit." << endl;

	cin.clear();
	cin.get();
	return 0;
}

