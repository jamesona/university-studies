#include "stdafx.h"
#include "HourlyEmployee.h"

Employee::Employee()
{
	const int _number = id_counter++;
	_name = "";
	_address = "";
	_phone = "";
}

Employee::Employee(
	int number = id_counter++,
	std::string employeeName = "John Doe",
	std::string employeeAddress = "123 Main St., Anytown, USA",
	std::string employeePhone = "(123) 456-789",
	double startingWage = 0,
	double hoursWorked = 0
	) {
	_number = number;
	_name = employeeName;
	_address = employeeAddress;
	_phone = employeePhone;
	_hourlyWage = startingWage;
	_hoursWorked = hoursWorked;
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
	outfile << this->number() << ','
		<< this->name() << ','
		<< this->address() << ','
		<< this->phoneNumber() << ','
		<< this->hourlyWage() << ','
		<< this->hoursWorked()
		<< std::endl;
}

void HourlyEmployee::printCheck(std::string company, std::string bank, int width)
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

	std::cout << "Hours Worked: " << std::fixed << std::setprecision(2) << employee.hoursWorked() << std::endl;
	std::cout << "Hourly Rate: " << std::fixed << std::setprecision(2) << employee.hourlyWage() << std::endl;
}

Employee* HourlyEmployee::readData(std::ifstream& infile)
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