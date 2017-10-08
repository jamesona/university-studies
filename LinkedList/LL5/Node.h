#include <iostream>
using namespace std;

template <typename T>
struct Node {
	T value;
	Node* prev = nullptr;
	Node* next = nullptr;

	Node(T val) {
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