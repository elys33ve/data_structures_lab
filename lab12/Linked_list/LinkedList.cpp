#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Info.h"
#include "Node.h"

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
bool List::is_empty() {
	if (length == 0) {			// test if list empty
		return true;
	}
	return false;
}


// print list from head
void List::print_list() {
	if (length == 0) { return; }
	string fname, lname, t1, t2;

	Node *node = head;
	for (int i=0; i<length; i++) {
		fname = node->data->firstname;
		lname = node->data->lastname;
		t1 = t2 = "\t\t";
		if (fname.size() >= 8) { t1 = "\t"; }		// adjust tabs
		if (lname.size() >= 8) { t2 = "\t"; }

		cout << fname << t1 << lname << t2;
		cout << node->data->id_number << "\n";
		if (node->next != nullptr) { node = node->next; }
		else { return; }
	}
}
// print list from parameter (for debugging)
void List::print_list(Node *node) {
	string fname, lname, t1, t2;

	if (node != nullptr) {
		fname = node->data->firstname;
		lname = node->data->lastname;
		t1 = t2 = "\t\t";
		if (fname.size() >= 8) { t1 = "\t"; }		// adjust tabs
		if (lname.size() >= 8) { t2 = "\t"; }

		cout << fname << t1 << lname << t2;
		cout << node->data->id_number << "\n";
		print_list(node->next);
	}
}





// find by id
Node *List::find(int id_num) {
	if (is_empty()) { return nullptr; }
	Node *node = head;

	// find node w id
	while (node != nullptr) {
		if (node->data->id_number == id_num) { return node; } 	// found
		node = node->next;
	}
	return nullptr;
}




//////////////////////////////////// compare words alphabetical


// true if (a, z)
bool List::higher(string word1, string word2) {	// if lower alphabetical order than word2
	string shorter;
	char c, k;

	// find shorter word
	if (word1.size() < word2.size()) { shorter = word1; }		
	else { shorter = word2; }

	// compare
	for (int i=0; i<shorter.size(); i++) {
		c = tolower(word1.at(i)); k = tolower(word2.at(i));
		if ((int)c > (int)k) { return true; }		// word1 < word2 (lower alphabetical)
		else if ((int)c < (int)k) { return false; }	// word1 > word2 (higher alphabetical)
	}

	if (word2 == word1) { return false; }
	if (word2 == shorter) { return true; }
	return false;
}



// true if (z, a)
bool List::lower(string word1, string word2) {	
	string shorter;
	char c, k;

	// find shorter word
	if (word1.size() < word2.size()) { shorter = word1; }		
	else { shorter = word2; }

	// compare
	for (int i=0; i<shorter.size(); i++) {
		c = tolower(word1.at(i)); k = tolower(word2.at(i));
		if ((int)c > (int)k) { return false; }		// word1 < word2 (lower alphabetical)
		else if ((int)c < (int)k) { return true; }	// word1 > word2 (higher alphabetical)
	}
	
	if (word2 == word1) { return false; }
	if (word2 == shorter) { return false; }
	return true;
}



// true if (a, a)
bool List::same(string word1, string word2) {	
	char c, k;

	// test length
	if (word1.size() < word2.size() || word1.size() > word2.size()) { return false; }

	// compare
	for (int i=0; i<word2.size(); i++) {
		c = tolower(word1.at(i)); k = tolower(word2.at(i));
		if ((int)c > (int)k || (int)c < (int)k) { 				// if not equal
			return false; 
		}
	}
	return true;
}







///////////// sorting functions


// swap
void List::swap(Node *x, Node *y) {
	Info *xi = x->data;
	Info *yi = y->data;
	x->data = yi;
	y->data = xi;
}

// max
Node *List::max() {
	if (is_empty()) { return nullptr; }
	int num, m = head->data->id_number;
	Node *current = head;

	while (current != nullptr) {
		num = current->data->id_number;
		if (num > m) {
			m = num;
		}
		current = current->next;
	}
	return find(m);
}


// bubble sort --- firstname
void List::bubble_sort(int x) {
	if (is_empty()) { return; }
	Node *current, *n1, *n2;
	int n_swap;

	for (int i=0; i<length; i++) {
		n_swap = 0;
		current = head;

		for (int j=0; j<length-i-1; j++) {
			n1 = current;
			n2 = n1->next;

			// descending order (a -> z)
			if (x == 1 && higher(n1->data->firstname, n2->data->firstname)) {
				swap(n1, n2);
				n_swap++;
			}
			// ascending order (z -> a)
			if (x == 0 && lower(n1->data->firstname, n2->data->firstname)) {
				swap(n1, n2);
				n_swap++;
			}
			current = current->next;
		}

		if (n_swap == 0) { break; }
	}
}






// insertion sort
void List::insertion_sort(int x) {
	if (is_empty()) { return; }
	Node *temp, *sort, *current, *n2;
	
	temp = nullptr;
	current = head;
	
	while (current != nullptr) {
		n2 = current->next;

		// sort descending
		if (x == 1) {
			if (temp == nullptr || !lower(temp->data->lastname, current->data->lastname)) {
				current->next = temp;
				temp = current;
			} else {
				sort = temp;
				while (sort->next != nullptr && lower(sort->next->data->lastname, current->data->lastname)) {
					sort = sort->next;
				}
				current->next = sort->next;
				sort->next = current;
			}
		} 
		// sort ascending
		else if (x == 0) {
			if (temp == nullptr || !higher(temp->data->lastname, current->data->lastname)) {
				current->next = temp;
				temp = current;
			} else {
				sort = temp;
				while (sort->next != nullptr && higher(sort->next->data->lastname, current->data->lastname)) {
					sort = sort->next;
				}
				current->next = sort->next;
				sort->next = current;
			}
		}
		current = n2;
	}
	head = temp;
}





// merge sort
void List::merge_sort(Node **head_ref, int x) {
	Node *n1, *n2, *h = *head_ref;
	if (h == nullptr || h->next == nullptr) { return; }

	// split into sublists
	Node *s1 = h->next, *s2 = h;
    while (s1 != nullptr) {
        s1 = s1->next;
        if (s1 != nullptr) {
            s2 = s2->next;
            s1 = s1->next;
        }
    }
    n1 = h;
    n2 = s2->next;
	s2->next = nullptr;

	// recursively sort sublists
	merge_sort(&n1, x);
	merge_sort(&n2, x);

	// merge sorted lists
	*head_ref = sorted_merge(n1, n2, x);
}
// mere sublists together
Node *List::sorted_merge(Node *n1, Node *n2, int x) {
	if (n1 == nullptr) { return n2; }
	if (n2 == nullptr) { return n1; }
	Node *sorted;

	// descending order
	if (x == 0) {
		if (n1->data->id_number <= n2->data->id_number) {
			sorted = n1;
			sorted->next = sorted_merge(n1->next, n2, x);
		} else {
			sorted = n2;
			sorted->next = sorted_merge(n1, n2->next, x);
		}
	}
	// ascending order
	if (x == 1) {
		if (n1->data->id_number >= n2->data->id_number) {
			sorted = n1;
			sorted->next = sorted_merge(n1->next, n2, x);
		} else {
			sorted = n2;
			sorted->next = sorted_merge(n1, n2->next, x);
		}
	}
	return sorted;
}


