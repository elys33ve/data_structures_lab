#include <iostream>
#include <string>
#include "Part.h"
#include "Chain.h"
#pragma once

using namespace std;




// hash table class
template<class T>
class Hash : public List<T> {
	private:
		List<T> **table;			// array of pointers to items
		int current_size;	// current number of items in table
		int capacity;		// max size of array
		int current;		// current index

		int hash_function(string str);

	public:
		Hash() { capacity = 100; create_table(); }			// default constructor
		Hash(int c) { capacity = c; create_table(); }		// overloaded constructor
		~Hash() { empty_table(); }							// destructor

		// create and allocate memory for new table
		void create_table();		

		// add / remove item
		void add_item(T *item);
		T *remove_item(string str);
		
		// getters 
		T *get_item(string str);
		int get_length() { return current_size; }
		string get_str(T *item) { return item->operator string(); }

		// bool helper functions
		bool is_empty() { return (current_size == 0) ? true : false; }
		bool is_full() { return (current_size >= capacity) ? true : false; }
		bool is_free(int idx) { return (table[idx] == nullptr) ? true : false; }
		bool is_in_table (string str) { return (get_item(str) == nullptr) ? false : true; }

		// delete table and free memory
		void empty_table() { for (int i=0; i<capacity; i++) { delete table[i]; } delete table; }
		// retest table (erase all items but dont delete)
		void reset() { for (int i=0; i<capacity; i++) { table[i] = nullptr; } }

		// print or show functions
		void show();
		void print_table();
		//string p(T *t) { return (t == nullptr) ? "nullptr" : get_str(t); }
};


// show table info
template<class T>
void Hash<T>::show() {
	print_table();
	cout << "table size: " << get_length() << "\t\tcapacity: " << capacity << endl;
}


// create new table (constructor helper function)
template<class T>
void Hash<T>::create_table() {
	current_size = 0;
	table = new List<T>* [capacity];
	current = 0;

	// make list items nullptr
	for (int i=0; i<capacity; i++) {
		List<T> *bucket = new List<T>(capacity);
		table[i] = bucket;
	}
}


// add item
template<class T>
void Hash<T>::add_item(T *item) {
	if (is_full()) { throw "error: table is full."; }		// throw overflow error
	int idx = hash_function(get_str(item));

	table[idx]->addItem(item);		// add to bucket
	current = idx;
	current_size++;
	return;

	/*
	// test if place in table is taken
	for (idx; idx<capacity; idx++) {			//  linear probe for next free space
		// insert new item if free space found
		if (is_free(idx)) {
			table[idx] = item;
			cout << "added " << p(table[idx]) << " at " << idx << endl;
			current = idx;
			current_size++;
			return;
		}	
	}
	
	
	// if end of array is reached without finding free space, wrap back to beginning
	for (int i=0; i<idx; i++) {
		// insert new item if free space found
		if (is_free(i)) {
			table[i] = item;
			cout << "added " << p(table[i]) << " at " << i << endl;
			current = i;
			current_size++;
			return;
		}
	}
	*/
}




// remove item
template<class T>
T *Hash<T>::remove_item(string str) {
	if (is_empty()) { throw "error: table is empty."; }		// throw underflow error
	int idx = hash_function(str);

	
	T* rm = table[idx]->removeItem(str); cout << "sdfasdfasdf\n";
	if (rm != nullptr) { current_size--; }		// decrement if removed
	cout << "sdfasdfasdf\n";

	/*
	// get index
	for (idx; idx<capacity; idx++) {
		if (!is_free(idx) && get_str(table[idx]) == str ) {
			T* rm = table[idx];
			table[idx] = nullptr;
			current = idx;
			current_size--;
			return rm;
		}
	}
	// wrap to beginning
	for (int i=0; i<idx; i++) {
		if (!is_free(i) && get_str(table[i]) == str ) {
			T* rm = table[i];
			table[i] = nullptr;
			current = i;
			current_size--;
			return rm;
		}
	}
	return nullptr;	
	*/
}





// get item from table
template<class T>
T *Hash<T>::get_item(string str) {					// (class object)
	if (is_empty()) { throw "error: table is empty."; }		// throw underflow error
	int idx = hash_function(str);

	return table[idx]->getItem(str);
	/*
	// test if place in table is taken
	for (idx; idx<capacity; idx++) {			//  linear probe for next free space
		// return item if found
		if (!is_free(idx) && get_str(table[idx]) == str) {
			current = idx;
			return table[idx];
		}	
	}
	
	// if end of array is reached without finding free space, wrap back to beginning
	for (int i=0; i<idx; i++) {
		// return item if found
		if (!is_free(i) && get_str(table[i]) == str) {
			current = i;
			return table[i];
		}	
	}
	return nullptr;
	*/
}




// hash function
template<class T>
int Hash<T>::hash_function(string str) {
	int sum = 0;
	for (int i=0; i<str.size(); i++) {
		sum += int(str.at(i));
	}
	return sum % capacity;
}



// print table
template<class T>
void Hash<T>::print_table() {
	for (int i=0; i<capacity; i++) {
		//cout << "item " << i << ": ";
		cout << "bucket " << i << ": ";
		List<T> *bucket = table[i];
		if (bucket->isEmpty()) {
			cout << "--empty--\n";
		} else {
			bucket->disp();
			//cout << str << "\t\thash: " << hash_function(str) << endl;
		}
	}
}