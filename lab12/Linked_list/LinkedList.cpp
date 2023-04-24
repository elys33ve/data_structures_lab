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
bool List::isEmpty() {
	if (length == 0) {			// test if list empty
		return true;
	}
	return false;
}



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




// bubble sort --- firstname
void List::bubble_sort(int x) {
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







/*
// insertion sort
void Sort::insertion_sort(int arr[], int n) {
	// swap each 'new' item until it has correct placement
	int j, temp;
	for (int i=1; i<n; i++) {
		temp = arr[i];
		j = i - 1;

		// move elements greater than t
		while (j >= 0 && arr[j] > temp) {
			arr[j + 1] = arr[j];
			j = j - 1;
		} arr[j + 1] = temp;
	}
}








// radix sort
void Sort::radix_sort(int arr[]) {
	int n = length;

	// get max value
	int m = max(arr, n);
	
	// sort
	for (int i=1; m/i>0; i*=10) {
        int output[n], count[10];

		// set count to zeros
		for (int j=0; j<10; j++) { count[j] = 0; }

		// get count for arr elements
		for (int j=0; j<n; j++) {
			count[(arr[j] / i) % 10]++;
		}
		// get elements positions
		for (int j=1; j<10; j++) {
			count[j] += count[j - 1];
		}

		// order
		for (int j=n-1; j>=0; j--) {
			output[count[(arr[j] / i) % 10] - 1] = arr[j];
			count[(arr[j] / i) % 10]--;
		}

		// copy to original array
		for (int j=0; j<n; j++) {
			arr[j] = output[j];
		}
	}
}
 */


