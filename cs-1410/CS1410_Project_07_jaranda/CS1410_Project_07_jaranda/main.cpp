// Author: Jameson Aranda
// Assignment: CS1410_Project_07_jaranda
// Instructor: Craig Sharp
// Class: CS 1410 -- 002
// Date Written: 4/15/2017 3:34:40 PM
// Description: 

// I declare that the following code was written by me or provided
// by the instructor for this project. I understand that copying source
// code from any other source constitutes cheating, and that I will receive 
// a zero on this project if I am found in violation of this policy.

#include "stdafx.h"
#include "Prompt.h"
#include "HourlyEmployee.h"
#include "SalariedEmployee.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

const string COMPANY_NAME = "FluffShuffle Electronics",
			BANK_NAME = "United Bank of Eastern Orem",
			EMPLOYEE_FILE = "employees.txt";
const int JUSTIFY_WIDTH = 80;

void promptExit()
{
	cin.ignore();
	cout << "\n\n\nPress any key to exit." << endl;
	cin.clear();
	cin.get();
}

void initializeEmployees(vector<Employee*> *employees)
{
	employees->push_back(new HourlyEmployee(1, "H. Potter", "Privet Drive", "201-9090", 40, 12.00));
	employees->push_back(new SalariedEmployee(2, "A. Dumbledore", "Hogwarts", "803-1230", 1200));
	employees->push_back(new HourlyEmployee(3, "R. Weasley", "The Burrow", "892-2000", 40, 10.00));
	employees->push_back(new SalariedEmployee(4, "R. Hagrid", "Hogwarts", "910-8765", 1000));
}

ofstream *initializeFile(string filename)
{
	// create a file
	ofstream* file;
	file = new ofstream(filename);

	try {
		if (!file)
			throw runtime_error("Couldn't open file for writing!");
	}
	catch (const exception& e) {
		cout << e.what();
		promptExit();
		return nullptr;
	}

	return file;
}

void writeFile(ofstream *filePtr, vector<Employee*> *employees)
{
	vector<Employee*>::iterator employee;

	for (employee = employees->begin(); employee != employees->end(); ++employee)
	{
		Employee* thisEmployee = *employee;
		string name = thisEmployee->getName();
		cout << "writing " << name << endl;
		thisEmployee->write(*filePtr);
	}

	cout << "Writing to file complete!" << endl;
}

void readFile(vector<Employee*> &employees)
{
	string fileName;
	
	cout << "Please enter the name of the employee file: ";
	cin.ignore();
	cin >> fileName;

	ifstream infile(fileName);
	
	try {
		if (!infile)
			throw runtime_error("Couldn't read file \"" + fileName + "\"");
	}
	catch (const exception& e) {
		cout << e.what();
		promptExit();
		return;
	}

	employees.push_back(HourlyEmployee::read(infile));
	employees.push_back(SalariedEmployee::read(infile));
	employees.push_back(HourlyEmployee::read(infile));
	employees.push_back(SalariedEmployee::read(infile));
}

void printChecks(vector<Employee*> &employees)
{
	vector<Employee*>::iterator employee;
	for (employee = employees.begin(); employee != employees.end(); ++employee)
	{
		Employee *thisEmployee = *employee;
		thisEmployee->printCheck(COMPANY_NAME, BANK_NAME, JUSTIFY_WIDTH);
	}
}

int main()
{
	vector<Employee*> employees;

	cout << "This program has two options:" << endl;
	cout << "1 - Create a data file, or" << endl;
	cout << "2 - Read data from a file and print paychecks." << endl;

	if (Prompt::getChoice("Please enter (1) to create a file or (2) to print checks", '1', '2'))
	{
		initializeEmployees(&employees);
		ofstream *file = initializeFile(EMPLOYEE_FILE);
		writeFile(file, &employees);
	}
	else
	{
		readFile(employees);
		printChecks(employees);
	}

	promptExit();
	return 0;
}

