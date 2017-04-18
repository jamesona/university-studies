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
#include "HourlyEmployee.h"
#include "SalariedEmployee.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

int main()
{
	vector<Employee *> employees;

	employees.push_back(new HourlyEmployee(1, "H. Potter", "Privet Drive", "201-9090", 40, 12.00));
	employees.push_back(new SalariedEmployee(2, "A. Dumbledore", "Hogwarts", "803-1230", 1200));
	employees.push_back(new HourlyEmployee(3, "R. Weasley", "The Burrow", "892-2000", 40, 10.00));
	employees.push_back(new SalariedEmployee(4, "R. Hagrid", "Hogwarts", "910-8765", 1000));

	return 0;
}

