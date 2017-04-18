#include "stdafx.h"
#include "SalariedEmployee.h"

Employee* SalariedEmployee::read(std::ifstream& infile)
{
	SalariedEmployee* emp;
	emp->readData(infile);
	return emp;
}

Employee* SalariedEmployee::readData(std::ifstream& infile)
{
	std::string line, value, number, name, address, phone, hours, wage;
	std::vector<std::string> values;

	getline(infile, line);

	if (line == "")
	{
		Employee null(-1);
		return null;
	}

	std::istringstream stream(line);
	for (std::string each; std::getline(stream, each, ','); values.push_back(each));

	number = values[0];
	name = values[1];
	address = values[2];
	phone = values[3];
	hours = values[4];
	wage = values[5];

	Employee newEmployee(stoi(number), name, address, phone, stof(wage), stof(hours));
	return newEmployee;
}

void SalariedEmployee::write(std::ofstream& outfile)
{
	outfile << getEmployeeNumber() << ','
		<< getName() << ','
		<< getAddress() << ','
		<< getPhone() << ','
		<< getWeeklySalary()
		<< std::endl;
}

void SalariedEmployee::printCheck(std::string company, std::string bank, int width)
{
	const std::string PAYTEXT = "Pay to the order of ";
	std::string name = employee.name(),
		wage = std::to_string(employee.calcPay());

	std::cout << centerText(width, company, '-') << std::endl << std::endl;

	std::cout << PAYTEXT << std::left
		<< std::setw(width - PAYTEXT.length() - name.length())
		<< std::setfill('.') << name << '$';

	std::cout << std::fixed << std::setprecision(2) << employee.calcPay() << std::endl << std::endl << std::endl;

	std::cout << bank << std::endl;
	std::cout << centerText(width, "", '-') << std::endl;

	std::cout << "Salary: " << std::fixed << std::setprecision(2) << employee.getWeeklySalary() << std::endl;
}
