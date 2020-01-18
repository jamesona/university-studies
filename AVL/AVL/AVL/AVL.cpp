#include "stdafx.h"
#include <iostream>     // cout
#include <algorithm>    // random_shuffle()
#include <vector>       // vector
#include <ctime>        // time()
#include <cstdlib>      // srand()
#include <iomanip>      // setw
#include <queue>        // queue
#include <string>
using namespace std;

#define SEED unsigned(time(0))

const char ALPHABET[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int compareCaseSensitive(char a, char b) {
	char A = toupper(a), B = toupper(b);
	if (A < B) return -1;
	if (B < A) return 1;
	if (a < b) return -1;
	if (b < a) return 1;
	return 0;
}

int compareCaseInsensitive(char a, char b) {
	if (a < b) return -1;
	if (b < a) return 1;
	return 0;
}

int compareCaseSensitive(string sA, string sB) {
	unsigned i = 0;
	char a, b;
	while (i < sA.length() && i < sB.length()) {
		a = sA[i];
		b = sB[i];
		int result = compareCaseSensitive(a, b);
		if (result != 0) return result;
		i++;
	}

	return 0;
}

int compareCaseInensitive(string sA, string sB) {
	unsigned i = 0;
	char a, b;
	while (i < sA.length() && i < sB.length()) {
		a = sA[i];
		b = sB[i];
		int result = compareCaseInsensitive(a, b);
		if (result != 0) return result;
		i++;
	}

	return 0;
}

int compareNum(double a, double b) {
	if (a < b) return -1;
	if (b < a) return 1;
	return 0;
}

int max(int a, int b) {
	return (a > b) ? a : b;
}

int max(char a, char b) {
	return (compareCaseSensitive(a, b) > 0) ? a : b;
}

void printLetter(char c) {
	cout << c;
}

void encodeLetter(char c) {
	c += 7;
}

void decodeLetter(char c) {
	c -= 7;
}

string getName(unsigned length) {
	string name;
	while (length > 0) {
		unsigned i = rand() % 26;
		if (i < 0 || i > 25) {
			i++;
			i--;
		}
		char c = ALPHABET[i];
		name += (name.length() == 0) ? c : tolower(c);
		--length;
	}
	return name;
}

struct Employee {
	std::string fname;
	std::string lname;
	unsigned age;
	std::string id;
	double salary;

	Employee() {};

	Employee(std::string fname, std::string lname, size_t age, std::string id, double salary) {
		this->fname = fname;
		this->lname = lname;
		this->age = age;
		this->id = id;
		this->salary = salary;
	}

	friend std::ostream& operator<<(std::ostream& os, const Employee& emp) {
		os << emp.fname << " " << emp.lname << ", " << emp.age << ", id is " << emp.id;
		return os;
	}
};

Employee* createEmployee(string id) {
	// create some random names. they don't sound real, but they're random.
	string fname = getName(rand() % 6 + 4);
	string lname = getName(rand() % 6 + 4);
	// random age between 16 and 70
	unsigned age = rand() % 54 + 16;
	// determine a random hourly wage 8-60, in increments of 0.25
	double hourly = (rand() % 1200 + 128) * 0.05;
	// determine salary based on haverage work hours/year
	double salary = hourly * 2087;

	return new Employee(fname, lname, age, id, salary);
}

int compareFname(Employee a, Employee b) {
	return compareCaseSensitive(a.fname, b.fname);
}

int compareLname(Employee a, Employee b) {
	return compareCaseSensitive(a.lname, b.lname);
}

int compareAge(Employee a, Employee b) {
	return compareNum(a.age, b.age);
}

int compareSalary(Employee a, Employee b) {
	return compareNum(a.salary, b.salary);
}

void printEmployeeData(Employee e) {
	cout.precision(2);
	cout << e.id << ": " << e.lname << ", " << e.fname <<
		endl << "age: " << e.age <<
		endl << "salary: $" << fixed << e.salary <<
		endl << endl;
}

void incEmployeeAge(Employee e) {
	e.age++;
}

void giveEmployee8PercentRaise(Employee e) {
	e.salary += e.salary * 0.08;
}

template<class T>
struct Node {
	T value;
	Node* left;
	Node* right;
	int height;

	Node(T val, Node<T>* l, Node<T>* r, int h) {
		value = val;
		left = l;
		right = r;
		height = h;
	}

	Node(T val, int h) {
		value = val;
		left = right = nullptr;
		height = h;
	}

	Node(T val) {
		value = val;
		left = right = nullptr;
		height = 0;
	}
};

template<class T>
struct Tree {
	Node<T>* root;
	int(*comparator)(T, T);

	Tree() {
		root = nullptr;
	}

	Tree(Node<T>* n) {
		root = n;
	}

	Tree(int(*fn)(T, T)) {
		root = nullptr;
		comparator = fn;
	}

	Tree(Node<T>* n, int(*fn)(T, T)) {
		root = n;
		comparator = fn;
	}

	void inOrder(Node<T>* cur, void(*doSomething)(T)) {
		if (!cur) return;

		inOrder(cur->left, doSomething);
		doSomething(cur->value);
		inOrder(cur->right, doSomething);
	}

	void inOrder(void(*doSomething)(T)) {
		inOrder(root, doSomething);
	}

	void preOrder(Node<T>* cur, void(*doSomething)(T)) {
		if (!cur) return;

		doSomething(cur->value);
		preOrder(cur->left, doSomething);
		preOrder(cur->right, doSomething);
	}

	void preOrder(void(*doSomething)(T)) {
		preOrder(root, doSomething);
	}

	void postOrder(Node<T>* cur, void(*doSomething)(T)) {
		if (!cur) return;

		postOrder(cur->left, doSomething);
		postOrder(cur->right, doSomething);
		doSomething(cur->value);
	}

	void postOrder(void(*doSomething)(T)) {
		postOrder(root, doSomething);
	}

	void breadthFirst(Node<T>* root, void(*doSomething)(T)) {
		//create a queue with root
		queue<Node<T>*> q;
		q.push(root);

		//while queue has more
		while (q.size()) {
			//get the front of the queue and process
			Node<T>* cur = q.front();
			q.pop();
			doSomething(cur->value);
			//push its children (if any) onto queue
			if (cur->left) q.push(cur->left);
			if (cur->right) q.push(cur->right);
		}
	}

	void breadthFirst(void(*doSomething)(T)) {
		breadthFirst(root, doSomething);
	}

	void insert(T value) {
		root = balancedInsert(value, root);
	}

	void remove(T value) {
		// start at the root of the tree
		Node<T>* cur = root;
		Node<T>* last = nullptr;

		// you can't remove from an empty tree, so return
		if (cur == nullptr) return;

		while (cur != nullptr) { // if our current place is defined
			if (cur->value == value) break; // this is the right one, skip to the end so we can delete it

			if (comparator(value, cur->value) < 0) { // traverse left if less than cur
				if (cur->left == nullptr) { // if we can't traverse any farther
					return; // we didn't find the value, so there's nothing to delete
				}
				last = cur; // remember where we were, for when we get to the end
				cur = cur->left; // if you're here, we didn't return, so step left
			}

			else { // traverse right if value is greater than cur
				if (cur->right == nullptr) { // if we can't traverse any farther
					return; // we didn't find the value, so there's nothing to delete
				}
				last = cur; // remember where we were, for when we get to the end
				cur = cur->right; // if you're here, we didn't return, so step right
			}
		}

		// We made it to the end, so we know cur holds the value
		if (last) { // if we have a parent, let's figure out which side we're on
			if (last->left == cur) { // looks like we're on the left
				last->left = nullptr; // make our parent forget us
			}
			else { // looks like we're on the right
				last->right = nullptr; // make our parent forget us
			}
		}
		else { // not having a parent means we're root
			root = nullptr; // so, we need to reset the tree
		}

		//create a queue
		queue<Node<T>*> q;
		if (cur->left) q.push(cur->left);
		if (cur->right) q.push(cur->right);

		//while queue has more
		while (q.size()) {
			//get the front of the queue and process
			cur = q.front(); // we can overwrite cur, because we're done with it
			q.pop();
			insert(cur->value); // add this value back into the tree
								//push its children (if any) onto queue
			if (cur->left) q.push(cur->left);
			if (cur->right) q.push(cur->right);
		}
	}

	bool search(T value) {
		// start at the root of the tree
		Node<T>* cur = root;

		while (cur != nullptr) { // if our current place is defined
			if (cur->value == value) return true; // return true if it matches, otherwise

			if (comparator(value, cur->value) < 0) { // traverse left if less than cur
				if (cur->left == nullptr) { // if we can't traverse any farther
					return false; // return false, because we didn't find it
				}
				cur = cur->left; // if you're here, we didn't return, so step left
			}

			else { // traverse right if value is greater than cur
				if (cur->right == nullptr) { // if we can't traverse any farther
					return false; // return false, because we didn't find it
				}
				cur = cur->right; // if you're here, we didn't return, so step right
			}
		}

		// the while condition is already false for an empty tree, so return false
		return false;
	}

	Node<T>* balancedInsert(T value, Node<T>* node) {
		// create the new node
		Node<T>* newNode = new Node<T>(value);
		// if the tree has no root, this is now it
		if (node == nullptr) {
			return newNode;
		}

		// if value is less than cur
		if (comparator(value, node->value) < 0) {
			// recurse to the left
			node->left = balancedInsert(value, node->left);
		}
		else {
			// recurse right
			node->right = balancedInsert(value, node->right);
		}

		// set height of the node
		setHeight(node);

		return balanceChildren(value, node);
	}

	Node<T>* balanceChildren(T value, Node<T>* node) {
		int balance = getBalance(node);

		// needs left -> left
		if (balance > 1 && comparator(value, node->left->value) < 0)
			return rotateRight(node);

		// needs right -> right
		if (balance < -1 && comparator(value, node->right->value) >= 0)
			return rotateLeft(node);

		// needs left -> right
		if (balance > 1 && comparator(value, node->left->value) >= 0)
		{
			node->left = rotateLeft(node->left);
			return rotateRight(node);
		}

		// needs right -> left
		if (balance < -1 && comparator(value, node->right->value) < 0)
		{
			node->right = rotateRight(node->right);
			return rotateLeft(node);
		}

		return node;
	}

	Node<T>* rotateRight(Node<T>* y) {
		Node<T>* x = y->left;
		Node<T>* child = x->right;

		x->right = y;
		y->left = child;

		y->height = max(heightOf(y->left), heightOf(y->right)) + 1;
		x->height = max(heightOf(x->left), heightOf(y->right)) + 1;

		return x;
	}

	Node<T>* rotateLeft(Node<T>* x) {
		Node<T>* y = x->right;
		Node<T>* child = y->left;

		y->left = x;
		x->right = child;

		x->height = max(heightOf(x->left), heightOf(x->right)) + 1;
		y->height = max(heightOf(y->left), heightOf(y->right)) + 1;

		return y;
	}

	int heightOf(Node<T>* n) {
		if (n == nullptr) return -1;
		return n->height;
	}

	void setHeight(Node<T>* node) {
		node->height = 1 + max(heightOf(node->left), heightOf(node->right));
	}

	int getBalance(Node<T>* n) {
		if (n == nullptr) return 0;
		return heightOf(n->left) - heightOf(n->right);
	}

	void display(Node<T>* cur, int pad) {
		if (!cur) return;

		//Note: uses reverse order traversal     
		display(cur->right, pad + 10);
		cout << endl << setw(pad) << cur->value << endl;
		display(cur->left, pad + 10);
	}

	void display() {
		display(root, 0);
		cout << endl;
	}
};

int main() {
	// alphabet tests
	vector<char> letters(ALPHABET, ALPHABET + sizeof(ALPHABET) - 1);
	Tree<char>* letter_tree = new Tree<char>(compareCaseSensitive);
	
	// run through the alphabet twice to hit 52 entries
	int iterations[2] = { 1, 2 };
	for (int loop : iterations) {
		// randomize
		srand(SEED);
		random_shuffle(letters.begin(), letters.end());

		// dump out the order of input
		for (auto letter : letters) {
			printLetter(letter);
		}

		for (auto letter : letters) {
			letter_tree->insert(letter);
		}
	}

	letter_tree->inOrder(printLetter);
	cout << endl;
	letter_tree->preOrder(printLetter);
	cout << endl;
	letter_tree->postOrder(printLetter);
	cout << endl;
	letter_tree->breadthFirst(printLetter);
	cout << endl;

	// employee test
	Tree<Employee>* employeesByAge = new Tree<Employee>(compareAge);

	for (unsigned count = 0; count < 64; count++) {
		string id = to_string(count);
		employeesByAge->insert(*createEmployee(id));
	}

	employeesByAge->inOrder(printEmployeeData);
	cout << endl;
	employeesByAge->preOrder(printEmployeeData);
	cout << endl;
	employeesByAge->postOrder(printEmployeeData);
	cout << endl;
	employeesByAge->breadthFirst(printEmployeeData);
	cout << endl;


	getchar();

	return 0;
}