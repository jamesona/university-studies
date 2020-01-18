#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include "Employee.h"

void display(std::list<char> list) {
	for (std::list<char>::iterator it = list.begin(); it != list.end(); ++it)
		std::cout << *it;
}

void reverseDisplay(std::list<char> list) {
	for (std::list<char>::reverse_iterator rit = list.rbegin(); rit != list.rend(); ++rit)
		std::cout << *rit;
}

bool compareChars(const char& a, const char& b) {
	char A = toupper(a);
	char B = toupper(b);
	if (A < B) return true;
	return false;
}

bool compareStrings(const std::string& sA, const std::string& sB) {
	unsigned i = 0;
	char a, A, b, B;

	while (i < sA.length() && i < sB.length()) {
		a = sA[i], A = toupper(a), b = sB[i], B = toupper(b);
		if (A < B) return true;
		if (a < b) return true;
		if (B < A) return false;
		if (b < a) return false;
		i++;
	}

	return false;
}

bool compareEmployeesByFirstName(Employee a, Employee b) {
	return compareStrings(a.fname, b.fname);
}

bool compareEmployeesByLastName(Employee a, Employee b) {
	return compareStrings(a.lname, b.lname);
}

bool compareEmployeesByAge(Employee a, Employee b) {
	if (a.age < b.age) return true;
	return false;
}

int main() {
	std::cout << "==== Tests for LL1 ====" << std::endl;
	std::list<char> list1;
	list1.push_back('I');
	list1.push_front('P');
	list1.push_front('U');
	list1.push_back('L');
	list1.push_back('S');
	list1.push_front('P');
	display(list1);
	std::cout << std::endl;
	reverseDisplay(list1);
	std::cout << std::endl;

	std::list<char> list2;
	list2.push_front('A');
	list2.push_back('L');
	list2.push_front('P');
	list2.push_back('S');
	display(list2);
	std::cout << std::endl;
	reverseDisplay(list2);
	std::cout << std::endl;

	std::cout << "==== Tests for LL2 ====" << std::endl;

	std::stack<char> stack;
	stack.push('L');
	stack.push('I');
	stack.push('V');
	stack.push('E');
	std::cout << "I'm feeling ";
	std::cout << stack.top();
	stack.pop();
	std::cout << stack.top();
	stack.pop();
	std::cout << stack.top();
	stack.pop();
	std::cout << stack.top();
	stack.pop();
	std::cout << "." << std::endl << std::endl;

	std::queue<char> q;
	q.push('R');
	q.push('A');
	q.push('T');
	std::cout << "Must have been that ";
	std::cout << q.front();
	q.pop();
	std::cout << q.front();
	q.pop();
	std::cout << q.front();
	q.pop();
	std::cout << " I ate." << std::endl << std::endl;

	std::cout << "Here's how many letters are left on the stack: " << stack.size() << std::endl;
	std::cout << "And here's how many letters are left on the q: " << q.size() << std::endl;

	std::cout << "==== Tests for LL3 ====" << std::endl;

	std::list<char> sortedList;

	sortedList.push_back('A');
	sortedList.push_back('e');
	sortedList.push_back('g');
	sortedList.push_back('e');
	sortedList.push_back('a');
	sortedList.push_back('n');
	sortedList.push_back('A');
	sortedList.push_back('n');
	sortedList.push_back('i');
	sortedList.push_back('m');
	sortedList.push_back('a');
	sortedList.push_back('l');
	sortedList.push_back('L');
	sortedList.push_back('O');
	sortedList.push_back('V');
	sortedList.push_back('E');
	sortedList.push_back('R');

	sortedList.sort(compareChars);

	for (auto l : sortedList) {
		std::cout << l;
	}

	std::cout << std::endl;

	std::cout << "==== Tests for LL5 ====" << std::endl;

	Employee e1("Fred", "Flintstone", 35, "8000BC");
	Employee e2("George", "Jetson", 35, "2407AD");
	Employee e3("Albert", "Einstein", 47, "1945");
	Employee e4("Baby", "Hitler", 2, "1904");
	Employee e5("Axe", "Cop", 30, "UVU#10458793");

	std::list<Employee> employeeListByFirst;
	employeeListByFirst.push_back(e1);
	employeeListByFirst.push_back(e2);
	employeeListByFirst.push_back(e3);
	employeeListByFirst.push_back(e4);
	employeeListByFirst.push_back(e5);

	employeeListByFirst.sort(compareEmployeesByFirstName);

	std::cout << "Employee List Sorted by First Name" << std::endl;
	std::list<Employee>::iterator it = employeeListByFirst.begin();
	while (it != employeeListByFirst.end()) {
		std::cout << *it++ << std::endl;
	}
	std::cout << std::endl;

	std::list<Employee> employeeListByLast;
	employeeListByLast.push_back(e1);
	employeeListByLast.push_back(e2);
	employeeListByLast.push_back(e3);
	employeeListByLast.push_back(e4);
	employeeListByLast.push_back(e5);
	employeeListByLast.sort(compareEmployeesByLastName);

	std::cout << "Employee List Sorted by Last Name" << std::endl;
	it = employeeListByLast.begin();
	while (it != employeeListByLast.end()) {
		std::cout << *it++ << std::endl;
	}
	std::cout << std::endl;
	
	std::list<Employee> employeeListByAge;
	employeeListByAge.push_back(e1);
	employeeListByAge.push_back(e2);
	employeeListByAge.push_back(e3);
	employeeListByAge.push_back(e4);
	employeeListByAge.push_back(e5);
	employeeListByAge.sort(compareEmployeesByAge);

	std::cout << "Employee List Sorted by Age" << std::endl;
	it = employeeListByAge.begin();
	while (it != employeeListByAge.end()) {
		std::cout << *it++ << std::endl;
	}
	std::cout << std::endl;

	std::cout << std::endl << "Press return to quit...";
	getchar();
	return 0;
}
