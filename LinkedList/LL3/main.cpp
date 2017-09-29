#include <iostream>
using namespace std;

#include "List.h"
#include "Stack.h"
#include "Queue.h"
#include "SortedList.h"

int compareChars(char a, char b) {
	char A = toupper(a);
	char B = toupper(b);
	if (A < B) return -1;
	if (B < A) return 1;
	if (a < b) return -1;
	if (b < a) return 1;
	return 0;
}

int main() {
	SortedList* sortedList = new SortedList(compareChars);

	sortedList->insert('A');
	sortedList->insert('e');
	sortedList->insert('g');
	sortedList->insert('e');
	sortedList->insert('a');
	sortedList->insert('n');
	sortedList->insert('A');
	sortedList->insert('n');
	sortedList->insert('i');
	sortedList->insert('m');
	sortedList->insert('a');
	sortedList->insert('l');
	sortedList->insert('L');
	sortedList->insert('O');
	sortedList->insert('V');
	sortedList->insert('E');
	sortedList->insert('R');

	sortedList->display();

	cout << endl << "Press return to quit...";
	getchar();
	return 0;
}
