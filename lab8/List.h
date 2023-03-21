#pragma once


/*
	ordered linked list template class:
		- overloaded >, <, and == operators
		- items passed to/from the class should be pointers
		- ensure there are no memory leaks
*/

template<class T>
struct Node {
	public:
		T* part;
		Node* prev;
		Node* next;
};


template<class T>
class List {
	private:
		int location;
		int length;

		Node<T>::Node head;
		Node<T>::Node tail;
		Node<T>::Node current;

	public:
		List();
		~List();

		// add item -- add item to list
		void addItem(T* item);
		// get item -- removes item if found in list and returns pointer
		T* getItem(T* item);

		// see next -- returns pointer to next item in list without removing it
		T* seeNext();
		// see previous -- returns pointer to previous item in list without removing it
		T* seePrev();
		// see at -- returns pointer to item at a location in list, sets current location for seeNext and seePrev
		T* seeAt(int* idx);

		// reset -- reset location to first item in list 
		void reset();

		// is in list -- returns bool indicating if item is is list
		bool isInList(T* find);
		// is empty -- returns bool indicating if list is empty
		bool isEmpty();

		// size -- returns int indicating number of items in list
		int* size();

		// empty list -- delete nodes in list
		void emptyList();
};



// ------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------

// constructor
template<class T>
List<T>::List() {
	location = 0;
	length = 0;

	head = nullptr;
	tail = nullptr;
	current = nullptr;
}
// destructor
template<class T>
List<T>::~List() {
	deleteList();		// empty list / delete nodes
}



// add item
template<class T>
void List<T>::addItem(T* item) {
	Node<T>::Node* newitem = new Node<T>::Node*;		// allocate memory

	// build node
	newitem->prev = tail;		// add previous
	newitem->next = nullptr;	// add next
	newitem->part = item;		// add data

	if (length == 0) { head = newitem }			// for first item
	tail = newitem;

	length++;
}


// get item
template<class T>
T* List<T>::getItem(T* item) {

	// check conditions
	if (isEmpty()) { throw "underflow error"; }			// throw underflow if empty
	if (!isInList(item)) { return nullptr; }			// return null if item not in list

	// find item in list
	reset();					// start at beginning of list

	while (current->next != nullptr) {
		// remove item from list if found
		if (current->part == item) {
			Node<T>::Node* skip = current->next;
			Node<T>::Node* removed = current;	

			// remove item by modifying previous node next	
			current = current->previous;
			current->next = skip;

			if (removed == head) {			// if removed head
				head = removed->next;
			}
			if (removed == tail) {			// if removed tail
				tail = removed->prev;
			}

			length--;
			delete removed;			// delete removed node
			return item;
		}
		current = current->next;
	}

	return nullptr;					// if item not found
}


// see next
template<class T>
T* List<T>::seeNext() {
	location++;
	current = current->next;

	if (isEmpty()) { throw "underflow error"; }			// throw underflow if empty

	return current->part;
}

// see previous
template<class T>
T* List<T>::seePrev() {
	location--;
	current = current->prev;

	if (isEmpty()) { throw "underflow error"; }			// throw underflow if empty

	return current->part;
}

// see at
template<class T>
T* List<T>::seeAt(int* idx) {
	location = idx;
	current = head;

	if (isEmpty()) { throw "underflow error"; }			// throw underflow if empty

	for (int i=0; i<*idx; i++) {
		if (current->next == nullptr) {			// get item at location -- rtn nullptr if reach end of list
			return nullptr;
		}
		current = current->next;
	}
	return current->part;
}


// reset
template<class T>
void List<T>::reset() {
	location = 0;
	current = head;				// reset current location to first item
}


// is in list
template<class T>
bool List<T>::isInList(T* find) {
	T* item = current;
	while (item->next != nullptr) {			// look for item in list
		if (item->part == find) {
			return true;
		}
	}
	return false;
}

// is empty
template<class T>
bool List<T>::isEmpty() {
	if (length == 0) {			// test if list empty
		return true;
	}
	return false;
}


// size
template<class T>
int* List<T>::size() {
	return &length;				// return size of list
}



template<class T>
void List<T>::emptyList() {
	reset();
	
	while (current->next != nullptr) {		// delete nodes
		current = current->next;
		delete current->prev;
	}
	delete current;
}