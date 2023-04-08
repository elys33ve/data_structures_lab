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

		Node<T>* root;

		// recursive helper functions for get all ascending / descending
		T* get_ascending(Node<T>* node, int* i, T arr[]);
		T* get_descending(Node<T>* node, int* i, T arr[]);

		// is leaf 
		bool is_leaf(Node<T>* node);
		// is empty
		bool is_empty();

	public:
		// constructor / destructor
		Tree() {
			root = nullptr;
			tsize = 0;
		}
		~Tree() { empty_tree(root);	}

		// insert
		void insert(T item);
		Node<T>* insert(Node<T>* node,  T item);
		// remove
		T* remove(std::string key);
		Node<T>* remove(Node<T> *node);
		// find
		T* find(T item);	// increments freq
		T find(std::string key) { return find(root, key)->data; }
		Node<T>* find(Node<T>* node, std::string key);


		// get size of tree
		int get_size() { return tsize; }
		// get height (at root)
		int get_height() { return height(root); } 
		// get difference in subtrees (at root)
		int get_difference() { return difference(root); }
		// get root node data
		T get_root() { return root->data; }



   	 	void balance();


		// get array of items in ascending / descending order (alphabetical by keyword)
		T* get_all_ascending();		// (z to a)
		void print_ascending();
		T* get_all_descending();	// (a to z)
		void print_descending();
		
	
		// delete tree and all nodes
		void empty_tree(Node<T>* node);


		// get difference between left and right node heights
		int difference(Node<T>* node);
		// get height of node
		int height(Node<T> *node);
		// correct height if balanced
		int corr_height() { return log2(tsize) + 1; }

		// rotate functions for balance
		Node<T> *rotate_l(Node<T> *node);
		Node<T> *rotate_rl(Node<T> *node);
		Node<T> *rotate_r(Node<T> *node);
		Node<T> *rotate_lr(Node<T> *node);

		
		void show() {
			print_info();
			print_nodes(root);
		}
		void print_info() { 
			cout << "size: " << get_size() << "\t\t\t" << "root: " << get_root().word << endl;
			cout << "diff: " << get_difference() << "\t\t\t" << "height: " << get_height() << endl;
		}
		void print_nodes(Node<T> *n) {
			if (n !=nullptr && !is_leaf(n)) {
				cout << n->data.word << "   l: ";
				if (n->left != nullptr){ cout << n->left->data.word; }
				else {cout << "null";} cout << "   r: ";
				if (n->right != nullptr) { cout << n->right->data.word; }
				else {cout << "null";} cout << endl;

				print_nodes(n->right);
				print_nodes(n->left);
			}
			else if (n != nullptr && is_leaf(n)) {
				cout << n->data.word << " is leaf\n";
			}
		}
		
};




//-------------------------------------------------------------------------------------------------

int max(int x, int y) {
	if (x > y) { return x; }
	else { return y; }
}


// rotate left
template<class T>
Node<T> *Tree<T>::rotate_l(Node<T> *node) {
	Node<T> *x, *z, *t23;
	x = node;
	z = node->right;
    if (z != nullptr) {
        t23 = node->right->left; 
	}
    else {
        t23 = nullptr;
	}

	x->right = t23;
	z->left = x;

	return z;
}
// rotate right
template<class T>
Node<T> *Tree<T>::rotate_r(Node<T> *node) {
	Node<T> *x, *z, *t23;
    x = node;
    z = node->left;
    if (z != nullptr) { 
		t23 = node->left->right;
	}
	else { 
		t23 = nullptr; 
	}

	x->left = t23;
    z->right = x;

	return z;
}
// rotate right left
template<class T>
Node<T> *Tree<T>::rotate_rl(Node<T> *node) {
	Node<T> *x, *y, *z, *t2, *t3;
    x = node;
    z = node->right;
    y = node->right->left;
    if (y != nullptr) {
        t2 = y->left;
        t3 = y->right;
    }
    else {
        t2 = nullptr;
        t3 = nullptr;
    }

    x->right = t2;
    y->left = x;
    y->right = z;
    z->left = t3;

	return y;
}
// rotate left right
template<class T>
Node<T> *Tree<T>::rotate_lr(Node<T> *node) {
	Node<T> *x, *y, *z, *t2, *t3;
    x = node;
    z = node->left;
    y = node->left->right;
    if (y != nullptr) {
        t2 = y->right;
        t3 = y->left;
    }
    else {
        t2 = nullptr;
        t3 = nullptr;
    }

    x->left = t2;
    y->right = x;
    y->left = z;
    z->right = t3;

	return y;
}


// balance
template<class T>
void Tree<T>::balance() {
	int diff = difference(root);
    int diff_l = difference(root->left);
    int diff_r = difference(root->right);

	if (diff > 1) {							// right height larger
        if (diff_r >= 0)
            root = rotate_l(root);
        else
            root = rotate_rl(root);
    }
    else if (diff < -1) { 			// left height larger
        if (diff_l <= 0)
            root = rotate_r(root);
        else
            root = rotate_lr(root);
    }
}

// defference
template<class T>
int Tree<T>::difference(Node<T> *node) {
	int l_height;
	int r_height;

    if (node == nullptr) {
        return 0;
	}

    if (node->left != nullptr) {		// get left
        l_height = height(node->left);
	} else {
        l_height = 0;
	}

    if (node->right != nullptr) {		// get right
        r_height = height(node->right);
	} else {
        r_height = 0;
	}
    
	int diff = r_height - l_height;
	return diff;
}


// height
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


// insert (main)
template<class T>
void Tree<T>::insert(T item) {
	Node<T> *n = insert(root, item);

	if (n == nullptr) {
		throw "cannot insert item";
	}
    balance();
}
template<class T>
Node<T>* Tree<T>::insert(Node<T> *node, T item) {	
	std::string key = item.word;
	if (is_empty()) {
		node = new Node<T>(item);
		root = node;
		tsize++;
		return node;
	}

	if (node == nullptr) {
		node = new Node<T>(item);
		tsize++;
		return node;
	}
	else if (*node < key) {
		node->left = insert(node->left, item);
	}
	else if (*node > key) {
		node->right = insert(node->right, item);
	}
	else { return nullptr; }
	return node;
}




// find (rtns node)
template<class T>
Node<T>* Tree<T>::find(Node<T> *node, std::string key) {
	if (is_empty()) { return nullptr; }

	// search for item
	if(node != nullptr && node->data.word != key) {
		if (*node < key) { find(node->right, key); }			// key is greater than
		else if (*node > key) { find(node->left, key); }		// key is less than
		else if (*node == key) { return node; }			// key found
	}
	return nullptr;
}
// find (by Data and increments if found)
template<class T>
T* Tree<T>::find(T item) { 
	Node<T> *node = find(root, item.word);
	
	if (node != nullptr) {		// incr freq
		node->data.freq += 1;
	}
	return &node->data; 
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


// is leaf
template<class T>
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
