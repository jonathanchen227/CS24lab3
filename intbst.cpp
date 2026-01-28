// intbst.cpp
// Implements class IntBST
// YOUR NAME(S), DATE

#include "intbst.h"

#include <iostream>
using std::cout;

// constructor sets up empty tree
IntBST::IntBST() {
	root = nullptr;
}

// destructor deletes all nodes
IntBST::~IntBST() {
      clear(root);
      root = nullptr;
}

// recursive helper for destructor
void IntBST::clear(Node *n) {
            if ( n == nullptr ) {
               return;
            }
            clear(n->right);
            clear(n->left);
            delete n;
          
}

// insert value in tree; return false if duplicate
bool IntBST::insert(int value) {
       return insert(value,root);
}

// recursive helper for insert (assumes n is never 0)
bool IntBST::insert(int value, Node*& n) {
    
    if ( n == nullptr ) {
        n = new Node();
        n->data = value;
        n->left = n->right = nullptr;
        return true;
    }
    if (n->data == value ) {
       return false;
    }
    if ( n->data > value ) {
        return insert(value,n->left);
    }
    else {
        return insert(value,n->right);
    } // REPLACE THIS NON-SOLUTION
}

// print tree data pre-order
void IntBST::printPreOrder() const {
    printPreOrder(root);
}

// recursive helper for printPreOrder()
void IntBST::printPreOrder(Node *n) const {
    if ( n==nullptr ) {
        return;
    }
        cout << n->data << endl;
        printPreOrder(n->left);
        printPreOrder(n->right);
}

// print tree data in-order, with helper
void IntBST::printInOrder() const {
    printInOrder(root); // IMPLEMENT HERE
}
void IntBST::printInOrder(Node *n) const {
     if ( n== nullptr ) {
        return;
    }
        printInOrder(n->left);
        cout << n->data << endl;
        printInOrder(n->right);
}

// prints tree data post-order, with helper
void IntBST::printPostOrder() const {
    printPostOrder(root);

}

void IntBST::printPostOrder(Node *n) const {
    if ( n == nullptr ) {
        return;
    }   
        
        printPostOrder(n->left);
        printPostOrder(n->right);
        cout << n->data << endl;
}

// return sum of values in tree
int IntBST::sum() const {
    return sum(root); // REPLACE THIS NON-SOLUTION
}

// recursive helper for sum
int IntBST::sum(Node *n) const {
    if ( n == nullptr ) {
      return 0; 
    }
    return sum ( n->right ) + sum ( n->left ) + n->data;
    
}

// return count of values
int IntBST::count() const {
    return count(root); // REPLACE THIS NON-SOLUTION
}

// recursive helper for count
int IntBST::count(Node *n) const {
    if ( n == nullptr ) {
        return 0;
    }
    return count(n->left) + count(n->right) + 1;  // REPLACE THIS NON-SOLUTION
}

// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
// Parameters:
// int value: the value to be found
// Node* n: the node to start with (for a recursive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"
IntBST::Node* IntBST::getNodeFor(int value, Node* n) const{
     if ( n == nullptr) { return nullptr; }
     if ( n->data == value ) {
        return n;
     }
     if ( n->data < value ) {
        return getNodeFor(value, n->right);
     }
     if ( n->data > value ) {
       return getNodeFor (value, n->left);
     }
     return nullptr;
}

// returns true if value is in the tree; false if not
bool IntBST::contains(int value) const {
    return contains(value,root);
}

bool IntBST::contains(int value, Node* n) const {
    if(n == nullptr){
       return false;
    }
    if ( n->data == value ) {
        return true;
    }
    if ( n->data < value ) {
       return contains(value,n->right);
    }
    else {
       return contains(value,n->left);
    }
    
}
// returns the Node containing the predecessor of the given value
int IntBST::getPredecessor(int value,Node* n) const{
    int predecessor = 0;
    while (n != nullptr) {
        if ( value > n->data ) {
            predecessor = n->data;
            n = n -> right;
        }
    else if ( value < n -> data ) {
        n = n -> left;
    }
    else {
        if ( n -> left != nullptr ) {
          n = n->left;
          while ( n->right != nullptr ) {
              n = n->right;
          }
          return n->data;
    return predecessor;
    }
    }
    return 0;
     // REPLACE THIS NON-SOLUTION
}
}

// returns the predecessor value of the given value or 0 if there is none
int IntBST::getPredecessor(int value) const{
    return getPredecessor(value,root); // REPLACE THIS NON-SOLUTION
}

// returns the Node containing the successor of the given value
int IntBST::getSuccessor(int value,Node* n) const {
    int successor = 0;
    while (n != nullptr) {
        if ( value <  n->data ) {
            successor = n->data;
            n = n -> left;
        }
        else if ( value > n -> data ) {
        n = n -> right;
    }
    else {
        if ( n -> right != nullptr ) {
          n = n->right;
          while ( n->left != nullptr ) {
              n = n->left;
          }
          return n->data;
    return successor;
    }
    }
    return 0;
     // REPLACE THIS NON-SOLUTION
}
}


// returns the successor value of the given value or 0 if there is none
int IntBST::getSuccessor(int value) const{
    return getSuccessor(value,root); // REPLACE THIS NON-SOLUTION
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool IntBST::remove(int value){
    return remove(value,root); // REPLACE THIS NON-SOLUTION
}
bool IntBST::remove(int value, Node*& n) {
    if (n == nullptr) {
        return false;
    }

    if (value < n->data) {
        return remove(value, n->left);
    }
    else if (value > n->data) {
        return remove(value, n->right);
    }
    else {
        if (n->left == nullptr && n->right == nullptr) {
            delete n;
            n = nullptr;
        }
        else if (n->left == nullptr) {
            Node* a = n;
            n = n->right;
            delete a;
        }
        else if (n->right == nullptr) {
            Node* b = n;
            n = n->left;
            delete b;
        }
        else {
            Node* successor = n->right;
            while (successor->left != nullptr) {
                successor = successor->left;
            }
            n->data = successor->data;
            remove(successor->data, n->right);
        }
        return true;
    }
}


