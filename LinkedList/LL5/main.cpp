#include <iostream>
using namespace std;

#include "List.h"
#include "ListIterator.h"

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
	List<char> list;
	list.append('I');
	list.prepend('P');
	list.prepend('U');
	list.append('L');
	list.append('S');
	list.prepend('P');
	//list1.display(); 
	
	cout << "Gonna try out this iterator thang." << endl << endl;

	ListIterator<char> it(list);
	while (it.hasNext()) {
		cout << it.next();
	}

	cout << endl << endl;
	
	cout << "Not bad. Not bad." << endl << endl;

	cout << "Reversel iterator gives this result: ";
	ListReverseIterator<char> that = ListReverseIterator<char>(list);
	while (that.hasNext()) {
		cout << that.next();
	}
	cout << endl << "ever point extra easiest " << endl << endl;

	cout << endl << "Press return to quit...";
	getchar();
	return 0;
}
