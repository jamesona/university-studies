#include "Tests.h"
#include "List.h"
#include "Employee.h"
#include "SortedList.h"
#include "ListIterator.h"

int LL5() {
	cout << "==== Tests for LL5 ====" << endl;

	Employee e1("Fred", "Flintstone", 35, "8000BC");
	Employee e2("George", "Jetson", 35, "2407AD");
	Employee e3("Albert", "Einstein", 47, "1945");
	Employee e4("Baby", "Hitler", 2, "1904");
	Employee e5("Axe", "Cop", 30, "UVU#10458793");

	SortedList<Employee> employeeListByFirst(compareEmployeesByFirstName);
	employeeListByFirst.insert(e1);
	employeeListByFirst.insert(e2);
	employeeListByFirst.insert(e3);
	employeeListByFirst.insert(e4);
	employeeListByFirst.insert(e5);
	cout << "Employee List Sorted by First Name" << endl;
	ListIterator<Employee> it(employeeListByFirst);
	while (it.hasNext()) {
		cout << it.next() << endl;
	}
	cout << endl;

	//TODO repeat with a sorted list of the same employees by last name

	//TODO repeat with a sorted list of the same employees by age

	return 0;
};