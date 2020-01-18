#include <string>

struct Employee {
	std::string fname;
	std::string lname;
	size_t age;
	std::string id;

	Employee() {};

	Employee(std::string fname, std::string lname, size_t age, std::string id) {
		this->fname = fname;
		this->lname = lname;
		this->age = age;
		this->id = id;
	}

	friend std::ostream& operator<<(std::ostream& os, const Employee& emp) {
		os << emp.fname << " " << emp.lname << ", " << emp.age << ", id is " << emp.id;
		return os;
	}
};