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

Employee Employee::read(std::ifstream& infile)
{
	std::string line, value, number, name, address, phone, hours, wage;
	std::vector<std::string> values;

	getline(infile, line);
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

void Employee::write(std::ofstream& outfile)
{
	outfile << this->number() << ','
		<< this->name() << ','
		<< this->address() << ','
		<< this->phoneNumber() << ','
		<< this->hourlyWage() << ','
		<< this->hoursWorked()
		<< std::endl; 
}

void Employee::printCheck(Employee employee, std::string company, std::string bank, int width)
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

std::string centerText(int width, const std::string& str, char fill = ' ') {
	int len = str.length();
	if (width < len) { return str; }

	int diff = width - len;
	int pad1 = diff / 2;
	int pad2 = diff - pad1;
	return std::string(pad1, fill) + str + std::string(pad2, fill);
}