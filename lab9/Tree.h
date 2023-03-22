#include <string>

#pragma once




template<class T>
class Node {
	public:
		T* data;
		Node<T>* left;
		Node<T>* right;

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




	public:
		Tree();
		~Tree();

		// insert --
		void insert(T* item);
		// remove --
		T* remove(std::string key);


		// get right and left nodes
		T* get_value();
		Node<T>* go_right();
		Node<T>* go_left();

		// find item by id
		T* find(int id);

		// get depth of tree
		int get_depth();

		// get array of items in ascending / descending order by value
		T* get_ascending();
		T* get_descending();

		// empty tree -- remove all items
		void empty_tree();
		
		// if empty
		bool is_empty();
};