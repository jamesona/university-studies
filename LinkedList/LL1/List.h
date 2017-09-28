#include "Node.h"

struct List {
	Node* head = nullptr;
	Node* tail = nullptr;
	unsigned int count = 0;

	bool isEmpty() {
		return (head == nullptr);
	}

	//forward iterative version, i.e. from head to the end
	void display() {
		for (Node* cur = head; cur != nullptr; cur = cur->next) {
			cur->display();
		}
		cout << endl << endl;
	}

	//reverse recursive version, i.e. from tail to the beginning
	void reverseDisplay(Node* cur) {
		cur->display();
		if (cur->hasPrev()) reverseDisplay(cur->prev);
		else cout << endl << endl;
	}

	void append(char val) {
		Node* node = new Node(val);

		if (isEmpty()) {
			head = node;
			head->prev = nullptr;
		}
		else {
			tail->next = node;
			node->prev = tail;
		}
		tail = node;
		tail->next = nullptr;
		++count;
	}

	void prepend(char val) {
		Node* node = new Node(val);

		if (isEmpty()) {
			tail = node;
			tail->next = nullptr;
			tail->prev = nullptr;

			head = node;
			head->next = nullptr;
			head->prev = nullptr;
		}
		else {
			head->prev = node;
			node->next = head;
			head = node;
		}
		++count;
	}

	char at(unsigned int pos) {
		unsigned int index = 0;
		Node* cur = head;

		while (index < pos) {
			if (cur->hasNext()) {
				index++;
				cur = cur->next;
			}
			else break;
		}
		return cur->value;
	}

	int find(char val) {
		Node* cur = head;
		unsigned int i = 0;
		while (i < count) {
			if (cur->value == val) return i;
			cur = cur->next;
			i++;
		}
		return -1;
	}

	unsigned int size() {
		return count;
	}

};