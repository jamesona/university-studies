template <typename T>
struct Stack {
	List<T>* list = new List<T>();

	void push(T val) {
		list->append(val);
	}

	T pop() {
		return list->removeBack();
	}

	unsigned int size() {
		return list->count;
	}
};