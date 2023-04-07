#include <iostream>
#include <string>
#include "This.h"

using namespace std;







Node* Tree::rr_rotate(Node *node) {
	Node *a, *b, *c;

	c = node;
	a = node->right;
	b = node->right->left;

	a = b;
	b = c;

	cout << "Right-Right Rotation";
	return node;
}
Node* Tree::ll_rotate(Node *node) {
   Node *a, *b, *c;

   a = node;
   c = node->left;
   b = node->left->right;

   c = b;
   b = a;

   cout << "Left-Left Rotation";
   return node;
}
Node* Tree::lr_rotate(Node *node) {
   Node *x;

   x = node->left;
   node->left = rr_rotate(x);
   
   cout<<"Left-Right Rotation";
   return ll_rotate(node);
}
Node* Tree::rl_rotate(Node *node) {
   Node *x;

   x = node->right;
   node->right = ll_rotate(x);

   cout<<"Right-Left Rotation";
   return rr_rotate(node);
}



int Tree::difference(Node *node) {
	int l_height = height(node->left);
	int r_height = height(node->right);

	int diff = l_height - r_height;
	return diff;
}


int Tree::height(Node *node) {
	int h = 0;

	if (node != nullptr) {
		int l_height = height(node->left);
		int r_height = height(node->right);
		int max_height = max(l_height, r_height);
		h = max_height + 1;
	}
	return h;
}



void Tree::insert(int item) {
	cout << "add " << item << endl;

	Node *n = insert(root, item);
}


Node* Tree::insert(Node *node, int item) {
	
	if (is_empty()) {
		node = new Node(item);
		root = node;
		tsize++;
		return node;
	}

	if (node == nullptr) {
		node = new Node(item);
		tsize++;
		return node;
	}
	else if (item < node->data) {
		node->left = insert(node->left, item);
		node = balance(node);
	}
	else if (item >= node->data) {
		node->right = insert(node->right, item);
		node = balance(node);
	}
	return node;
}







Node* Tree::balance(Node *node) {
	int bal_factor = difference(node);

	if (bal_factor > 1) {
		if (difference(node->left) > 0) {
			node = ll_rotate(node);
		}
		else {
			node = lr_rotate(node);
		}
	}
	else if (bal_factor < -1) {
		if (difference(node->right) > 0) { 
			node = rl_rotate(node); 
		}
		else { 
			node = rr_rotate(node); 
		}
	}
	return node;
}











// is empty
bool Tree::is_empty() {
	if (tsize == 0) {
		return true;
	}	
	return false;
}


// empty tree
void Tree::empty(Node *node) {
	if (node != nullptr) {
		empty(node->left);
		empty(node->right);
		delete node;
	}
}