#include "stdafx.h"
#include "HourlyEmployee.h"

Employee* HourlyEmployee::read(std::ifstream& infile)
{
	HourlyEmployee* emp;
	emp->readData(infile);
	return emp;
}

void HourlyEmployee::readData(std::ifstream& infile)
{
	std::string line, value, number, name, address, phone, hours, wage;
	std::vector<std::string> values;

	getline(infile, line);

	if (line == "")
	{
		return;
	}

	std::istringstream stream(line);
	for (std::string each; std::getline(stream, each, ','); values.push_back(each));
	number = values[0];
	name = values[1];
	address = values[2];
	phone = values[3];
	hours = values[4];
	wage = values[5];

	HourlyEmployee newEmployee(stoi(number), name, address, phone, stof(wage), stof(hours));
	emp = newEmployee;
}

double HourlyEmployee::getHourlyWage()
{
	return _hourlyWage;
}

double HourlyEmployee::getHoursWorked()
{
	return _hoursWorked;
}

void HourlyEmployee::write(std::ofstream& outfile)
{
	outfile << getEmployeeNumber() << ','
		<< getName() << ','
		<< getAddress() << ','
		<< getPhone() << ','
		<< getHourlyWage() << ','
		<< getHoursWorked()
		<< std::endl;
}

void HourlyEmployee::printCheck(std::string company, std::string bank, int width)
{
	const std::string PAYTEXT = "Pay to the order of ";
	std::string name = getName(),
		wage = std::to_string(calcPay());

	std::cout << centerText(width, company, '-') << std::endl << std::endl;

	std::cout << PAYTEXT << std::left
		<< std::setw(width - PAYTEXT.length() - name.length())
		<< std::setfill('.') << name << '$';

	std::cout << std::fixed << std::setprecision(2) << calcPay() << std::endl << std::endl << std::endl;

	std::cout << bank << std::endl;
	std::cout << centerText(width, "", '-') << std::endl;

	std::cout << "Hours Worked: " << std::fixed << std::setprecision(2) << getHoursWorked() << std::endl;
	std::cout << "Hourly Rate: " << std::fixed << std::setprecision(2) << getHourlyWage() << std::endl;
}

