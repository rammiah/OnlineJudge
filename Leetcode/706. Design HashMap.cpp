class MyHashMap {
	struct node {
		int key;
		int value;
		node* next = nullptr;
	};
	int size;
	int capacity;
	node** nodes;


	int hash(int key) {
		return key % capacity;
	}

	void rehash() {
		// 1.5倍增长
		node** old_nodes = nodes;
		int old_capacity = capacity;
		capacity *= 1.5;
		size = 0;
		nodes = new node*[capacity]{};
		for (int i = 0; i < old_capacity; ++i) {
			node* n = old_nodes[i];
			while (n != nullptr) {
				put(n->key, n->value);
				node* next = n->next;
				delete n;
				n = next;
			}
		}
		delete[] old_nodes;
	}

public:
	/** Initialize your data structure here. */
	MyHashMap(): capacity(1023), size(0) {
		nodes = new node*[capacity]{};
	}

	/** value will always be non-negative. */
	void put(int key, int value) {
        // std::cout << "put" << "(" << key << ","<< value << ")\n";
		node* n = nodes[hash(key)];
		if (n == nullptr) {
			n = new node;
			nodes[hash(key)] = n;
			n->key = key;
			n->value = value;
			++size;
		}
		else {
			while (n->next != nullptr && n->key != key) {
				n = n->next;
			}
			if (n->key == key) {
				n->value = value;
				return;
			}
			// 添加
			node* new_node = new node;
			n->next = new_node;
			new_node->key = key;
			new_node->value = value;
			++size;
		}
		if (size * 1.0 / capacity >= 0.8) {
			rehash();
		}
	}

	/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
	int get(int key) {
		node* n = nodes[hash(key)];
		while (n != nullptr && n->key != key) {
			n = n->next;
		}

		return n == nullptr ? -1 : n->value;
	}

	/** Removes the mapping of the specified value key if this map contains a mapping for the key */
	void remove(int key) {
		node* n = nodes[hash(key)];
		node* prev = n;
		while (n != nullptr && n->key != key) {
			prev = n;
			n = n->next;
		}
		if (n != nullptr) {
			// 删除
			if (prev == n) {
				// 第一个
				nodes[hash(key)] = n->next;
				delete n;
			}
			else {
				prev->next = n->next;
				delete n;
			}
			--size;
		}
	}

	~MyHashMap() {
		for (int i = 0; i < capacity; ++i) {
			node* n = nodes[i];
			while (n != nullptr) {
				node* next = n->next;
				delete n;
				n = next;
			}
		}
		delete[] nodes;
	}
};
