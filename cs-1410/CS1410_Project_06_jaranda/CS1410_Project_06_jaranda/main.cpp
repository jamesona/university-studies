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

int main()
{
	string fileName = "employees.csv";
	vector<Employee> employees;

	cout << "This program has two options:" << endl;
	cout << "1 - Create a data file, or" << endl;
	cout << "2 - Read data from a file and print paychecks." << endl;

	if (Prompt::getChoice("Please enter (1) to create a file or (2) to print checks", '1', '2'))
	{
		// create a file
		ofstream employeeFile;
		employeeFile.open(fileName);

		Employee joe(37, "Joe Brown", "123 Main St.", "123-6788", 45, 10.00);
		Employee sam(21, "Sam Jones", "45 East State", "661-9000", 30, 12.00);
		Employee mary(15, "Mary Smith", "12 High Street", "401-8900", 40, 15.00);
		
		employees.push_back(joe);
		employees.push_back(sam);
		employees.push_back(mary);

		for (vector<Employee>::iterator it = employees.begin(); it != employees.end(); ++it)
		{
			Employee employee = *it;
			cout << "Writing #" << employee.number() << ':' << employee.name() << endl;
			employee.write(employeeFile);
		}

		cout << "Writing to file complete!" << endl;
	}
	else
	{
		// load file & print checks
		cout << "Please enter the name of the employee file: ";
		cin.ignore();
		cin >> fileName;
		
		ifstream inputFile(fileName);
		if (inputFile.is_open())
		{
			while (!inputFile.eof()) {
				employees.push_back(Employee::read(inputFile));
			}
		}

		for (vector<Employee>::iterator it = employees.begin(); it != employees.end(); ++it)
		{
			Employee employee = *it;
			Employee::printCheck(employee, COMPANY_NAME, BANK_NAME, JUSTIFY_WIDTH);
		}
	}
	
	cin.ignore();
	cout << "\n\n\nPress any key to exit." << endl;
	cin.clear();
	cin.get();
	return 0;
}

