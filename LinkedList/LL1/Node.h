#include <iostream>
using namespace std;

struct Node {
	char value;
	Node* prev = nullptr;
	Node* next = nullptr;

	//TODO constructor, e.g. to be used like Node* temp = new Node('Z');
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