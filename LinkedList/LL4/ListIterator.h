struct ListIterator {
	Node* cur;

	ListIterator(List list) {
		cur = list.head;
	}

	char next() {
		char val = cur->value;
		if (hasNext()) cur = cur->next;
		return val;
	}

	bool hasNext() {
		return cur != nullptr;
	}
};

struct ListReverseIterator {
	Node* cur;

	ListReverseIterator(List list) {
		cur = list.tail;
	}

	char next() {
		char val = cur->value;
		if (hasNext()) cur = cur->prev;
		return val;
	}

	bool hasNext() {
		return cur != nullptr;
	}
};