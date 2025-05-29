#ifndef RBTREE_H_INCLUDED
#define RBTREE_H_INCLUDED

#include <stdexcept>

//---------------------------------------------------------------------------------

/**
 * @enum TreeColor
 * @brief Defines the color of a Red-Black Tree node
 *
 * Represents the two possible colors (RED or BLACK) for nodes in a Red-Black Tree,
 * used to maintain balance properties.
 */
enum class TreeColor { RED, BLACK };


//---------------------------------------------------------------------------------

/**
 * @class RBTree
 * @brief A Red-Black Tree data structure
 *
 * Implements a self-balancing binary search tree with Red-Black properties.
 * Supports insertion, traversal (in-order, pre-order, post-order), and search operations.
 *
 * @tparam T The type of value stored in the tree
 * @author Minh Khang Nguyen
 * @version 01
 * @todo Add deletion operation
 * @bug Insert operation may not handle duplicate values
 */
template<typename T>
class RBTree {
public:

    /// Function pointer type for traversal operations
    using f1Typ = void (*)(T&);

    /**
     * @brief Default constructor
     *
     * Initializes an empty Red-Black Tree with a null root.
     *
     * @return void
     * @post Root is set to nullptr
     */
    RBTree();

    /**
     * @brief Copy constructor
     *
     * Creates a deep copy of another Red-Black Tree.
     *
     * @param other The Red-Black Tree to copy
     * @return void
     * @post Tree is a deep copy of other
     */
    RBTree(const RBTree<T>& other);

    /**
     * @brief Assignment operator
     *
     * Assigns the contents of another Red-Black Tree to this one, performing a deep copy.
     *
     * @param other The Red-Black Tree to assign from
     * @return RBTree<T>& Reference to this tree
     * @pre Object must be initialized
     * @post Tree is a deep copy of other
     */
    RBTree<T>& operator=(const RBTree<T>& other);

    /**
     * @brief Destructor
     *
     * Deallocates all nodes in the Red-Black Tree.
     *
     * @return void
     * @post All nodes are deleted, root is nullptr
     */
    ~RBTree();

    /**
     * @brief Inserts a value into the tree
     *
     * Adds a new value to the Red-Black Tree and balances it.
     *
     * @param v The value to insert
     * @return void
     * @pre Value type T must support comparison operators
     * @post Value is inserted, tree remains balanced
     */
    void insert(const T& v);

    /**
     * @brief Performs in-order traversal
     *
     * Traverses the tree in-order, applying the provided function to each value.
     *
     * @param f1 Function to apply to each value
     * @return void
     * @pre Tree must be initialized
     * @post Function f1 is applied to values in in-order
     */
    void inOrder(f1Typ f1) const;

    /**
     * @brief Performs pre-order traversal
     *
     * Traverses the tree pre-order, applying the provided function to each value.
     *
     * @param f1 Function to apply to each value
     * @return void
     * @pre Tree must be initialized
     * @post Function f1 is applied to values in pre-order
     */
    void preOrder(f1Typ f1) const;

    /**
     * @brief Performs post-order traversal
     *
     * Traverses the tree post-order, applying the provided function to each value.
     *
     * @param f1 Function to apply to each value
     * @return void
     * @pre Tree must be initialized
     * @post Function f1 is applied to values in post-order
     */
    void postOrder(f1Typ f1) const;


    /**
     * @brief Searches for a value using depth-first search
     *
     * Performs a DFS to find a target value in the tree.
     *
     * @param target The value to search for
     * @return bool True if target is found, false otherwise
     * @pre Tree must be initialized
     * @post Returns true if target exists, false otherwise
     */
    bool DFSearch(const T& target);

    /**
     * @brief Checks if the tree is empty
     *
     * Returns true if the tree has no nodes.
     *
     * @return bool True if tree is empty, false otherwise
     * @pre Tree must be initialized
     * @post Returns true if root is nullptr, false otherwise
     */
    bool operator!() const;

private:

    struct RBTNode {

        /// The value stored in the node
        T value;
        /// The color of the node (RED or BLACK)
        TreeColor color;
        /// Pointer to the left child node
        RBTNode* left;
        /// Pointer to the right child node
        RBTNode* right;
        /// Pointer to the parent node
        RBTNode* parent;

        explicit RBTNode(const T& v);
    };

    /// Pointer to the root node of the tree
    RBTNode* root;

    /**
     * @brief Recursively inserts a node
     *
     * Helper function to insert a value into the tree recursively.
     *
     * @param node The current node in recursion
     * @param parent The parent of the current node
     * @param value The value to insert
     * @return RBTNode<T>* Pointer to the inserted or updated node
     * @pre Value type T must support comparison operators
     * @post Value is inserted into the subtree
     */
    RBTNode* insertRecursive(RBTNode* node, RBTNode* parent, const T& value);

    /**
     * @brief Fixes Red-Black Tree properties after insertion
     *
     * Balances the tree by adjusting colors and performing rotations.
     *
     * @param node The node to start fixing from
     * @return void
     * @pre Node must be part of the tree
     * @post Tree satisfies Red-Black properties
     */
    void fixInsert(RBTNode* node);

    /**
     * @brief Performs a left rotation
     *
     * Rotates the subtree rooted at x to the left.
     *
     * @param x The root of the subtree to rotate
     * @return void
     * @pre Node x must have a right child
     * @post Subtree is rotated, pointers updated
     */
    void leftRotate(RBTNode* x);

    /**
     * @brief Performs a right rotation
     *
     * Rotates the subtree rooted at y to the right.
     *
     * @param y The root of the subtree to rotate
     * @return void
     * @pre Node y must have a left child
     * @post Subtree is rotated, pointers updated
     */
    void rightRotate(RBTNode* y);

    /**
     * @brief Recursive in-order traversal
     *
     * Helper function for in-order traversal.
     *
     * @param f1 Function to apply to each value
     * @param node The current node in recursion
     * @return void
     * @pre Node must be part of the tree
     * @post Function f1 is applied to values in in-order
     */
    void inOrderRecursive(f1Typ f1, RBTNode* node) const;

    /**
     * @brief Recursive pre-order traversal
     *
     * Helper function for pre-order traversal.
     *
     * @param f1 Function to apply to each value
     * @param node The current node in recursion
     * @return void
     * @pre Node must be part of the tree
     * @post Function f1 is applied to values in pre-order
     */
    void preOrderRecursive(f1Typ f1, RBTNode* node) const;

    /**
     * @brief Recursive post-order traversal
     *
     * Helper function for post-order traversal.
     *
     * @param f1 Function to apply to each value
     * @param node The current node in recursion
     * @return void
     * @pre Node must be part of the tree
     * @post Function f1 is applied to values in post-order
     */
    void postOrderRecursive(f1Typ f1, RBTNode* node) const;


    /**
     * @brief Recursive depth-first search
     *
     * Helper function for DFS to find a target value.
     *
     * @param node The current node in recursion
     * @param target The value to search for
     * @return bool True if target is found, false otherwise
     * @pre Node must be part of the tree
     * @post Returns true if target exists in subtree, false otherwise
     */
    bool deepRecursive(RBTNode* node, const T& target);

    /**
     * @brief Deletes all nodes in the tree
     *
     * Recursively deallocates all nodes in the subtree.
     *
     * @param node The root of the subtree to delete
     * @return void
     * @pre Node must be part of the tree
     * @post All nodes in subtree are deleted
     */
    void deleteTree(RBTNode* node);

    /**
     * @brief Copies a subtree
     *
     * Recursively creates a deep copy of a subtree.
     *
     * @param node The root of the subtree to copy
     * @param parent The parent of the new subtree
     * @return RBTNode<T>* Pointer to the root of the copied subtree
     * @pre Node must be part of a valid tree
     * @post Returns a deep copy of the subtree
     */
    RBTNode* copyTree(RBTNode* node, RBTNode* parent);
};

//===========================Public===============

template<typename T>
RBTree<T>::RBTree() : root(nullptr) {}

template<typename T>
RBTree<T>::RBTree(const RBTree<T>& other) : root(nullptr) {
    if (other.root) root = copyTree(other.root, nullptr);
}

template<typename T>
RBTree<T>& RBTree<T>::operator=(const RBTree<T>& other) {
    if (this != &other) {
        deleteTree(root);
        if (other.root) root = copyTree(other.root, nullptr);
    }
    return *this;
}

template<typename T>
RBTree<T>::~RBTree() {
    deleteTree(root);
}

template<typename T>
void RBTree<T>::insert(const T& v) {
    root = insertRecursive(root, nullptr, v);
    fixInsert(root);
    if (root) root->color = TreeColor::BLACK;
}

template<typename T>
void RBTree<T>::inOrder(f1Typ f1) const {
    inOrderRecursive(f1, root);
}

template<typename T>
void RBTree<T>::preOrder(f1Typ f1) const {
    preOrderRecursive(f1, root);
}

template<typename T>
void RBTree<T>::postOrder(f1Typ f1) const {
    postOrderRecursive(f1, root);
}

template<typename T>
bool RBTree<T>::DFSearch(const T& target) {
    return deepRecursive(root, target);
}


template<typename T>
bool RBTree<T>::operator!() const {
    return root == nullptr;
}

//============================Private==============

template<typename T>
typename RBTree<T>::RBTNode* RBTree<T>::insertRecursive(RBTNode* node, RBTNode* parent, const T& value) {
    if (!node) {
        RBTNode* newNode = new RBTNode(value);
        newNode->parent = parent;
        return newNode;
    }
    if (value < node->value) {
        node->left = insertRecursive(node->left, node, value);
    }
    else {
        node->right = insertRecursive(node->right, node, value);
    }
    return node;
}

template<typename T>
void RBTree<T>::fixInsert(RBTNode* z) {
    while (z->parent && z->parent->color == TreeColor::RED) {
        if (z->parent == z->parent->parent->left) {
            RBTNode* y = z->parent->parent->right;
            if (y && y->color == TreeColor::RED) {
                z->parent->color = TreeColor::BLACK;
                y->color = TreeColor::BLACK;
                z->parent->parent->color = TreeColor::RED;
                z = z->parent->parent;
            }
            else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(z);
                }
                z->parent->color = TreeColor::BLACK;
                z->parent->parent->color = TreeColor::RED;
                rightRotate(z->parent->parent);
            }
        }
        else {
            RBTNode* y = z->parent->parent->left; // Uncle
            if (y && y->color == TreeColor::RED) {
                z->parent->color = TreeColor::BLACK;
                y->color = TreeColor::BLACK;
                z->parent->parent->color = TreeColor::RED;
                z = z->parent->parent;
            }
            else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(z);
                }
                z->parent->color = TreeColor::BLACK;
                z->parent->parent->color = TreeColor::RED;
                leftRotate(z->parent->parent);
            }
        }
    }
    if (root) root->color = TreeColor::BLACK; // Ensure root is black
}

template<typename T>
void RBTree<T>::leftRotate(RBTNode* x) {
    RBTNode* y = x->right;
    x->right = y->left;
    if (y->left) y->left->parent = x;
    y->parent = x->parent;
    if (!x->parent) {
        root = y;
    }
    else if (x == x->parent->left) {
        x->parent->left = y;
    }
    else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

template<typename T>
void RBTree<T>::rightRotate(RBTNode* y) {
    RBTNode* x = y->left;
    y->left = x->right;
    if (x->right) x->right->parent = y;
    x->parent = y->parent;
    if (!y->parent) {
        root = x;
    }
    else if (y == y->parent->right) {
        y->parent->right = x;
    }
    else {
        y->parent->left = x;
    }
    x->right = y;
    y->parent = x;
}

template<typename T>
void RBTree<T>::inOrderRecursive(f1Typ f1, RBTNode* node) const {
    if (!node) return;
    inOrderRecursive(f1, node->left);
    f1(node->value);
    inOrderRecursive(f1, node->right);
}

template<typename T>
void RBTree<T>::preOrderRecursive(f1Typ f1, RBTNode* node) const {
    if (!node) return;
    f1(node->value);
    preOrderRecursive(f1, node->left);
    preOrderRecursive(f1, node->right);
}

template<typename T>
void RBTree<T>::postOrderRecursive(f1Typ f1, RBTNode* node) const {
    if (!node) return;
    postOrderRecursive(f1, node->left);
    postOrderRecursive(f1, node->right);
    f1(node->value);
}

template<typename T>
bool RBTree<T>::deepRecursive(RBTNode* node, const T& target) {
    if (!node) return false;
    if (node->value == target) return true;
    if (deepRecursive(node->left, target)) return true;
    return deepRecursive(node->right, target);
}

template<typename T>
void RBTree<T>::deleteTree(RBTNode* node) {
    if (!node) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

template<typename T>
typename RBTree<T>::RBTNode* RBTree<T>::copyTree(RBTNode* node, RBTNode* parent) {
    if (!node) return nullptr;
    RBTNode* newNode = new RBTNode(node->value);
    newNode->color = node->color;
    newNode->parent = parent;
    newNode->left = copyTree(node->left, newNode);
    newNode->right = copyTree(node->right, newNode);
    return newNode;
}

template<typename T>
RBTree<T>::RBTNode::RBTNode(const T& v) : value(v), color(TreeColor::RED), left(nullptr), right(nullptr), parent(nullptr) {}

#endif
