#include "stdafx.h"
#include "SalariedEmployee.h"

SalariedEmployee::SalariedEmployee()
{

}

SalariedEmployee::SalariedEmployee(int number, std::string name, std::string address, std::string phone, double weekly)
{
	Employee::_number = number;
	Employee::_name = name;
	Employee::_address = address;
	Employee::_phone = phone;
	_weeklySalary = weekly;
}

Employee* SalariedEmployee::read(std::ifstream& infile)
{
	SalariedEmployee* emp = new SalariedEmployee;
	emp->readData(infile);
	return emp;
}

void SalariedEmployee::readData(std::ifstream& infile)
{
	std::string line;
	std::vector<std::string> values;

	for (int i = 0; i < 5; i++)
	{
		std::getline(infile, line);
		if (line == "")
		{
			return;
		}
		values.push_back(line);
	}

	Employee::_number = stoi(values[0]);
	Employee::_name = values[1];
	Employee::_address = values[2];
	Employee::_phone = values[3];
	_weeklySalary = stof(values[4]);
}

void SalariedEmployee::write(std::ofstream& outfile)
{
	outfile << getEmployeeNumber() << '\n'
		<< getName() << '\n'
		<< getAddress() << '\n'
		<< getPhone() << '\n'
		<< getWeeklySalary() << '\n';
}

double SalariedEmployee::getWeeklySalary()
{
	return _weeklySalary;
}

void SalariedEmployee::printCheck(std::string company, std::string bank, int width)
{
	const std::string PAYTEXT = "Pay to the order of ";
	std::string name = this->getName(),
		wage = std::to_string(this->calcPay());

	std::cout << centerText(width, company, '-') << std::endl << std::endl;

	std::cout << PAYTEXT << std::left
		<< std::setw(width - PAYTEXT.length() - name.length())
		<< std::setfill('.') << name << '$';

	std::cout << std::fixed << std::setprecision(2) << this->calcPay() << std::endl << std::endl << std::endl;

	std::cout << bank << std::endl;
	std::cout << centerText(width, "", '-') << std::endl;

	std::cout << "Salary: " << std::fixed << std::setprecision(2) << this->getWeeklySalary() << std::endl;
}

double SalariedEmployee::calcPay()
{
	double grossPay = getWeeklySalary();
	return Employee::netPay(grossPay);
}

SalariedEmployee::~SalariedEmployee()
{

}