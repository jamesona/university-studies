struct Stack {
	List* list = new List();

	void push(char val) {
		list->append(val);
	}

	char pop() {
		return list->removeBack();
	}

	unsigned int size() {
		return list->count;
	}
};