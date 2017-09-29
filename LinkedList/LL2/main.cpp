#include <iostream>
using namespace std;

#include "List.h"
#include "Stack.h"
#include "Queue.h"

int main() {
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
