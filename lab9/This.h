#include <string>
#include <iostream>
#include <cmath>

#pragma once
using namespace std;




// node class for tree
class Node {
	public:
		int data;
		Node* left;
		Node* right;

		Node(int data_val) {	
			data = data_val;;
			right = nullptr;
			left = nullptr;
		}
		Node() {	
			data = 0;
			right = nullptr;
			left = nullptr;
		}
		~Node() { }
};






//-------------------------------------------------------------------------------------------------

int max(int x, int y) {
	if (x > y) {
		return x;
	} else {
		return y;
	}
}


#pragma once

// binary search tree
class Tree {
	private:
		int tsize;			// current number of nodes

		Node* root;

	public:
		Tree() {
			tsize = 0;
			root = nullptr;
		}
		~Tree() {
			empty(root);
		}
		int get_size() { return tsize; }
		int get_root() { return root->data; }

		Node* find(int item);
		Node* find(Node *node);



		Node* insert(Node *node, int item);
		void insert(int item);


		Node* balance(Node *node);
		int difference(Node *node);
		int height(Node *node);

		Node* ll_rotate(Node *node);
		Node* lr_rotate(Node *node);
		Node* rr_rotate(Node *node);
		Node* rl_rotate(Node *node);

		bool is_empty();
		void empty(Node *node);
};



////////////////////////////////////////////////////////////////////////////////////////





		












Node* Tree::find(int item) {

}
Node* Tree::find(Node *node) {

}








