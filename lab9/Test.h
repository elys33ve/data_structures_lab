#include <string>
#include <cmath>

#pragma once



// class for holding data
class Data {
	public:
		std::string word;		// word / key
		int freq;				// word frequency

		Data () { }
		Data (std::string w) {
			word = w;
			freq = 1;
		}
		Data (std::string w, int f) {
			word = w;
			freq = f;
		}
};



// node class for tree
template<class T>
class Node {
	public:
		T data;
		Node<T>* left;
		Node<T>* right;

		Node(T data_val) {	
			data = data_val;
			right = nullptr;
			left = nullptr;
		}
		~Node() { }

		bool operator<(std::string key);
		bool operator>(std::string key);
		bool operator==(std::string key);

		bool operator<(Node<T>* key);
		bool operator>(Node<T>* key);
		bool operator==(Node<T>* key);
};



// operator overloads
template<class T>	
bool Node<T>::operator<(std::string key) {	// if node is lower alphabetical order than key
	std::string cur = data.word;
	std::string shorter;
	char c, k;

	// find shorter word
	if (cur.size() < key.size()) { shorter = cur; }		
	else { shorter = key; }

	// compare
	for (int i=0; i<shorter.size(); i++) {
		c = tolower(cur.at(i)); k = tolower(key.at(i));
		if ((int)c > (int)k) { return true; }		// cur < key (lower alphabetical)
		else if ((int)c < (int)k) { return false; }	// cur > key (higher alphabetical)
	}
	
	if (key == cur) { return false; }
	if (key == shorter) { return true; }
	return false;
}
template<class T>	
bool Node<T>::operator>(std::string key) {	// if node is higher alphabetical order than key
	std::string cur = data.word;
	std::string shorter;
	char c, k;

	// find shorter word
	if (cur.size() < key.size()) { shorter = cur; }		
	else { shorter = key; }

	// compare
	for (int i=0; i<shorter.size(); i++) {
		c = tolower(cur.at(i)); k = tolower(key.at(i));
		if ((int)c > (int)k) { return false; }		// cur < key (lower alphabetical)
		else if ((int)c < (int)k) { return true; }	// cur > key (higher alphabetical)
	}
	
	if (key == cur) { return false; }
	if (key == shorter) { return false; }
	return true;
}
template<class T>	
bool Node<T>::operator==(std::string key) {	// if node keyword equal to key
	std::string cur = data.word;
	char c, k;

	// test length
	if (cur.size() < key.size() || cur.size() > key.size()) { return false; }

	// compare
	for (int i=0; i<key.size(); i++) {
		c = tolower(cur.at(i)); k = tolower(key.at(i));
		if ((int)c > (int)k || (int)c < (int)k) { // if not equal
			return false; 
		}
	}
	return true;
}




// operator overloads
template<class T>	
bool Node<T>::operator<(Node<T>* node) {	// if node is lower alphabetical order than key
	std::string cur = data.word;
	std::string key = node->data.word;
	std::string shorter;
	char c, k;

	// find shorter word
	if (cur.size() < key.size()) { shorter = cur; }		
	else { shorter = key; }

	// compare
	for (int i=0; i<shorter.size(); i++) {
		c = tolower(cur.at(i)); k = tolower(key.at(i));
		if ((int)c > (int)k) { return true; }		// cur < key (lower alphabetical)
		else if ((int)c < (int)k) { return false; }	// cur > key (higher alphabetical)
	}

	if (key == cur) { return false; }
	if (key == shorter) { return true; }
	return false;
}
template<class T>	
bool Node<T>::operator>(Node<T>* node) {	// if node is higher alphabetical order than key
	std::string cur = data.word;
	std::string key = node->data.word;
	std::string shorter;
	char c, k;

	// find shorter word
	if (cur.size() < key.size()) { shorter = cur; }		
	else { shorter = key; }

	// compare
	for (int i=0; i<shorter.size(); i++) {
		c = tolower(cur.at(i)); k = tolower(key.at(i));
		if ((int)c > (int)k) { return false; }		// cur < key (lower alphabetical)
		else if ((int)c < (int)k) { return true; }	// cur > key (higher alphabetical)
	}
	
	if (key == cur) { return false; }
	if (key == shorter) { return false; }
	return true;
}
template<class T>	
bool Node<T>::operator==(Node<T>* node) {	// if node keyword equal to key
	std::string cur = data.word;
	std::string key = node->data.word;
	char c, k;

	// test length
	if (cur.size() < key.size() || cur.size() > key.size()) { return false; }

	// compare
	for (int i=0; i<key.size(); i++) {
		c = tolower(cur.at(i)); k = tolower(key.at(i));
		if ((int)c > (int)k || (int)c < (int)k) { // if not equal
			return false; 
		}
	}
	return true;
}





//-------------------------------------------------------------------------------------------------






// binary search tree
template<class T>
class Tree {
	private:
		int tsize;			// current number of nodes

		Node<T>* current;	// current position
		Node<T>* root;


		// height
		int tree_height(Node<T>* h);
	
		// get word / key
		std::string get_key() { return current->data.word; }
		std::string get_key(Node<T>* node) { return node->data.word; }

		// get right and left nodes (return ptr)
		Node<T>* get_right() { if (is_empty()) { return nullptr; } return current->right; }
		Node<T>* get_left() { if (is_empty()) { return nullptr; } return current->left; }
		// go right and left (update current)
		void go_right() { current = current->right; }
		void go_left() { current = current->left; }

		// re-sort (recursive helper function for remove)
		void resort(Node<T>* node);
		// re-balance (in)
		void rebalance();
		// recursive helper functions for get all ascending / descending
		T* get_ascending(Node<T>* node, int* i, T arr[]);
		T* get_descending(Node<T>* node, int* i, T arr[]);

		// is leaf 
		bool is_leaf();
		bool is_leaf(Node<T>* node);
		// is empty
		bool is_empty();

		// key is greater, less, or equal to current keyword
		bool key_is_greater(std::string key);
		bool key_is_less(std::string key);
		bool key_is_equal(std::string key);

		
	public:
		// constructor / destructor
		Tree() {
			root = nullptr;
			current = nullptr;
			tsize = 0;
		}
		~Tree() { empty_tree(root);	}

		// insert
		void insert(T item);
		// remove
		T* remove(std::string key);
		// find
		T* find_item(std::string key);		// (by keyword)
		T* find_item(T item);				// (by item -- if found, updates freq)

		// get size of tree
		int get_size() { return tsize; }
		// get balanced height
		int get_height() { return log2(tsize)-1; } 
		// get current node data
		T get_current() { return current->data; }

		// get array of items in ascending / descending order (alphabetical by keyword)
		T* get_all_ascending();		// (z to a)
		void print_ascending();
		T* get_all_descending();	// (a to z)
		void print_descending();
		
		
		// delete tree and all nodes
		void empty_tree(Node<T>* node);
};




//-------------------------------------------------------------------------------------------------






// get all ascending
// returns static array of items (Data) in ascending alphabetical order (z to a)
template<class T>
T* Tree<T>::get_all_ascending() {
	static T arr[1024];					// static array to return 
	int i = -1;

	get_ascending(root, &i, arr);
	return arr;
}
// recursive helper function for get all ascending
template<class T>
T* Tree<T>::get_ascending(Node<T>* node, int* i, T arr[]) {
	if (is_empty()) { return nullptr; }

	if (node != nullptr) {
		get_ascending(node->left, i, arr);			// get lower keywords
		*i += 1;
		arr[*i] = node->data;
		get_ascending(node->right, i, arr);			// get higher keywords
	}
	return nullptr;
}
// print ascending
template<class T>
void Tree<T>::print_ascending() {
	T* arr = get_all_ascending();
	T x;

	for (int i=0; i<tsize; i++) {
		x = *(arr + i);
		std::cout << x.word << std::endl;
	}
}



// get all descending
// returns static array of items (Data) in descending alphabetical order (a to z)
template<class T>
T* Tree<T>::get_all_descending() {
	static T arr[1024];					// static array to return 
	int i = -1;

	get_descending(root, &i, arr);
	return arr;
}
// recursive helper function for get all descending
template<class T>
T* Tree<T>::get_descending(Node<T>* node, int* i, T arr[]) {
	if (is_empty()) { return nullptr; }

	if (node != nullptr) {
		get_descending(node->right, i, arr);		// get higher keywords
		*i += 1;
		arr[*i] = node->data;
		get_descending(node->left, i, arr);			// get lower keywords
	}
	return nullptr;
}
// print descending
template<class T>
void Tree<T>::print_descending() {
	T* arr = get_all_descending();
	T x;

	for (int i=0; i<tsize; i++) {
		x = *(arr + i);
		std::cout << x.word << std::endl;
	}
}



// find (by keyword)
// returns ptr to item with keyword
template<class T>
T* Tree<T>::find_item(std::string key) {
	if (is_empty()) { return nullptr; }

	// search for item
	current = root;
	while(current != nullptr && get_key() != key) {
		if (key_is_greater(key)) { go_right(); }			// key is greater than
		else if (key_is_less(key)) { go_left(); }			// key is less than
	}

	// if found
	if (current != nullptr && get_key() == key) {
		return &current->data;
	}
	return nullptr;
}
// find (by item)
// returns ptr to item with keyword
template<class T>
T* Tree<T>::find_item(T item) {
	if (is_empty()) { return nullptr; }

	// search for item
	current = root;
	std::string key = item.word;
	while(current != nullptr && get_key() != key) {
		if (key_is_greater(key)) { go_right(); }			// key is greater than
		else if (key_is_less(key)) { go_left(); }			// key is less than
		else { throw ":|"; }
	}

	// if item is found in tree
	if (current != nullptr && get_key() == key) {		
		current->data.freq += 1;			// increment frequency
		return &current->data;
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



// insert
template<class T>
void Tree<T>::insert(T item) {
	Node<T>* newitem = new Node<T>(item);

	if (is_empty()) {			// if first insert
		root = newitem;
		current = root;
		tsize++;
	}
	else {						// not first insert
		std::string key = item.word;
		current = root;
		Node<T>* parent;

		while(current != nullptr) {
			parent = current;
			
			// new key is greater than
			if (key_is_greater(key)) { go_right(); }	
			// new key is less than
			else if (key_is_less(key)) { go_left(); }
			// new key is equal	
			else if (key_is_equal(key)){ 							
				delete newitem;				// if key already in tree, throw error
				throw "item already in tree";
			}
			else { throw "what the fuck"; }
		}
		

		// if didn't need balancing
		if (current == nullptr) {			// if insert position found (no duplicates)
			current = parent;
			if (key_is_greater(key)) { current->right = newitem; }			// insert right
			else if (key_is_less(key)) { current->left = newitem; }			// insert left
			tsize++;
		}
	}
}



// re-balance
template<class T>
void Tree<T>::rebalance() {
	std::cout << get_height() << std::endl;
}



// remove
template<class T>
T* Tree<T>::remove(std::string key) {
	if (is_empty()) { return nullptr; }

	current = root;
	Node<T>* parent;
	Node<T>* temp = current;
	T item;
	
	// find item to remove
	while(current != nullptr) {
		parent = temp;
		temp = current;

		if (key_is_greater(key)) { go_right(); }			// key is greater than
		else if (key_is_less(key)) { go_left(); }			// key is less than
		else if (key_is_equal(key)) { 						// key is equal
			current = parent;
			item = temp.data;

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
			return &item;
		}
	}
	return nullptr;
}



// re-sort
// recursive helper function for remove -- re-sorts 
template<class T>
void Tree<T>::resort (Node<T>* node) {
	if(node != nullptr) {						// recursion until node is nullptr
		std::string key = node->data.word;
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



// is empty
template<class T>
bool Tree<T>::is_empty() {
	if (tsize == 0) {
		return true;
	}	
	return false;
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



// operator overloads (but not actually)
// compare string key and current node keyword
template<class T>	
bool Tree<T>::key_is_greater(std::string key) {	// if current is lower alphabetical order than key
	std::string cur = get_key();
	std::string shorter;
	char c, k;

	// find shorter word
	if (cur.size() < key.size()) { shorter = cur; }		
	else { shorter = key; }

	// compare
	for (int i=0; i<shorter.size(); i++) {
		c = tolower(cur.at(i)); k = tolower(key.at(i));
		if ((int)c > (int)k) { return true; }		// cur < key (lower alphabetical)
		else if ((int)c < (int)k) { return false; }	// cur > key (higher alphabetical)
	}

	if (key == cur) { return false; }
	if (key == shorter) { return true; }
	return false;
}
template<class T>	
bool Tree<T>::key_is_less(std::string key) {	// if current is higher alphabetical order than key
	std::string cur = get_key();
	std::string shorter;
	char c, k;

	// find shorter word
	if (cur.size() < key.size()) { shorter = cur; }		
	else { shorter = key; }

	// compare
	for (int i=0; i<shorter.size(); i++) {
		c = tolower(cur.at(i)); k = tolower(key.at(i));
		if ((int)c > (int)k) { return false; }		// cur < key (lower alphabetical)
		else if ((int)c < (int)k) { return true; }	// cur > key (higher alphabetical)
	}
	
	if (key == cur) { return false; }
	if (key == shorter) { return false; }
	return true;
}
template<class T>	
bool Tree<T>::key_is_equal(std::string key) {	// if current node keyword equal to key
	std::string cur = get_key();
	char c, k;

	// test length
	if (cur.size() < key.size() || cur.size() > key.size()) { return false; }

	// compare
	for (int i=0; i<key.size(); i++) {
		c = tolower(cur.at(i)); k = tolower(key.at(i));
		if ((int)c > (int)k || (int)c < (int)k) { // if not equal
			return false; 
		}
	}
	return true;
}