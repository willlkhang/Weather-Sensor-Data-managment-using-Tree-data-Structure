#ifndef HASHMAP_H
#define HASHMAP_H

#include <iostream>
#include <functional> // for std::hash only
#include <stdexcept>

/**
 * @class HashMap
 * @brief A simple hash map implementation using separate chaining for collision handling
 *
 * Stores key-value pairs using a fixed-size array of linked lists. Supports common
 * operations such as insertion, deletion, retrieval, and search.
 *
 * @tparam K Type of the key
 * @tparam V Type of the value
 *
 * @author Minh Khang Nguyen
 * @version 01
 *
 * @todo Support dynamic resizing and load factor threshold
 * @bug No protection against hash collisions creating long chains
 */
template<typename K, typename V>
class HashMap {
public:

	/**
	 * @brief Default constructor
	 *
	 * Initializes an empty hash map with all buckets set to null.
	 *
	 * @post Hash table is initialized with size 101
	 */
	HashMap();

	/**
	 * @brief Copy constructor
	 *
	 * Performs a deep copy of another HashMap instance.
	 *
	 * @param other HashMap instance to copy from
	 * @post A deep copy of all chains is made
	 */
	HashMap(const HashMap& other);

	/**
	 * @brief Destructor
	 *
	 * Frees all dynamically allocated memory for node chains.
	 *
	 * @post All memory is released
	 */
	~HashMap();

	/**
	 * @brief Assignment operator
	 *
	 * Performs deep copy assignment of another HashMap.
	 *
	 * @param other HashMap to assign from
	 * @return Reference to the current object
	 * @post All previous data is cleared and replaced
	 */

	HashMap& operator=(const HashMap& other);
	
	/**
	 * @brief Adds or updates a key-value pair
	 *
	 * If key exists, its value is updated; otherwise a new node is inserted.
	 *
	 * @param key Key to insert or update
	 * @param value Value to associate with the key
	 * @post Map will contain key with new value
	 */
	void addItem(const K& key, const V& value);
	
	/**
	 * @brief Removes the key-value pair with the specified key
	 *
	 * If key is not found, no operation is performed.
	 *
	 * @param key Key to remove
	 * @post Key-value pair is removed if present
	 */
	void removeItem(const K& key);
	
	/**
	 * @brief Checks if a key exists in the map
	 *
	 * @param key Key to search for
	 * @return True if key is found; otherwise, false
	 */
	bool findValue(const K& key) const;

	/**
	 * @brief Indexing operator
	 *
	 * Returns a reference to the value for a given key. If key does not exist,
	 * a new key is added with default value.
	 *
	 * @param key Key to access
	 * @return Reference to associated value
	 * @post Inserts default value if key does not exist
	 */
	V& operator[](const K& key);

	/**
	 * @brief Accessor function
	 *
	 * Returns a reference to the value for a given key. Throws if not found.
	 *
	 * @param key Key to access
	 * @return Reference to value
	 * @throws std::out_of_range if key is not found
	 */
	V& at(const K& key);

	/**
	 * @brief Const accessor function
	 *
	 * Returns a const reference to the value for a given key. Throws if not found.
	 *
	 * @param key Key to access
	 * @return Const reference to value
	 * @throws std::out_of_range if key is not found
	 */
	const V& at(const K& key) const;

	/**
	 * @brief Returns the number of stored key-value pairs
	 *
	 * @return Total number of elements in the map
	 */
	size_t size() const;

	/**
	 * @brief Checks whether the map is empty
	 *
	 * @return True if map has no elements; false otherwise
	 */
	bool empty() const;

private:

	/// Fixed table size for hash distribution
	static const int tableSize = 101; // prime number distribution

	/// Internal structure to represent a key-value pair in a chain
	struct Node {
		K key;        /// Key of the node
		V value;      /// Value associated with the key
		Node* next;   /// Pointer to the next node in the chain
		
		/**
		 * @brief Constructor for a node
		 *
		 * Initializes a node with key-value pair.
		 *
		 * @param k Key
		 * @param v Value
		 */
		Node(const K& k, const V& v);
	};

	/// Array of pointers to linked lists (buckets)
	Node* table[tableSize];

	/// Number of elements in the map
	size_t elementCount;

	/// Hash function to compute index
	int hashFunction(const K& key) const;
	
	/// Deep copy of linked list
	Node* copyChain(Node* head) const;
	
	/// Delete linked list
	void deleteChain(Node* head);

	// Clear entire map
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
