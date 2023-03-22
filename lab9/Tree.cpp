#include "Tree.h"



template<class T>
Node<T>::Node(T* data_val) {
	data = data_val;
}
template<class T>
Node<T>::~Node() { 

}



// ----------- Tree


// constructor
template<class T>
Tree<T>::Tree() {
	root = nullptr;
	current = nullptr;

	size = 0;
	idx = -1;
}

// destructor
template<class T>
Tree<T>::~Tree() {
	empty_tree();
}




// insert
template<class T>
void Tree<T>::insert(T* item) {


}
// remove
template<class T>
T* Tree<T>::remove(int id) {


}


// get right node
template<class T>
Node<T>* Tree<T>::go_right() {
	if (is_empty()) { throw "tree is empty"; }			//--------------

	// --- test if out of range ---

	current = current->right;
	return current;
}

// get left node
template<class T>
Node<T>* Tree<T>::go_left() {
	if (is_empty()) { throw "tree is empty"; }			//--------------

	// 
}

// find item by id
template<class T>
T* Tree<T>::find(int id) {
	if (is_empty()) { throw "tree is empty"; }			//--------------

}

// get depth of tree
template<class T>
int Tree<T>::get_depth() {


}

// get array in ascending order
template<class T>
T* Tree<T>::get_ascending() {
	if (is_empty()) { throw "tree is empty"; }			//--------------

}

// get array in descending order
template<class T>
T* Tree<T>::get_descending() {
	if (is_empty()) { throw "tree is empty"; }			//--------------

}

// empty tree -- remove all items
template<class T>
void Tree<T>::empty_tree() {


}


// is empty
template<class T>
bool Tree<T>::is_empty() {
	if (size == 0) {
		return true;
	}	
	return false;
}
