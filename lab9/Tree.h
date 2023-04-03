#include <string>

# pragma once



// node class for tree
template<class T>
class Node {
	public:
		T* data;
		Node<T>* left;
		Node<T>* right;

		Node(T* data_val) {	
			data = data_val;
			right = nullptr;
			left = nullptr;
		}
		~Node() {}
};




// binary search tree
template<class T>
class Tree {
	private:
		int tsize;			// current number of nodes

		Node<T>* current;	// current position
		Node<T>* root;

	
		// get word / key
		std::string get_key() { return current->data->word; }
		std::string get_key(Node<T>* node) { return node->data->word; }

		// get right and left nodes (return ptr)
		Node<T>* get_right() { if (is_empty()) { return nullptr; } return current->right; }
		Node<T>* get_left() { if (is_empty()) { return nullptr; } return current->left; }
		// go right and left (update current)
		void go_right() { current = current->right; }
		void go_left() { current = current->left; }

		// re-sort (recursive helper function for remove)
		void resort(Node<T>* node);
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
		void insert(T* item);
		// remove
		T* remove(std::string key);
		// find
		T* find_item(std::string key);		// (by keyword)
		T* find_item(T* item);				// (by item -- if found, updates freq)

		// get size of tree
		int get_size() { return tsize; }

		// get array of items in ascending / descending order (alphabetical by keyword)
		T* get_all_ascending();		// (z to a)
		T* get_all_descending();	// (a to z)
		
		
		// delete tree and all nodes
		void empty_tree(Node<T>* node);
};