#include "stdafx.h"
#include "SalariedEmployee.h"

SalariedEmployee::SalariedEmployee()
{

}

SalariedEmployee::SalariedEmployee(int number, std::string name, std::string address, std::string phone, double weekly)
{
	_number = number;
	_name = name;
	_address = address;
	_phone = phone;
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

	getline(infile, line);

	if (line == "")
	{
		return;
	}

	std::istringstream stream(line);
	for (std::string each; std::getline(stream, each, ','); values.push_back(each));

	//number = stoi(values[0]);
	//name = values[1];
	//address = values[2];
	//phone = values[3];
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
	return 0;
}

SalariedEmployee::~SalariedEmployee()
{

}