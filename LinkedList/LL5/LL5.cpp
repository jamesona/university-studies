#include "Tests.h"
#include "List.h"
#include "Employee.h"
#include "SortedList.h"
#include "ListIterator.h"
#include "CompareChars.h"

int compareStrings(string sA, string sB) {
	int i = 0;
	char a, A, b, B;
	
	while (i < sA.length() && i < sB.length()) {
		a = sA[i], A = toupper(a), b = sB[i], B = toupper(b);
		if (A < B) return -1;
		if (B < A) return 1;
		if (a < b) return -1;
		if (b < a) return 1;
		i++;
	}

	return 0;
}

int compareEmployeesByFirstName(Employee a, Employee b) {
	return compareStrings(a.fname, b.fname);
}

int compareEmployeesByLastName(Employee a, Employee b) {
	return compareStrings(a.lname, b.lname);
}

int compareEmployeesByAge(Employee a, Employee b) {
	if (a.age < b.age) return -1;
	if (b.age < a.age) return 1;
	return 0;
}

int LL5() {
	cout << "==== Tests for LL5 ====" << endl;

	Employee e1("Fred", "Flintstone", 35, "8000BC");
	Employee e2("George", "Jetson", 35, "2407AD");
	Employee e3("Albert", "Einstein", 47, "1945");
	Employee e4("Baby", "Hitler", 2, "1904");
	Employee e5("Axe", "Cop", 30, "UVU#10458793");
	ListIterator<Employee>* it;

	SortedList<Employee> employeeListByFirst(compareEmployeesByFirstName);
	employeeListByFirst.insert(e1);
	employeeListByFirst.insert(e2);
	employeeListByFirst.insert(e3);
	employeeListByFirst.insert(e4);
	employeeListByFirst.insert(e5);
	cout << "Employee List Sorted by First Name" << endl;
	it = new ListIterator<Employee>(employeeListByFirst);
	while (it->hasNext()) {
		cout << it->next() << endl;
	}
	cout << endl;

	SortedList<Employee> employeeListByLast(compareEmployeesByLastName);
	employeeListByLast.insert(e1);
	employeeListByLast.insert(e2);
	employeeListByLast.insert(e3);
	employeeListByLast.insert(e4);
	employeeListByLast.insert(e5);
	cout << "Employee List Sorted by Last Name" << endl;
	it = new ListIterator<Employee>(employeeListByLast);
	while (it->hasNext()) {
		cout << it->next() << endl;
	}
	cout << endl;

	SortedList<Employee> employeeListByAge(compareEmployeesByAge);
	employeeListByAge.insert(e1);
	employeeListByAge.insert(e2);
	employeeListByAge.insert(e3);
	employeeListByAge.insert(e4);
	employeeListByAge.insert(e5);
	cout << "Employee List Sorted by Age" << endl;
	it = new ListIterator<Employee>(employeeListByAge);
	while (it->hasNext()) {
		cout << it->next() << endl;
	}
	cout << endl;

	return 0;
};