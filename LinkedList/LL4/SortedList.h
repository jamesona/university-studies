struct SortedList : List {
	int (*compare)(char, char);

	SortedList(int(*comparator)(char, char)) {
		compare = comparator;
	}

	void insert(char val) {
		// if the list is empty, or this value is less than head
		if (isEmpty() || compare(val, head->value) < 0) {
			prepend(val);
		}
		// if this value is greater than or equal to tail
		else if (compare(val, tail->value) > -1) {
			append(val);
		}
		// otherwise, iterate up the list until we find something >= val
		else {
			Node* cur = head;
			while (compare(val, cur->value) > -1) {
				cur = cur->next;
			}

			// alias the left and right nodes, so the next part doesn't suck
			Node* rightNode = cur;
			Node* leftNode = cur->prev;

			// now that we know where to put the new node, make it
			Node* node = new Node(val);
			node->next = rightNode;
			node->prev = leftNode;

			// insert it
			leftNode->next = node;
			rightNode->prev = node;

			// let the list know
			count++;
		}
	}
};
