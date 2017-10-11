#include "Tests.h"
#include "List.h"

int LL1() {
	cout << "==== Tests for LL1 ====" << endl;
	List<char> list1;
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

	List<char> list2;
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

	return 0;
};