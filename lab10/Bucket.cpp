#include <iostream>
#include <string>
#include "Bucket.h"

using namespace std;


// constructor
template<class T>
Bucket<T>::Bucket() {
	location = length = 0;
	head = tail = current = nullptr;
}
template<class T>
Bucket<T>::Bucket(int c) {
	capacity = c;
	location = length = 0;
	head = tail = current = nullptr;
}
// destructor
template<class T>
Bucket<T>::~Bucket() {
	empty_nodes();
}


// empty items
template<class T>
void Bucket<T>::empty_bucket() {
	reset();
	while (current->next != nullptr) {		// delete nodes
		go_next();
		delete current->prev->part;
	}
	delete current->part;
}

// empty nodes
template<class T>
void Bucket<T>::empty_nodes() {
	reset();
	while (current->next != nullptr) {		// delete nodes
		go_next();
		delete current->prev;
	}
	delete current;
}



// add item
template<class T>
void Bucket<T>::add_item(T* item) {
	Node<T>* newitem = new Node<T>(tail, item);		// allocate memory

	if (length == 0) { head = newitem; }			// for first item
	else { tail->next = newitem; }
	tail = newitem;

	length++;
}


// get item
template<class T>
T* Bucket<T>::get_item(string item) {
	reset();						// start at beginning of list
	
	// check conditions
	if (!in_bucket(item) || is_empty()) { return nullptr; }			// return null if item not in list
	
	// find item in list
	while (current != nullptr) {
		// remove item from list if found
		if (current->part->get_str_sku() == item) {
			return current->part;
		}
		go_next();
	}
	return nullptr;					// if item not found
}


// remove item
template<class T>
T* Bucket<T>::remove_item(string item) {
	reset();		// start at beginning of list
	
	// check conditions
	if (!in_bucket(item) || is_empty()) { return nullptr; }			// return null if item not in list

	// find item in list
	while (current != nullptr) {
		
		// remove item from list if found
		if (current->part->get_str_sku() == item) {
			Node<T>* skip = current->next;
			Node<T>* removed = current;	
			T* rm = removed->part;

			// remove item by modifying previous node next				
			if (removed == head) {				// if removed head
				head = removed->next;
				head->prev = nullptr;
			}
			else if (removed == tail) {			// if removed tail
				tail = removed->prev;
				tail->next = nullptr;
			}
			else {
				go_prev();
				current->next = skip;
				skip->prev = current;
			}


			length--;
			delete removed;			// delete removed node
			return rm;
		}
		go_next();
	}
	return nullptr;					// if item not found
}


// see next
template<class T>
T* Bucket<T>::see_next() {
	if (is_empty()) { throw "underflow error"; }			// throw underflow if empty

	location++;
	if (current->next == nullptr) { return nullptr; }
	go_next();

	return current->part;
}
// see previous
template<class T>
T* Bucket<T>::see_prev() {
	if (is_empty()) { throw "underflow error"; }			// throw underflow if empty

	location--;
	if (current->prev == nullptr) { return nullptr; }
	go_prev();

	return current->part;
}
// see at
template<class T>
T* Bucket<T>::see_at(int idx) {
	if (is_empty()) { throw "underflow error"; }			// throw underflow if empty
	location = idx;
	current = head;

	for (int i=0; i<idx; i++) {
		if (current->next == nullptr) {			// get item at location -- rtn nullptr if reach end of list
			return nullptr;
		}
		go_next();
	}
	return current->part;
}


// is in bucket
template<class T>
bool Bucket<T>::in_bucket(string find) {
	Node<T>* item = head;

	while (item != nullptr) {			// look for item in list
		if (item->part->get_str_sku() == find) {
			return true;
		}
		item = item->next;
	}
	return false;
}

// is empty
template<class T>
bool Bucket<T>::is_empty() {
	if (length == 0) {			// test if list empty
		return true;
	}
	return false;
}


// hash function (for the print function)
template<class T>
int Bucket<T>::hash_function(string str) {
	int sum = 0;
	for (int i=0; i<str.size(); i++) {
		sum += int(str.at(i));
	}
	return sum % capacity;
}


// display
template<class T>
void Bucket<T>::disp() {
	int idx = location;		
	reset();

	for (int i=0; i<length-1; i++) {
		std::cout << current->part->get_sku() << "(" << hash_function(to_string(current->part->get_sku())) << "), ";
		go_next();
	}
	std::cout << current->part->get_sku() << "(" << hash_function(to_string(current->part->get_sku())) << ")\n";

	see_at(idx);			// set location back for any see functions
}