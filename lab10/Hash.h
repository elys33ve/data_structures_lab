#include <iostream>
#include <string>
#include "Item.h"
#pragma once

using namespace std;




// hash table class
template<class T>
class Hash {
	private:
		T **table;			// array of pointers to items
		int current_size;	// current number of items in table
		int capacity;		// max size of array

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

		// bool helper functions
		bool is_empty() { return (current_size == 0) ? true : false; }
		bool is_full() { return (current_size >= capacity) ? true : false; }
		bool is_free(int idx) { return (table[idx] == nullptr) ? true : false; }

		// delete table and free memory
		void empty_table() { delete table; }

		// print or show functions
		void show();
		void print_table();
		string p(T *t) { return (t == nullptr) ? "nullptr" : t->str; }
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
	table = new T* [capacity];

	// make list items nullptr
	for (int i=0; i<capacity; i++) {
		table[i] = nullptr;
	}
}


// add item
template<class T>
void Hash<T>::add_item(T *item) {
	if (is_full()) { throw tableIsFull(); }		// throw overflow error
	int idx = hash_function(item->str);

	// test if place in table is taken
	for (idx; idx<capacity; idx++) {			//  linear probe for next free space
		// insert new item if free space found
		if (is_free(idx)) {
			table[idx] = item;
			cout << "added " << p(table[idx]) << " at " << idx << endl;
			show();
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
			current_size++;
			return;
		}
	}
}




// remove item
template<class T>
T *Hash<T>::remove_item(string str) {
	if (is_empty()) { throw tableIsEmpty(); }		// throw underflow error
	int idx = hash_function(str);

	// get index
	for (idx; idx<capacity; idx++) {
		if (!is_free(idx) && table[idx]->str == str ) {
			T* rm = table[idx];
			table[idx] = nullptr;
			return rm;
		}
	}
	// wrap to beginning
	for (int i=0; i<idx; i++) {
		if (!is_free(i) && table[i]->str == str ) {
			T* rm = table[i];
			table[i] = nullptr;
			return rm;
		}
	}
	return nullptr;	
}





// get item from table
template<class T>
T *Hash<T>::get_item(string str) {					// (class object)
	if (is_empty()) { throw tableIsEmpty(); }		// throw underflow error
	int idx = hash_function(str);

	// test if place in table is taken
	for (idx; idx<capacity; idx++) {			//  linear probe for next free space
		// return item if found
		if (!is_free(idx) && table[idx]->str == str) {
			return table[idx];
		}	
	}
	
	// if end of array is reached without finding free space, wrap back to beginning
	for (int i=0; i<idx; i++) {
		// return item if found
		if (!is_free(i) && table[i]->str == str) {
			return table[i];
		}	
	}
	return nullptr;
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
		cout << "item " << i << ": ";
		if (is_free(i)) {
			cout << "--NULL--\n";
		} else {
			string str = table[i]->str;
			cout << str << "\t\thash: " << hash_function(str) << endl;
		}
	}

}