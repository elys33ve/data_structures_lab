#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;



// constructor
List::List() {
	location = length = 0;
	head = nullptr;
}
// destructor
List::~List() {	
	Node *node = head;
	while (node != nullptr && node->next != nullptr) {		// delete nodes
		node = node->next;
		delete node->prev;
	}
	delete node;
}



// add item
void List::addItem(Info* item) {
	Node *newitem = new Node(item);		// allocate memory

	// first item
	if (length == 0) { 
		head = newitem;
		length++;
		return;
	}

	// not first item
	Node *node = head;
	while (node != nullptr && node->next != nullptr) {
		node = node->next;
	}
	// add link
	node->next = newitem;
	length++;
}




// is empty
bool List::isEmpty() {
	if (length == 0) {			// test if list empty
		return true;
	}
	return false;
}



void List::print_list() {
	if (length == 0) { return; }

	Node *node = head;
	for (int i=0; i<length; i++) {
		cout << node->data->firstname << " ";
		cout << node->data->lastname << " ";
		cout << node->data->id_number << "\n";
		if (node->next != nullptr) { node = node->next; }
		else { return; }
	}
}
