#include "Tree.h"


// ----------- Node

// constructor
template<class T>		
Node<T>::Node() {		// root
	data = nullptr;
	right = nullptr;
	left = nullptr;
}
template<class T>
Node<T>::Node(T* data_val) {
	data = data_val;
	right = nullptr;
	left = nullptr;
}

// deconstructor
template<class T>
Node<T>::~Node() { 

}



// ----------- Tree

// constructor
template<class T>
Tree<T>::Tree() {
	root = new Node<T>;
	current = nullptr;
	size = 0;
	idx = -1;
}

// destructor
template<class T>
Tree<T>::~Tree() {
	empty_tree();
	delete root;
}





/*	--------------- private ---------------		*/


// get right node
// return right child of current node without updating current position
template<class T>
Node<T>* Tree<T>::get_right() {			
	if (is_empty() || is_leaf()) { return nullptr; }
	return current->right;;
}
// get left node
// return left child of current node without updating current position
template<class T>
Node<T>* Tree<T>::get_left() {
	if (is_empty() || is_leaf()) { return nullptr; }	
	return current->left;
}




/* 
// find item
// find by keyword and return node. if item is not in tree, return parent 
// node where it should be
template<class T>
Node<T>* Tree<T>::find(std::string key) {
	if (is_empty()) { return nullptr; }

	current = root;
	while (get_key() != key) {			
		if (current == nullptr) {
			
		}

		if (key_is_greater()) { go_right(); }			// key is greater than
		else if (key_is_less()) { go_left(); }			// key is less than
	}
} */





// is leaf
template<class T>						// use current
bool Tree<T>::is_leaf() {
	if (current->child == nullptr) {
		return true;
	}
	return false;
}
template<class T>						// use parameter
bool Tree<T>::is_leaf(Node<T>* node) {
	if (node->child == nullptr) {
		return true;
	}
	return false;
}

/* 
template<class T>	
bool Tree<T>::key_is_greater(std::string key) {
	// if key higher alphabetical order
}
template<class T>	
bool Tree<T>::key_is_less(std::string key) {
	// if key lower alphabetical order
}
 */




/*	--------------- public ---------------		*/

// insert
template<class T>
void Tree<T>::insert(T* item) {
	Node<T>* newitem = new Node<T>;

	if (size == 0) {			// if first insert
		root = newitem;
		current = root;
	}
	else {						// not first insert
		
		
		// find place to insert
	}

	


}


/* // remove
template<class T>
T* Tree<T>::remove(std::string key) {
	if (is_empty()) { throw "tree is empty"; }			//--------------

	// find key
	T* obj = find(key);		
	
	if (obj == nullptr) {
		// cannot remove : not in tree
	}
	
	// remove object


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


} */


// is empty
template<class T>
bool Tree<T>::is_empty() {
	if (size == 0) {
		return true;
	}	
	return false;
}




/* 

// operator overloads
template<class T>	
bool Tree<T>::operator==(std::string key) {
	if (current->key == )
}
template<class T>	
bool Tree<T>::operator<(std::string key) {

}
template<class T>	
bool Tree<T>::operator>(std::string key) {

}
 */