#include "Tests.h"
#include "List.h"
#include "Stack.h"
#include "Queue.h"

int LL2() {
	cout << "==== Tests for LL2 ====" << endl;

	Stack<char> stack;
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

	Queue<char> q;
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

	return 0;
};