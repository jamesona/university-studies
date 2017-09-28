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
		int index = 0;
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
		int i = 0;
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

int main() {
	List list1;
	list1.append('I');
	list1.prepend('P');
	list1.prepend('U');
	list1.append('L');
	list1.append('S');
	list1.prepend('P');
	list1.display(); //you will see a word 
	list1.reverseDisplay(list1.tail); //you will see a different word
									  //together, they form a secret phrase

	cout << "Who did?\n" << list1.at(3) << " did, "
		<< list1.size() << " times." << endl << endl;

	List list2;
	list2.prepend('A');
	list2.append('L');
	list2.prepend('P');
	list2.append('S');
	list2.display();
	list2.reverseDisplay(list2.tail);
	//together, they form a second secret phrase

	cout << "Too much Dew (said no one ever). I need to "
		<< list2.at(0) << "ee. Then I'll drink "
		<< list2.size() << " more." << endl;

	cout << endl << "Press return to quit...";
	getchar();
	return 0;
}
