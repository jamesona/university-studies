/* 
.....................................................
....+-------------------------------------------+....
....|                 Employee                  |....
....+-------------------------------------------+....
....| - id_number : int         <<static>>      |....
....+-------------------------------------------+....
....| - virtual void readData() = 0             |....
....| + getEmployeeNumber() : int               |....
....| + getName() : string                      |....
....| + getAddress() : string                   |....
....| + getPhone() : string                     |....
....| + Employee* read(ifstream&)   <<static>>  |....
....| + virtual void write(ofstream&) = 0       |....
....| + virtual double calcPay() = 0            |....
....| + virtual printCheck() = 0                |....
....| + virtual ~Employee()                     |....
....+-------------------------------------------+....
.....................................................
*/


#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>

class Employee
{
private:
	static int id_counter;
	int _number;
	std::string _name;
	std::string _address;
	std::string _phone;

	// Function Name: Employee::readData
	// Purpose: Read employee data from file
	// Parameters: none
	// Returns: none
	// Pre-conditions: none
	// Post-conditions: none
	virtual void readData(std::ifstream&, Employee&) = 0;

public:
	static const int OVERTIME;
	static const double PAY_DIFFERENTIAL;
	static const double FED_TAX;
	static const double STATE_TAX;

	Employee();

	Employee(
		int number,
		std::string employeeName,
		std::string employeeAddress,
		std::string employeePhone,
		double startingWage,
		double hoursWorked
		);

	virtual ~Employee();

	static Employee* read(std::ifstream&);

	// Function Name: Employee::getEmployeeNumber
	// Purpose: Return the unique ID number of the employee
	// Parameters: none
	// Returns: int number
	// Pre-conditions: none
	// Post-conditions: none
	int getEmployeeNumber();
	
	// Function Name: Employee::getName
	// Purpose: Return the name of the employee
	// Parameters: none
	// Returns: string name
	// Pre-conditions: none
	// Post-conditions: none
	std::string getName();
	
	// Function Name: Employee::getAddress
	// Purpose: Return the address of the employee
	// Parameters: none
	// Returns: string address
	// Pre-conditions: none
	// Post-conditions: none
	std::string getAddress();
	
	// Function Name: Employee::getPhone
	// Purpose: Return the phone number of the employee
	// Parameters: none
	// Returns: string phoneNumber
	// Pre-conditions: none
	// Post-conditions: none
	std::string getPhone();

	// Function Name: Employee::calcPay
	// Purpose: Calculate employee's net pay for the period, after tax
	// Parameters: none
	// Returns: double netPay
	// Pre-conditions: none
	// Post-conditions: none
	virtual double calcPay() = 0;
	
	// Function Name: Employee::printCheck
	// Purpose: Prints itemized paycheck for employee
	// Parameters: Employee employee, string company_name, string bank_name, int check_width
	// Returns: none
	// Pre-conditions: none
	// Post-conditions: none
	virtual void printCheck(std::string, std::string, int) = 0;

	// Function Name: Employee::write
	// Purpose: Write employee data to file
	// Parameters: none
	// Returns: double hoursWorked
	// Pre-conditions: none
	// Post-conditions: none
	virtual void write(std::ofstream&) = 0;

	// Function Name: Employee::grossPay
	// Purpose: Calculate employee's net pay for the period, after tax
	// Parameters: none
	// Returns: double netPay
	// Pre-conditions: none
	// Post-conditions: none
	double netPay();

	// Function Name: Employee::federalTax
	// Purpose: Calculate federal tax deduction for pay period
	// Parameters: none
	// Returns: double netPay
	// Pre-conditions: none
	// Post-conditions: none
	double federalTax();

	// Function Name: Employee::stateTax
	// Purpose: Calculate state tax deduction for pay period
	// Parameters: none
	// Returns: double netPay
	// Pre-conditions: none
	// Post-conditions: none
	double stateTax();
};

// Function Name: centerText
// Purpose: Centers input text using pad characters
// Parameters: int width, string str, char fill
// Returns: string text
// Pre-conditions: none
// Post-conditions: none
std::string centerText(int width, const std::string& str, char fill);