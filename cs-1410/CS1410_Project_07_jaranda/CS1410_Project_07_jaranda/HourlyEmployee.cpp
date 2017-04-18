#include "stdafx.h"
#include "HourlyEmployee.h"

HourlyEmployee::HourlyEmployee()
{

}

HourlyEmployee::HourlyEmployee(int number, std::string name, std::string address, std::string phone, double wage, double hours)
{
	_number = number;
	_name = name;
	_address = address;
	_phone = phone;
	_hourlyWage = wage;
	_hoursWorked = hours;
}

Employee* HourlyEmployee::read(std::ifstream& infile)
{
	HourlyEmployee* emp = new HourlyEmployee;
	emp->readData(infile);
	return emp;
}

void HourlyEmployee::readData(std::ifstream& infile)
{
	std::string line;
	std::vector<std::string> values;

	std::getline(infile, line);

	if (line == "")
	{
		return;
	}

	std::istringstream stream(line);
	for (std::string each; std::getline(stream, each, ','); values.push_back(each));
	//_number = stoi(values[0]);
	//_name = values[1];
	//_address = values[2];
	//_phone = values[3];
	//_hours = stof(values[4]);
	//_wage = stof(values[5]);
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

double HourlyEmployee::calcPay()
{
	return 0;
}

HourlyEmployee::~HourlyEmployee()
{

}