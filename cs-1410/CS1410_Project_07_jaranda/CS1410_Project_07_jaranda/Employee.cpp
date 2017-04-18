#include "stdafx.h"
#include "Employee.h"

int Employee::id_counter = 0;
const int Employee::OVERTIME = 40; // 40 Hours needed to reach overtime
const double Employee::PAY_DIFFERENTIAL = 1.5; // Pay time-and-a-half for hours over 40
const double Employee::FED_TAX = 0.2; // Federal income tax; 20%
const double Employee::STATE_TAX = 0.075; // State income tax; 7.5%

Employee::~Employee()
{

}

int Employee::getEmployeeNumber()
{
	return _number;
}
std::string Employee::getName()
{
	return _name;
}
std::string Employee::getAddress()
{
	return _address;
}
std::string Employee::getPhone()
{
	return _phone;
}

std::string centerText(int width, const std::string& str, char fill = ' ') {
	int len = str.length();
	if (width < len) { return str; }

	int diff = width - len;
	int pad1 = diff / 2;
	int pad2 = diff - pad1;
	return std::string(pad1, fill) + str + std::string(pad2, fill);
}