#include <string>

#pragma once


template<class T>
class Node {
	public:
		T* data;
		Node<T>* left;
		Node<T>* right;

		Node();
		Node(T* data_val);
		~Node();
};



// binary search tree,, avl algorithm

template<class T>
class Tree {
	private:
		int size;
		int idx;

		Node<T>* current;
		Node<T>* root;

		


		// get word / key
		std::string get_key() { return current->data->word; }
		std::string get_key(Node<T>* node) { return node->data->word; }

		// get right and left nodes
		Node<T>* get_right();
		Node<T>* get_left();
		// go right and left (update current)
		void go_right() { current = current->right; }
		void go_left()  { current = current->left; }

		// is leaf
		bool is_leaf();
		bool is_leaf(Node<T>* node);


	public:
		Tree();
		~Tree();

		// insert
		void insert(T* item);

		// get size of tree
		int get_size() { return size; }
		
		// if empty
		bool is_empty();
		
};




/*


template<class T>
class Tree {
	private:
		int size;
		int idx;

		Node<T>* current;
		Node<T>* root;

		
		// find item by keyword
		Node<T>* find(std::string key);

		// get word / key
		std::string get_key() { return current->data->word; }
		std::string get_key(Node<T>* node) { return node->data->word; }

		// get right and left nodes
		Node<T>* get_right();
		Node<T>* get_left();
		// go right and left (update current)
		void go_right() { current = current->right; }
		void go_left()  { current = current->left; }

		// is leaf
		bool is_leaf();
		bool is_leaf(Node<T>* node);

		// key is less or greater than current
		bool key_is_greater(std::string key);
		bool key_is_less(std::string key);

	public:
		Tree();
		~Tree();

		// insert --
		void insert(T* item);
		// remove --
		T* remove(std::string key);

		// get size of tree
		int get_size() { return size; }

		// get array of items in ascending / descending order by value
		T* get_ascending();
		T* get_descending();

		// empty tree -- remove all items
		void empty_tree();
		
		// if empty
		bool is_empty();
		

		// operator overloads 
		bool operator==(std::string key);
		bool operator<(std::string key);
		bool operator>(std::string key);
		
};


*/