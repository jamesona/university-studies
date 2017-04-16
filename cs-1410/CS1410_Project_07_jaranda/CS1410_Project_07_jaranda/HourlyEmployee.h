/* 
.....................................................
....+-------------------------------------------+....
....|              HourlyEmployee               |....
....+-------------------------------------------+....
....| - _number : int                           |....
....| - _name : string                          |....
....| - _address : string                       |....
....| - _phoneNumber : string                   |....
....| - _hourlyWage : double                    |....
....| - _hoursWorked : double                   |....
....+-------------------------------------------+....
....| - override readData() : void              |....
....| + getHourlyWage() : double                |....
....| + getHoursWorked() : double               |....
....| + override write() : void                 |....
....| + override calcPay() : double             |....
....| + override printCheck() : void            |....
....+-------------------------------------------+....
.....................................................
*/

#include "stdafx.h"
#include "Employee.h"

class HourlyEmployee : public Employee
{
private:
	double _hourlyWage;
	double _hoursWorked;

	void readData();

public:
	~Employee();

	// Function Name: Employee::getHourlyWage
	// Purpose: Return the employee's current hourly wage
	// Parameters: none
	// Returns: double hourlyWage
	// Pre-conditions: none
	// Post-conditions: none
	double getHourlyWage();

	// Function Name: Employee::getHoursWorked
	// Purpose: Return number of hours worked this week
	// Parameters: none
	// Returns: double hoursWorked
	// Pre-conditions: none
	// Post-conditions: none
	double getHoursWorked();

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