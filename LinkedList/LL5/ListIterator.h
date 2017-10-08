template <typename T>
struct ListIterator {
	Node<T>* cur;

	ListIterator(List<T> list) {
		cur = list.head;
	}

	T next() {
		T val = cur->value;
		if (hasNext()) cur = cur->next;
		return val;
	}

	bool hasNext() {
		return cur != nullptr;
	}
};

template <typename T>
struct ListReverseIterator {
	Node<T>* cur;

	ListReverseIterator(List<T> list) {
		cur = list.tail;
	}

	T next() {
		T val = cur->value;
		if (hasNext()) cur = cur->prev;
		return val;
	}

	bool hasNext() {
		return cur != nullptr;
	}
};