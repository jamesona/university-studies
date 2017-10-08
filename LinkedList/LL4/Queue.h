struct Queue {
	List* list = new List();

	void push(char val) {
		list->append(val);
	}

	char shift() {
		return list->removeFront();
	}

	unsigned int size() {
		return list->count;
	}
};