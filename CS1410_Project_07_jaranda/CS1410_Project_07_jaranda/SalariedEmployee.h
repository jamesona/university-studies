/* 
.....................................................
....+-------------------------------------------+....
....|             SalariedEmployee              |.....
...+-------------------------------------------+....
....| - _number : int                           |....
....| - _name : string                          |....
....| - _address : string                       |....
....| - _phoneNumber : string                   |....
....| - _weeklySalary: double                   |....
....+-------------------------------------------+....
....| + getWeeklySalary() : double              |....
....| + override write() : void                 |....
....| + override calcPay() : double             |....
....| + override printCheck() : void            |....
....+-------------------------------------------+....
.....................................................
*/


#include "stdafx.h"
#include "Employee.h"

class SalariedEmployee : public Employee
{
private:
	double _weeklySalary;

	// Function Name: SalariedEmployee::readData
	// Purpose: Read employee data from file
	// Parameters: none
	// Returns: none
	// Pre-conditions: none
	// Post-conditions: none
	void readData(std::ifstream&);

public:
	SalariedEmployee();

	SalariedEmployee(int, std::string, std::string, std::string, double);

	~SalariedEmployee();

	static Employee* SalariedEmployee::read(std::ifstream&);

	// Function Name: Employee::getWeeklySalary
	// Purpose: Return total pay for the week
	// Parameters: none
	// Returns: double salary
	// Pre-conditions: none
	// Post-conditions: none
	double getWeeklySalary();

	// Function Name: Employee::write
	// Purpose: Write employee data to file
	// Parameters: none
	// Returns: none
	// Pre-conditions: none
	// Post-conditions: none
	void write(std::ofstream&);

	// Function Name: Employee::calcPay
	// Purpose: Calculate employee's gross pay for the period, before tax
	// Parameters: none
	// Returns: double grossPay
	// Pre-conditions: none
	// Post-conditions: none
	double calcPay();

	// Function Name: Employee::printCheck
	// Purpose: Prints itemized paycheck for employee
	// Parameters: Employee employee, string company_name, string bank_name, int check_width
	// Returns: none
	// Pre-conditions: none
	// Post-conditions: none
	void printCheck(std::string, std::string, int);
};