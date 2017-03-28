#include "stdafx.h"
#include "Employee.h"

int Employee::id_counter = 0;
const int Employee::OVERTIME = 40; // 40 Hours needed to reach overtime
const double Employee::PAY_DIFFERENTIAL = 1.5; // Pay time-and-a-half for hours over 40
const double Employee::FED_TAX = 0.2; // Federal income tax; 20%
const double Employee::STATE_TAX = 0.075; // State income tax; 7.5%

Employee::Employee()
{
	const int _number = id_counter++;
	_name = "John Doe";
	_address = "123 Main St., Anytown, USA";
	_phone = "(123) 456-789";
	_hourlyWage = 0;
	_hoursWorked = 0;
}

Employee::Employee(
	std::string employeeName = "John Doe",
	std::string employeeAddress = "123 Main St., Anytown, USA",
	std::string employeePhone = "(123) 456-789",
	double startingWage = 0,
	double hoursWorked = 0
){
	const int _number = id_counter++;
	_name = employeeName;
	_address = employeeAddress;
	_phone = employeePhone;
	_hourlyWage = startingWage;
	_hoursWorked = hoursWorked;
}

Employee::~Employee()
{
}

int Employee::number()
{
	return _number;
}

std::string Employee::name()
{
	return _name;
}
std::string Employee::name(std::string newName)
{
	_name = newName;
	return _name;
}

std::string Employee::address()
{
	return _address;
}
std::string Employee::address(std::string newAddr)
{
	_address = newAddr;
	return _address;
}

std::string Employee::phoneNumber()
{
	return _phone;
}
std::string Employee::phoneNumber(std::string newPhone)
{
	_phone = newPhone;
	return _phone;
}

double Employee::hourlyWage()
{
	return _hourlyWage;
}
double Employee::hourlyWage(double newWage)
{
	_hourlyWage = newWage;
	return _hourlyWage;
}

double Employee::hoursWorked()
{
	return _hoursWorked;
}
double Employee::hoursWorked(double newHours)
{
	_hoursWorked = newHours;
	return _hoursWorked;
}

double Employee::addHours(double hours)
{
	_hoursWorked += hours;
	return _hoursWorked;
}

void Employee::resetHours()
{
	_hoursWorked = 0;
}

double Employee::grossPay()
{
	double grossPay = _hourlyWage * _hoursWorked;

	if (_hoursWorked > OVERTIME)
	{
		grossPay += (_hoursWorked - OVERTIME) * (_hourlyWage * PAY_DIFFERENTIAL);
	}

	return grossPay;
}

double Employee::federalTax()
{
	double grossPay = Employee::grossPay();
	return grossPay * FED_TAX;
}

double Employee::stateTax()
{
	double grossPay = Employee::grossPay();
	return grossPay * STATE_TAX;
}

double Employee::calcPay()
{
	double netPay = Employee::grossPay();

	netPay -= Employee::federalTax();
	netPay -= Employee::stateTax();

	return netPay;
}