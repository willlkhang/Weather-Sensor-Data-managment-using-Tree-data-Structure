#ifndef HASHMAP_H
#define HASHMAP_H

#include <iostream>
#include <functional> // for std::hash only
#include <stdexcept>

template<typename K, typename V>
class HashMap {
public:
	HashMap();
	HashMap(const HashMap& other);
	~HashMap();
	HashMap& operator=(const HashMap& other);

	void addItem(const K& key, const V& value);
	void removeItem(const K& key);
	bool findValue(const K& key) const;

	V& operator[](const K& key);
	V& at(const K& key);
	const V& at(const K& key) const;


	size_t size() const;
	bool empty() const;

private:
	static const int tableSize = 101; // prime number distribution

	struct Node {
		K key;
		V value;
		Node* next;

		Node(const K& k, const V& v);
	};

	Node* table[tableSize];

	size_t elementCount;

	int hashFunction(const K& key) const;

	Node* copyChain(Node* head) const;
	void deleteChain(Node* head);

	void clear();
};

//--------private-----------

template<typename K, typename V>
HashMap<K,V>::Node::Node(const K& k, const V& v) : key(k), value(v), next(nullptr) {}

template<typename K, typename V>
int HashMap<K, V>::hashFunction(const K& key) const {
	std::hash<K> hasher;
	return static_cast<int>(hasher(key) % tableSize);
}


template<typename K, typename V>
typename HashMap<K, V>::Node* HashMap<K, V>::copyChain(HashMap<K, V>::Node* head) const {
	if (!head) return nullptr;
	Node* newhead = new Node(head->key, head->value);
	Node* target = newhead;
	Node* src = head->next;

	while (src) {
		target->next = new Node(src->key, src->value);
		target = target->next;
		src = src->next;
	}
	target->next = nullptr;
	return newhead;
}

template<typename K, typename V>
void HashMap<K, V>::deleteChain(Node* head) {
	while (head) {
		Node* tmp = head;
		head = head->next;
		delete tmp;
	}
}


//---------public----------

template<typename K, typename V>
HashMap<K, V>::HashMap() : elementCount(0) {
	for (int i = 0; i < tableSize; i++) {
		table[i] = nullptr;
	}
}

template<typename K, typename V>
HashMap<K, V>::HashMap(const HashMap& other) : elementCount(other.elementCount) {
	for (int i = 0; i < tableSize; i++) {
		table[i] = copyChain(other.table[i]);
	}
}

template<typename K, typename V>
HashMap<K, V>::~HashMap() {
	clear();
}


template<typename K, typename V>
HashMap<K, V>& HashMap<K, V>::operator=(const HashMap& other) {
	if (this != &other) {
		clear();
		elementCount = other.elementCount;
		for (int i = 0; i < tableSize; i++) {
			table[i] = copyChain(other.table[i]);
		}
	}
	return *this;
}

template<typename K, typename V>
void HashMap<K, V>::addItem(const K& key, const V& value) {
	int index = hashFunction(key);
	Node* current = table[index];

	while (current) {
		if (current->key == key) {
			current->value = value; return;
		}
		current = current->next;
	}

	Node* newOne = new Node(key, value);
	newOne->next = table[index];
	table[index] = newOne;
	++elementCount;
}

template<typename K, typename V>
void HashMap<K, V>::removeItem(const K& key) {
	int index = hashFunction(key);

	Node* current = table[index];
	Node* prev = nullptr;

	while (current && current->key != key) {
		prev = current;
		current = current->next;
	}

	if (!current) {
		//std::cout << "there is no such data for the provided key\n";
		return;
	}
	if (!prev) table[index] = current->next;
	else prev->next = current->next;

	delete current; --elementCount;
	//std::cout << "remove value at key: " << key << " done\n";
}

template<typename K, typename V>
bool HashMap<K, V>::findValue(const K& key) const {
	int index = hashFunction(key);
	Node* current = table[index];
	while (current) {
		if(current->key == key) return true;
		current = current->next;
	}
	return false;
}

template<typename K, typename V>
size_t HashMap<K, V>::size() const {
	return elementCount;
}

template<typename K, typename V>
bool HashMap<K, V>::empty() const {
	return elementCount == 0;
}

template<typename K, typename V>
void HashMap<K, V>::clear() {
	for (int i = 0; i < tableSize; i++) {
		deleteChain(table[i]);
		table[i] = nullptr;
	}
	elementCount = 0;
}

template<typename K, typename V>
V& HashMap<K, V>::operator[](const K& key) {
	int index = hashFunction(key);
	Node* current = table[index];

	//getter
	while (current) {
		if (current->key == key) return current->value;
		current = current->next;
	}

	//setter
	Node* newone = new Node(key, V());
	newone->next = table[index];
	table[index] = newone;
	++elementCount;
	return table[index]->value;
}

template<typename K, typename V>
V& HashMap<K, V>::at(const K& key) {
	int index = hashFunction(key);
	for (Node* current = table[index]; current; current = current->next) {
		if (current->key == key) return current->value;
	}
	throw std::out_of_range("no such key in this map\n");
}

template<typename K, typename V>
const V& HashMap<K, V>::at(const K& key) const {
	int index = hashFunction(key);
	for (Node* current = table[index]; current; current = current->next) {
		if (current->key == key) return current->value;
	}
	throw std::out_of_range("no such key in this map\n");
}

#endif //HASHMAP_H
