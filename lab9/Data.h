#include <string>

#pragma once


// class for holding data
class Data {
	public:
		std::string word;		// word / key
		int freq;				// word frequency

		Data () { }
		Data (std::string w, int f) {
			word = w;
			freq = f;
		}
};



/* 				// if need to balance	
				if (current->left == nullptr && current->right != nullptr) { 
					Node<T>* child_node = current->right;

					// current < child < key
					if (*child_node < key) { 
						child_node->right = newitem;
						child_node->left = current;
						if (*parent < current) { parent->right = child_node; }		// parent->right
						else if (*parent > current) { parent->left = child_node; }	// parent->left
					}
					// current < key < child
					else if (*child_node > key) {
						newitem->left = current;
						newitem->right = child_node;
						if (*parent < current) { parent->right = newitem; }			// parent->right
						else if (*parent > current) { parent->left = newitem; }		// parent->left
					}
					else { throw "item already in tree"; }
					current->right = nullptr;
					tsize++;
					break;
				}
				else { go_right(); } */


				/* 				if (current->right == nullptr && current->left != nullptr) { 
					Node<T>* child_node = current->left;

					// key < child < current
					if (*child_node > key) { 
						child_node->right = newitem;
						child_node->left = current;
						if (*parent < current) { parent->right = child_node; }		// parent->right
						else if (*parent > current) { parent->left = child_node; }	// parent->left
					}
					// child < key < current
					else if (*child_node < key) {
						newitem->left = current;
						newitem->right = child_node;
						if (*parent < current) { parent->right = newitem; }			// parent->right
						else if (*parent > current) { parent->left = newitem; }		// parent->left
					}
					else { throw "item already in tree"; }
					current->left = nullptr;
					tsize++;
					break;
				}
				else { go_left(); } */