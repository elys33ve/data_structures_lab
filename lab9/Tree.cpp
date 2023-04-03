#include <string>
#include "Tree.h"





// --------- private functions --------- 


// re-sort
// recursive helper function for remove -- re-sorts 
template<class T>
void Tree<T>::resort (Node<T>* node) {
	if(node != nullptr) {						// recursion until node is nullptr
		std::string key = node->data->word;
		current = root;
		Node<T> temp = *node;
		Node<T>* parent;

		// find insert position
		while (current != nullptr) {
			parent = current;

			if (key_is_greater(key)) { go_right(); }			// key is greater than
			else if (key_is_less(key)) { go_left(); }			// key is less than
			else { return; }
		}

		// insert
		current = parent;
		if (key_is_greater(key)) { current->right = node; }			// insert right
		else if (key_is_less(key)) { current->left = node; }		// insert left

		node->left = nullptr;
		node->right = nullptr;
		resort(temp.left);
		resort(temp.right);
	}
}



// get ascending / descending
// recursive helper function for get all ascending
template<class T>
T* Tree<T>::get_ascending(Node<T>* node, int* i, T arr[]) {
	if (is_empty()) { return nullptr; }

	if (node != nullptr) {
		get_ascending(node->left, i, arr);			// get lower keywords
		*i += 1;
		arr[*i] = *node->data;
		get_ascending(node->right, i, arr);			// get higher keywords
	}
	return nullptr;
}
// recursive helper function for get all descending
template<class T>
T* Tree<T>::get_descending(Node<T>* node, int* i, T arr[]) {
	if (is_empty()) { return nullptr; }

	if (node != nullptr) {
		get_descending(node->right, i, arr);		// get higher keywords
		*i += 1;
		arr[*i] = *node->data;
		get_descending(node->left, i, arr);			// get lower keywords
	}
	return nullptr;
}



// is leaf
template<class T>						// use current
bool Tree<T>::is_leaf() {
	if (current == nullptr) { return true; }
	if (current->left == nullptr && current->right == nullptr) {
		return true;
	}
	return false;
}
template<class T>						// use parameter
bool Tree<T>::is_leaf(Node<T>* node) {
	if (node == nullptr) { return true; }
	if (node->left == nullptr && node->right == nullptr) {
		return true;
	}
	return false;
}



// is empty
template<class T>
bool Tree<T>::is_empty() {
	if (tsize == 0) {
		return true;
	}	
	return false;
}



// operator overloads (but not actually)
// compare string key and current node keyword
template<class T>	
bool Tree<T>::key_is_greater(std::string key) {	// if current is lower alphabetical order than key
	std::string cur = get_key();
	std::string shorter;

	// find shorter word
	if (cur.size() < key.size()) { shorter = cur; }		
	else { shorter = key; }

	// compare
	for (int i=0; i<shorter.size(); i++) {
		if ((int)cur.at(i) > (int)key.at(i)) { return true; }		// cur < key (lower alphabetical)
		else if ((int)cur.at(i) < (int)key.at(i)) { return false; }	// cur > key (higher alphabetical)
	}
	return false;
}
template<class T>	
bool Tree<T>::key_is_less(std::string key) {	// if current is higher alphabetical order than key
	std::string cur = get_key();
	std::string shorter;

	// find shorter word
	if (cur.size() < key.size()) { shorter = cur; }		
	else { shorter = key; }

	// compare
	for (int i=0; i<shorter.size(); i++) {
		if ((int)cur.at(i) > (int)key.at(i)) { return false; }		// cur < key (lower alphabetical)
		else if ((int)cur.at(i) < (int)key.at(i)) { return true; }	// cur > key (higher alphabetical)
	}
	return false;
}
template<class T>	
bool Tree<T>::key_is_equal(std::string key) {	// if current node keyword equal to key
	std::string cur = get_key();

	// test length
	if (cur.size() < key.size() || cur.size() > key.size()) { return false; }

	// compare
	for (int i=0; i<key.size(); i++) {
		if ((int)cur.at(i) > (int)key.at(i) || (int)cur.at(i) < (int)key.at(i)) { // if not equal
			return false; 
		}
	}
	return true;
}

		
		

// --------- public functions --------- 


// insert
template<class T>
void Tree<T>::insert(T* item) {
	Node<T>* newitem = new Node<T>(item);

	if (is_empty()) {			// if first insert
		root = newitem;
		current = root;
		tsize++;
	}
	else {						// not first insert
		std::string key = item->word;
		current = root;
		Node<T>* parent;
		
		while(current != nullptr) {
			parent = current;

			if (key_is_greater(key)) { go_right(); }			// new key is greater than
			else if (key_is_less(key)) { go_left(); }			// new key is less than
			else if (key_is_equal(key)) { 						// new key is equal
				current->data = item;		
				delete newitem;				// if key already in tree, replace with new data
				break;
			}
		}

		if (current == nullptr) {			// if insert position found (no duplicates)
			current = parent;
			if (key_is_greater(key)) { current->right = newitem; }			// insert right
			else if (key_is_less(key)) { current->left = newitem; }			// insert left
			tsize++;
		}
	}
}




// remove
template<class T>
T* Tree<T>::remove(std::string key) {
	if (is_empty()) { return nullptr; }

	current = root;
	Node<T>* parent;
	Node<T>* temp = current;
	T* item;
	
	// find item to remove
	while(current != nullptr) {
		parent = temp;
		temp = current;

		if (key_is_greater(key)) { go_right(); }			// key is greater than
		else if (key_is_less(key)) { go_left(); }			// key is less than
		else if (key_is_equal(key)) { 						// key is equal
			current = parent;
			item = temp->data;

			if (key_is_greater(key)) { current->right = nullptr; }		// remove from tree right
			else if (key_is_less(key)) { current->left = nullptr; }		// remove from tree left

			// if item to remove is not a leaf -- re-sort
			if (!is_leaf(temp)) {			
				// re-sort children of removed item and everything below back into tree
				resort(temp->right);
				resort(temp->left);
				current = parent;
			}
			tsize--;
			delete temp;
			return item;
		}
	}
	return nullptr;
}



// find (by keyword)
// returns ptr to item with keyword
template<class T>
T* Tree<T>::find_item(std::string key) {
	if (is_empty()) { return nullptr; }

	current = root;
	while(current != nullptr && get_key() != key) {
		if (key_is_greater(key)) { go_right(); }			// key is greater than
		else if (key_is_less(key)) { go_left(); }			// key is less than
	}

	if (current != nullptr && get_key() == key) {
		return current->data;
	}
	return nullptr;
}
// find (by item)
// returns ptr to item with keyword
template<class T>
T* Tree<T>::find_item(T* item) {
	if (is_empty()) { return nullptr; }

	current = root;
	std::string key = item->word;
	while(current != nullptr && get_key() != key) {
		if (key_is_greater(key)) { go_right(); }			// key is greater than
		else if (key_is_less(key)) { go_left(); }			// key is less than
	}

	if (current != nullptr && get_key() == key) {		// if item does not match item found with same key
		current->data->freq = item->freq;			// update frequency
		return current->data;
	}
	return nullptr;
}



// get all ascending / descending
// returns static array of items (Data) in ascending alphabetical order (z to a)
template<class T>
T* Tree<T>::get_all_ascending() {
	static T arr[500];					// static array to return 
	int i = -1;

	get_ascending(root, &i, arr);
	return arr;
}
// returns static array of items (Data) in descending alphabetical order (a to z)
template<class T>
T* Tree<T>::get_all_descending() {
	static T arr[500];					// static array to return 
	int i = -1;

	get_descending(root, &i, arr);
	return arr;
}



// empty tree 
// delete all nodes in tree and free memory
template<class T>
void Tree<T>::empty_tree(Node<T>* node) {
	if(node != nullptr) {
		empty_tree(node->left);
		empty_tree(node->right);
		delete node;
	}	
}


