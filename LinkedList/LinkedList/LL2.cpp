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

struct List {
	Node* head = nullptr;
	Node* tail = nullptr;
	unsigned int count = 0;

	bool isEmpty() {
		return (head == nullptr);
	}

	void display() {
		for (Node* cur = head; cur != nullptr; cur = cur->next) {
			cur->display();
		}
		cout << endl << endl;
	}

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

	char remove(unsigned int pos) {
		unsigned i = 0;
		Node* cur = head;
		while (i < pos) {
			cur = cur->next;
			i++;
		}
		Node* prev = cur->prev;
		Node* next = cur->next;

		prev->next = next;
		next->prev = prev;

		return cur->value;
	}

	char removeFront() {
		char val = head->value;

		if (head->hasNext()) {
			head = head->next;
			head->prev = nullptr;
		}
		else {
			head = nullptr;
			tail = nullptr;
		}
		
		count--;
		return val;
	}

	char removeBack() {
		char val = tail->value;

		if (tail->hasPrev()) {
			tail = tail->prev;
			tail->next = nullptr;
		}
		else {
			head = nullptr;
			tail = nullptr;
		}

		count--;
		return val;
	}
};

struct Stack {
	List* list = new List();

	void push(char val) {
		list->append(val);
	}

	char pop() {
		return list->removeBack();
	}

	unsigned int size() {
		return list->count;
	}
};

struct Queue {
	List* list = new List();

	void push(char val) {
		list->append(val);
	}

	char shift() {
		return list->removeFront();
	}

	unsigned int size() {
		return list->count;
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
	list1.display(); 
	list1.reverseDisplay(list1.tail); 

	cout << "Who did?\n" << list1.at(3) << " did, "
		<< list1.size() << " times." << endl << endl;

	List list2;
	list2.prepend('A');
	list2.append('L');
	list2.prepend('P');
	list2.append('S');
	list2.display();
	list2.reverseDisplay(list2.tail);

	cout << "Too much Dew (said no one ever). I need to "
		<< list2.at(0) << "ee. Then I'll drink "
		<< list2.size() << " more." << endl;

	Stack stack;
	stack.push('L');
	stack.push('I');
	stack.push('V');
	stack.push('E');
	cout << "I'm feeling ";
	cout << stack.pop();
	cout << stack.pop();
	cout << stack.pop();
	cout << stack.pop();
	cout << "." << endl << endl;

	Queue q;
	q.push('R');
	q.push('A');
	q.push('T');
	cout << "Must have been that ";
	cout << q.shift();
	cout << q.shift();
	cout << q.shift();
	cout << " I ate." << endl << endl;

	cout << "Here's how many letters are left on the stack: " << stack.size() << endl;
	cout << "And here's how many letters are left on the q: " << q.size() << endl;

	cout << endl << "Press return to quit...";
	getchar();
	return 0;
}
