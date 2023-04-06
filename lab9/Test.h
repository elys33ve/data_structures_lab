#include <string>
#include <cmath>

#pragma once
using namespace std;



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
			data = data_val;;
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



// operator overloads (str)
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




// operator overloads (class)
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
		// get height (at root)
		int get_height() { return height(root); } 
		// get difference in subtrees (at root)
		int get_difference() { return difference(root); }
		// get current or root node data
		T get_current() { return current->data; }
		T get_root() { return root->data; }

		// get array of items in ascending / descending order (alphabetical by keyword)
		T* get_all_ascending();		// (z to a)
		void print_ascending();
		T* get_all_descending();	// (a to z)
		void print_descending();
		
		
		// delete tree and all nodes
		void empty_tree(Node<T>* node);


		void x();

		void show(Node<T>* node, int l);
		Node<T>* iinsert(Node<T>* node, T item);
		Node<T>* balance(Node<T>* node);
		int difference(Node<T>* t);
		
		int height(Node<T> *node);



		Node<T> *ll_rotate(Node<T> *node);
		Node<T> *lr_rotate(Node<T> *node);
		Node<T> *rr_rotate(Node<T> *node);
		Node<T> *rl_rotate(Node<T> *node);

		Node<T>* insert(Node<T>* node,  T item);
		void tst(Node<T> *n);
		Node<T>* find_parent(Node<T> *node);
};




//-------------------------------------------------------------------------------------------------

int max(int x, int y) {
	if (x > y) { return x; }
	else { return y; }
}


template<class T>
Node<T> *Tree<T>::ll_rotate(Node<T> *node) {
	// C<-B<-A	=>	C<-B->A
	Node<T> *parent = node->left;
	Node<T> *l_child = node->left->left;

	node->left = parent->right; 
	parent->right = node;
	parent->left = l_child; 
	return parent;
}
template<class T>
Node<T> *Tree<T>::lr_rotate(Node<T> *node) {
	// B->C<-A	=>	C<-B->A
	Node<T> *l_child = node->left;
	Node<T> *parent = node->left->right;
	
	node->left = parent->right;
	parent->right = node;
	parent->left = l_child;
	return parent;
}
template<class T>
Node<T> *Tree<T>::rr_rotate(Node<T> *node) {
	// C->B->A	=>	C<-B->A
	Node<T> *parent = node->right;
	Node<T> *r_child = node->right->right;
	
	node->right = parent->left;
	parent->left = node;
	parent->right = r_child;
	return parent;
}
template<class T>
Node<T> *Tree<T>::rl_rotate(Node<T> *node) {
	// A->C<-B	=>	C<-B->A
	Node<T> *r_child = node->right;
	Node<T> *parent = node->right->left;

	node->right = parent->left;
	parent->left = node;
	parent->right = r_child;
	return parent;
}


template<class T>
int Tree<T>::difference(Node<T> *node) {
	// get left and right subtree heights
	int l_height = height(node->left);
	int r_height = height(node->right);

	// get difference (diff = balance left > 0 > balance right)
	int diff = l_height - r_height;
	return diff;
}

template<class T>
int Tree<T>::height(Node<T> *node) {
   int h = 0;
   if (node != nullptr) {
      int l_height = height(node->left);
      int r_height = height(node->right);
      int max_height = max(l_height, r_height);
      h = max_height + 1;
   }
   return h;
}

template<class T>
void Tree<T>::x() {
	//Node<T> *b = balance(root);
	tst(root);
}


template<class T>
void Tree<T>::tst(Node<T> *n) {
	if (n !=nullptr && !is_leaf(n)) {
		cout << n->data.word << "   l: ";
		if (n->left != nullptr){ cout << n->left->data.word; }
		else {cout << "null";} cout << "   r: ";
		if (n->right != nullptr) { cout << n->right->data.word; }
		else {cout << "null";} cout << endl;

		tst(n->right);
		tst(n->left);
	}	
}


template<class T>
Node<T>* Tree<T>::balance(Node<T>* node) {
	int diff = difference(node);
	Node<T> *parent = node;


	if (node == nullptr) { return node; }
	
	


	// balance left
	if (diff >= 1) { 
		diff = difference(node->left); 
		
		if (height(node) > 2) {
			node->left = balance(node->left);
		}
		else if (diff > 0) {				// left left
			cout << "ll\n";
			parent = ll_rotate(node);
			cout << parent->right->data.word << " " << parent->left->data.word << endl;
		}
		else if (diff < 0) {		// left right
			cout << "lr\n";
			parent = lr_rotate(node);
		}
	}
	// balance right
	else if (diff <= -1) {
		diff = difference(node->right);	
		
		if (height(node) > 2) {
			node->right = balance(node->right);
		}
		else if (diff < 0) {				// right right
			cout << "rr\n";
			parent = rr_rotate(node);
		}
		else if (diff > 0) {		// right left
			cout << "rl\n";
			parent = rl_rotate(node);
		}
	}
	else { return node;	}	// no difference

	if (*root == node->data.word) { root = parent; }
	return parent;
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
		Node<T>* temp;

		while(current != nullptr) {
			parent = current;
			
			// new key is greater than
			if (*current < key) { go_right(); }	
			// new key is less than
			else if (*current > key) { go_left(); }
			// new key is equal	
			else if (*current == key){ 							
				delete newitem;				// if key already in tree, throw error
				throw "item already in tree";
			}
			else { throw "what the fuck"; }
		}
		

		if (current == nullptr) {			// if insert position found (no duplicates)
			current = parent;
			if (*current < key) { 
				current->right = newitem;
			}			// insert right
			else if (*current > key) { 
				current->left = newitem; 
			}			// insert left
			tsize++;
		}
		parent = find_parent(current); 
		Node<T> *b = balance(root);
	}
}



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
		if (*current < key) { go_right(); }			// key is greater than
		else if (*current > key) { go_left(); }			// key is less than
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
		if (*current < key) { go_right(); }				// key is greater than
		else if (*current > key) { go_left(); }			// key is less than
		else { break; }
	}

	// if item is found in tree
	if (current != nullptr && get_key() == key) {		
		current->data.freq += 1;			// increment frequency
		return &current->data;
	}

	return nullptr;
}

template<class T>
Node<T>* Tree<T>::find_parent(Node<T> *node) {
	if (is_empty()) { return nullptr; }

	if (node == root) { return root;	}

	// search for item
	current = root;
	std::string key = node->data.word;
	while(current != nullptr && get_key() != key) {
		if (current->left == node || current->right == node) { return current; }

		if (*current < key) { go_right(); }				// key is greater than
		else if (*current > key) { go_left(); }			// key is less than
		else { return current; }
	}
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

		if (*current < key) { go_right(); }			// key is greater than
		else if (*current > key) { go_left(); }			// key is less than
		else if (*current == key) { 						// key is equal
			current = parent;
			item = temp.data;

			if (*current < key) { current->right = nullptr; }		// remove from tree right
			else if (*current > key) { current->left = nullptr; }		// remove from tree left

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

			if (*current < key) { go_right(); }			// key is greater than
			else if (*current > key) { go_left(); }			// key is less than
			else { return; }
		}

		// insert
		current = parent;
		if (*current < key) { current->right = node; }			// insert right
		else if (*current > key) { current->left = node; }		// insert left

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
