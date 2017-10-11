#include "Tests.h"
#include "List.h"
#include "ListIterator.h"

int LL4() {
	cout << "==== Tests for LL4 ====" << endl;

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

	return 0;
}