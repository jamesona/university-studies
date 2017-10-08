template <typename T>
struct Queue {
	List<T>* list = new List<T>();

	void push(T val) {
		list->append(val);
	}

	T shift() {
		return list->removeFront();
	}

	unsigned int size() {
		return list->count;
	}
};