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

Employee* Employee::read(std::ifstream& infile)
{
	std::string line, value, number, name, address, phone, hours, wage;
	std::vector<std::string> values;

	getline(infile, line);

	if (line == "")
	{
		return nullptr;
	}

	std::istringstream stream(line);
	for (std::string each; std::getline(stream, each, ',');values.push_back(each));
	
	number = values[0];
	name = values[1];
	address = values[2];
	phone = values[3];
	hours = values[4];
	wage = values[5];

	Employee newEmployee(stoi(number), name, address, phone, stof(wage), stof(hours));
	return newEmployee;
}

void Employee::readData(std::ifstream& input, Employee emp)
{

}

std::string centerText(int width, const std::string& str, char fill = ' ') {
	int len = str.length();
	if (width < len) { return str; }

	int diff = width - len;
	int pad1 = diff / 2;
	int pad2 = diff - pad1;
	return std::string(pad1, fill) + str + std::string(pad2, fill);
}