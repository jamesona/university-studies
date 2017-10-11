struct Employee {
	string fname;
	string lname;
	size_t age;
	string id;

	Employee(string fname, string lname, size_t age, string id) {
		this->fname = fname;
		this->lname = lname;
		this->age = age;
		this->id = id;
	}

	//friend ostream& operator<<(ostream& os, const Employee& emp) {
	//	os << emp.fname << " " << emp.lname << ", " << emp.age << ", id is " << emp.id;
	//	return os;
	//}
};

int compareEmployeesByFirstName(Employee a, Employee b) {
	return 0;
}

int compareEmployeesByLastName(Employee a, Employee b) {
	return 0;
}

int compareEmployeesByAge(Employee a, Employee b) {
	return 0;
}