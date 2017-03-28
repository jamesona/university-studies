/* Employee
================================
	- id : int
	- name : string
	- address : string
	- phoneNumber : string
	- hourlyWage : double
	- hoursWorked : double
================================
	+ id() : int
	+ name(newName : string) : string
	+ address(newAddress : string) : string
	+ phoneNumber(newPhone : string) : string
	+ hourlyWage(newWage : double) : double
	+ hoursWorked(newHours : double) : double
	+ addHours(hours : double) : double
	+ resetHours() : void
	+ calcPay() : double
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
	double _hourlyWage;
	double _hoursWorked;

public:
	Employee();
	Employee(
		int number,
		std::string employeeName,
		std::string employeeAddress,
		std::string employeePhone,
		double startingWage,
		double hoursWorked
		);
	~Employee();

	static const int OVERTIME;
	static const double PAY_DIFFERENTIAL;
	static const double FED_TAX;
	static const double STATE_TAX;

	// Function Name: Employee::read
	// Purpose: Generate a new Employee object from file
	// Parameters: ifstream&
	// Returns: Employee
	// Pre-conditions: none
	// Post-conditions: none
	static Employee read(std::ifstream&);

	
	// Function Name: Employee::write
	// Purpose: Write employee object to file
	// Parameters: ofstream&
	// Returns: none
	// Pre-conditions: none
	// Post-conditions: none
	void write(std::ofstream&);

	// Function Name: Employee::printCheck
	// Purpose: Prints itemized paycheck for employee
	// Parameters: Employee employee, string company_name, string bank_name, int check_width
	// Returns: none
	// Pre-conditions: none
	// Post-conditions: none
	static void printCheck(Employee, std::string, std::string, int);
	
	// Function Name: Employee::number
	// Purpose: Return the unique ID number of the employee
	// Parameters: none
	// Returns: int number
	// Pre-conditions: none
	// Post-conditions: none
	int number();
	
	// Function Name: Employee::name
	// Purpose: Return the name of the employee
	// Parameters: none
	// Returns: string name
	// Pre-conditions: none
	// Post-conditions: none
	std::string name();

	// Function Name: Employee::name
	// Purpose: Change the name of the employee
	// Parameters: string newName
	// Returns: string name
	// Pre-conditions: none
	// Post-conditions: none
	std::string name(std::string newName);
	
	// Function Name: Employee::address
	// Purpose: Return the address of the employee
	// Parameters: none
	// Returns: string address
	// Pre-conditions: none
	// Post-conditions: none
	std::string address();

	// Function Name: Employee::address
	// Purpose: Set the address of the employee
	// Parameters: string newAddress
	// Returns: address
	// Pre-conditions: none
	// Post-conditions: none
	std::string address(std::string newAddr);
	
	// Function Name: Employee::phoneNumber
	// Purpose: Return the phone number of the employee
	// Parameters: none
	// Returns: string phoneNumber
	// Pre-conditions: none
	// Post-conditions: none
	std::string phoneNumber();

	// Function Name: Employee::phoneNumber
	// Purpose: Set the phone number of the employee
	// Parameters: string newPhone
	// Returns: string phoneNumber
	// Pre-conditions: none
	// Post-conditions: none
	std::string phoneNumber(std::string newPhone);
	
	// Function Name: Employee::hourlyWage
	// Purpose: Return the employee's current hourly wage
	// Parameters: none
	// Returns: double hourlyWage
	// Pre-conditions: none
	// Post-conditions: none
	double hourlyWage();

	// Function Name: Employee::hourlyWage
	// Purpose: Set the employee's hourly wage
	// Parameters: double newWage
	// Returns: double hourlyWage
	// Pre-conditions: none
	// Post-conditions: none
	double hourlyWage(double newWage);

	// Function Name: Employee::hoursWorked
	// Purpose: Return number of hours worked this week
	// Parameters: none
	// Returns: double hoursWorked
	// Pre-conditions: none
	// Post-conditions: none
	double hoursWorked();

	// Function Name: Employee::hoursWorked
	// Purpose: Set hours worked this week; see Employee::addHours and Employee::resetHours
	// Parameters: double newHours
	// Returns: double hoursWorked
	// Pre-conditions: none
	// Post-conditions: none
	double hoursWorked(double newHours);

	// Function Name: Employee::addHours
	// Purpose: Add hours to employee's weekly total
	// Parameters: double hours
	// Returns: double hoursWorked
	// Pre-conditions: none
	// Post-conditions: none
	double addHours(double hours);

	// Function Name: Employee::resetHours
	// Purpose: Reset (zero-out) employee's total hours for the week
	// Parameters: none
	// Returns: none
	// Pre-conditions: none
	// Post-conditions: none
	void resetHours();

	// Function Name: Employee::grossPay
	// Purpose: Calculate employee's gross pay for the period, before tax
	// Parameters: none
	// Returns: double netPay
	// Pre-conditions: none
	// Post-conditions: none
	double grossPay();

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

	// Function Name: Employee::calcPay
	// Purpose: Calculate employee's net pay for the period, after tax
	// Parameters: none
	// Returns: double netPay
	// Pre-conditions: none
	// Post-conditions: none
	double calcPay();
};

// Function Name: centerText
// Purpose: Centers input text using pad characters
// Parameters: int width, string str, char fill
// Returns: string text
// Pre-conditions: none
// Post-conditions: none
std::string centerText(int width, const std::string& str, char fill);