#pragma once


/*
	ordered linked list template class:
		- overloaded >, <, and == operators
		- items passed to/from the class should be pointers
		- ensure there are no memory leaks
*/

template<class T>
class Node {
	public:
		T *part;
		Node *prev;
		Node *next;
};


template<class T>
class List {
	private:
		int* location;
		int* length;

		Node<T>::Node head;
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

		// returns int indicating number of items in list
		int* size();
};



// ------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------

// constructor
template<class T>
List<T>::List() {
	location = 0;
	length = 0;

	head = nullptr;
	current = nullptr;
}
// destructor
template<class T>
List<T>::~List() {

}



// add item
template<class T>
void List<T>::addItem(T* item) {
	


}

// get item
template<class T>
T* List<T>::getItem(T* item) {
	


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
	current = head;
}


// is in list
template<class T>
bool List<T>::isInList(T* find) {
	T* item = current;
	while (item->next != nullptr) {
		if (item->part == find) {
			return true;
		}
	}
	return false;
}

// is empty
template<class T>
bool List<T>::isEmpty() {
	if (length == 0) {
		return true;
	}
	return false;
}


// size
template<class T>
int* List<T>::size() {
	return length;
}