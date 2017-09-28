#include <iostream>
using namespace std;

#include "List.h"
#include "Stack.h"
#include "Queue.h"

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
