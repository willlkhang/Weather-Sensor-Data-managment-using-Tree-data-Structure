#ifndef RBMAP_H_INCLUDED
#define RBMAP_H_INCLUDED

#include <stdexcept>

enum class Color { RED, BLACK };

template<typename K, typename V>
struct RBNode {
	K key;
	V value;
	Color color;
	RBNode* left, * right, * parent;

	RBNode(const K& k, const V& v) : key(k), value(v), color(Color::RED),
		left(nullptr), right(nullptr), parent(nullptr) {
	}
};
// root is always black


//need iterator to complete
template<typename K, typename V>
class RBMap {
public:

	typedef void(&funcPtr)(K&, V&);


	RBMap();
	RBMap(const RBMap& other);
	~RBMap();

	void insert(const K& key, const V& val);
	const V& at(const K& key);

	V& operator[](const K& key);
	RBMap<K, V>& operator=(RBMap<K, V> const& other);

	size_t size() const;

	void inOrder(funcPtr f);
	void preOrder(funcPtr f);
	void postOrder(funcPtr f);

private:
	RBNode <K, V>* root;
	size_t sz;

	RBNode<K, V>* copyNode(RBNode<K, V>* node, RBNode<K, V>* parent);
	void bstInsert(RBNode<K, V>* z);/*BST has no balancing*/
	void rotateleft(RBNode<K, V>* x);
	void rotateright(RBNode<K, V>* y);
	void fixInsert(RBNode<K, V>* z);

	void inOrderRecursive(funcPtr fptr, RBNode<K, V>* z);
	void preOrderRecursive(funcPtr fptr, RBNode<K, V>* z);
	void postOrderRecursive(funcPtr fptr, RBNode<K, V>* z);

	RBNode<K, V>* findNode(RBNode<K, V>* n, const K& key) const;
	void clear(RBNode<K, V>* n);
};

//=====================================Public========================

template<typename K, typename V>
RBMap<K, V>::RBMap() : root(nullptr), sz(0) {}

template<typename K, typename V>
RBMap<K, V>::RBMap(const RBMap& other) : root(nullptr), sz(0) {
	root = copyNode(other.root, nullptr);
	sz = other.sz;
	if (root) root->color = Color::BLACK;
}

template<typename K, typename V>
RBMap<K, V>::~RBMap() { clear(root); }

template<typename K, typename V>
void RBMap<K, V>::insert(const K& key, const V& val) {
	RBNode<K, V>* z = new RBNode<K, V>(key, val);
	bstInsert(z);
	fixInsert(z);
	++sz;
}

template<typename K, typename V>
const V& RBMap<K, V>::at(const K& key) {
	auto n = findNode(root, key);
	if (!n) throw std::out_of_range("Key not found");
	return n->value;
}

template<typename K, typename V>
V& RBMap<K, V>::operator[](const K& key) {
	RBNode<K, V>* node = findNode(root, key);
	if (node) return node->value;
	insert(key, V());
	return findNode(root, key)->value;
}

template<typename K, typename V>
RBMap<K, V>& RBMap<K, V>::operator=(RBMap<K, V> const& other) {
	if (this != &other) {
		clear(root);
		root = copyNode(other.root, nullptr);
		sz = other.sz;
		if (root) root->color = Color::BLACK;
	}

	return *this;
}

template<typename K, typename V>
size_t RBMap<K, V>::size() const { return sz; }

template<typename K, typename V>
void RBMap<K, V>::inOrder(funcPtr f) { return inOrderRecursive(f, root); }

template<typename K, typename V>
void RBMap<K, V>::preOrder(funcPtr f) { return preOrderRecursive(f, root); }

template<typename K, typename V>
void RBMap<K, V>::postOrder(funcPtr f) { return postOrderRecursive(f, root); }

//=====================================================================================================

template<typename K, typename V>
RBNode<K, V>* RBMap<K, V>::copyNode(RBNode<K, V>* node, RBNode<K, V>* parent) {
	if (!node) return nullptr; // avoid wasting computational cost
	RBNode<K, V>* n = new RBNode<K, V>(node->key, node->value);
	n->color = node->color;
	n->parent = parent;
	n->left = copyNode(node->left, n);
	n->right = copyNode(node->right, n);
	return n;
}

template<typename K, typename V>
void RBMap<K, V>::bstInsert(RBNode<K, V>* z) { /*BST has no balancing*/
	RBNode<K, V>* x = root;
	RBNode<K, V>* y = nullptr;

	while (x) {
		y = x;
		if (z->key < x->key) x = x->left;
		else if (z->key > x->key) x = x->right;
		else { x->value = z->value; delete z; return; }
	}

	z->parent = y;
	if (!y) root = z;
	else if (z->key < y->key) y->left = z;
	else y->right = z;
}

template<typename K, typename V>
void RBMap<K, V>::rotateleft(RBNode<K, V>* x) {
	RBNode<K, V>* y = x->right;
	x->right = y->left;
	if (y->left) y->left->parent = x;
	y->parent = x->parent;
	if (!x->parent) root = y;
	else if (x == x->parent->left) x->parent->left = y;
	else x->parent->right = y;
	y->left = x;
	x->parent = y;
}

template<typename K, typename V>
void RBMap<K, V>::rotateright(RBNode<K, V>* y) {
	RBNode<K, V>* x = y->left;
	y->left = x->right;
	if (x->right) x->right->parent = y;
	x->parent = y->parent;
	if (!y->parent) root = x;
	else if (y == y->parent->right) y->parent->right = x;
	else y->parent->left = x;
	x->right = y;
	y->parent = x;
}

template<typename K, typename V>
void RBMap<K, V>::fixInsert(RBNode<K, V>* z) {
	//loop unit z is root (root is black --> red -> brake) or z is parent
	while (z->parent && z->parent->color == Color::RED) {
		//when z->parent is red --> z->parent has prandpa
		RBNode<K, V>* gp = z->parent->parent;
		//CASE: z->parent = gp->left)
		if (z->parent == gp->left) {
			//make y is the other child gp->right
			RBNode<K, V>* y = gp->right;
			//CASE 1: y is red (also check is y exists)
			if (y && y->color == Color::RED) {
				//change color of dad and unclde to black
				z->parent->color = Color::BLACK;
				y->color = Color::BLACK;
				//gp to red as his kis are black
				gp->color = Color::RED;
				//continue to check from gp;
				z = gp;
			}
			else {
				//CASE 2: z is his right kid
				if (z == z->parent->right) {
					z = z->parent; // move z to parent
					rotateleft(z); //roate left to parent --> case 3
				}
				//CASE 3: z is left kid
				z->parent->color = Color::BLACK;
				gp->color = Color::RED;
				rotateright(gp);
			}
		}
		else {
			//CASE z->parent == gp->right
			RBNode<K, V>* y = gp->left;
			if (y && y->color == Color::RED) {
				//change color of dad and unclde to black
				z->parent->color = Color::BLACK;
				y->color = Color::BLACK;
				//gp to red as his kis are black
				gp->color = Color::RED;
				//continue to check from gp;
				z = gp;
			}
			else {
				//CASE 2: z is his left kid
				if (z == z->parent->left) {
					z = z->parent; // move z to parent
					rotateright(z); //roate left to parent --> case 3
				}
				//CASE 3: z is right kid
				z->parent->color = Color::BLACK;
				gp->color = Color::RED;
				rotateleft(gp);
			}
		}
	}
	if (root) root->color = Color::BLACK;
}

template<typename K, typename V>
RBNode<K, V>* RBMap<K, V>::findNode(RBNode<K, V>* n, const K& key) const {
	if (!n) return nullptr;
	if (key < n->key) return findNode(n->left, key);
	if (n->key < key) return findNode(n->right, key);
	return n;
}

template<typename K, typename V>
void RBMap<K, V>::clear(RBNode<K, V>* n) {
	if (!n) return;
	clear(n->right);
	clear(n->left);
	delete n;
}

template<typename K, typename V>
void RBMap<K, V>::inOrderRecursive(funcPtr fptr, RBNode<K, V>* z) {
	if (!z) return;
	inOrderRecursive(fptr, z->left);
	fptr(z->key, z->value);
	inOrderRecursive(fptr, z->right);
}

template<typename K, typename V>
void RBMap<K, V>::preOrderRecursive(funcPtr fptr, RBNode<K, V>* z) {
	if (!z) return;
	fptr(z->key, z->value);
	preOrderRecursive(fptr, z->left);
	preOrderRecursive(fptr, z->right);
}

template<typename K, typename V>
void RBMap<K, V>::postOrderRecursive(funcPtr fptr, RBNode<K, V>* z) {
	if (!z) return;
	postOrderRecursive(fptr, z->left);
	postOrderRecursive(fptr, z->right);
	fptr(z->key, z->value);
}

#endif // RBMAP_H_INCLUDED