#include <iostream>
using namespace std;

struct Node {
	char value;
	Node* prev = nullptr;
	Node* next = nullptr;

	Node(char val) {
		value = val;
	}

	bool hasNext() {
		return next != nullptr;
	}

	bool hasPrev() {
		return prev != nullptr;
	}

	void display() {
		cout << value;
	}
};