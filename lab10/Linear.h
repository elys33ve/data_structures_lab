#include <iostream>
#include <string>
#include "Part.h"
#pragma once

using namespace std;




// hash table class
template<class T>
class Linear {
	private:
		T **table;			// array of pointers to items
		int current_size;	// current number of items in table
		int capacity;		// max size of array
		int current;		// current index

		int hash_function(string str);

	public:
		Linear() { capacity = 100; create_table(); }			// default constructor
		Linear(int c) { capacity = c; create_table(); }		// overloaded constructor
		~Linear() { empty_table(); }							// destructor

		// create and allocate memory for new table
		void create_table();		

		// add / remove item
		void add_item(T *item);
		T *remove_item(string str);
		
		// getters 
		T *get_item(string str);
		int get_length() { return current_size; }
		string get_str(T *item) { return item->operator string(); }
		int get_capacity () { return capacity; }

		// see next, previous
		T *see_at(int idx);
		T *see_next();
		T *see_prev();

		// bool helper functions
		bool is_empty() { return (current_size == 0) ? true : false; }
		bool is_full() { return (current_size >= capacity) ? true : false; }
		bool is_free(int idx) { return (table[idx] == nullptr) ? true : false; }
		bool is_in_table (string str) { return (get_item(str) == nullptr) ? false : true; }

		// delete table and free memory
		void empty_table() { delete table; }
		// retest table (erase all items but dont delete)
		void reset() { for (int i=0; i<capacity; i++) { table[i] = nullptr; } }

		// print or show functions
		void show();
		void print_table();
		string p(T *t) { return (t == nullptr) ? "nullptr" : get_str(t); }
};

// show table info
template<class T>
void Linear<T>::show() {
	print_table();
	cout << "table size: " << get_length() << "\t\tcapacity: " << capacity << endl;
}


// create new table (constructor helper function)
template<class T>
void Linear<T>::create_table() {
	current_size = 0;
	table = new T* [capacity];
	current = 0;

	// make list items nullptr
	for (int i=0; i<capacity; i++) {
		table[i] = nullptr;
	}
}


// add item
template<class T>
void Linear<T>::add_item(T *item) {
	if (is_full()) { throw "error: table is full."; }		// throw overflow error
	int idx = hash_function(get_str(item));

	// test if place in table is taken
	for (idx; idx<capacity; idx++) {			//  linear probe for next free space
		// insert new item if free space found
		if (is_free(idx)) {
			table[idx] = item;
			//cout << "added " << p(table[idx]) << " at idx: " << idx << endl;
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
			//cout << "added " << p(table[i]) << " at idx: " << i << endl;
			current = i;
			current_size++;
			return;
		}
	}
}




// remove item
template<class T>
T *Linear<T>::remove_item(string str) {
	if (is_empty()) { throw "error: table is empty."; }		// throw underflow error
	int idx = hash_function(str);

	// get index
	for (idx; idx<capacity; idx++) {
		if (!is_free(idx) && get_str(table[idx]) == str ) {
			T* rm = table[idx];
			table[idx] = nullptr;
			current = idx;
			return rm;
		}
	}
	// wrap to beginning
	for (int i=0; i<idx; i++) {
		if (!is_free(i) && get_str(table[i]) == str ) {
			T* rm = table[i];
			table[i] = nullptr;
			current = i;
			return rm;
		}
	}
	return nullptr;	
}





// get item from table
template<class T>
T *Linear<T>::get_item(string str) {					// (class object)
	if (is_empty()) { throw "error: table is empty."; }		// throw underflow error
	int idx = hash_function(str);

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
}




// hash function
template<class T>
int Linear<T>::hash_function(string str) {
	int sum = 0;
	for (int i=0; i<str.size(); i++) {
		sum += int(str.at(i));
	}
	return sum % capacity;
}


// see at
template<class T>
T *Linear<T>::see_at(int idx) {
	if (is_empty()) { throw "error: table is empty."; }				// underflow error
	if (idx >= capacity || idx < 0) { throw "error: out of range."; }	// range error
	current = idx;
	return table[idx];
}
// see next
template<class T>
T *Linear<T>::see_next() {
	if (is_empty()) { throw "error: table is empty."; }		// underflow error
	
	// if at end of list, wrap around to beginning
	if (current >= capacity-1) { current = 0; } 
	else { current++; }

	return table[current];
}
// see previous
template<class T>
T *Linear<T>::see_prev() {
	if (is_empty()) { throw "error: table is empty."; }		// underflow error
	
	// if at beginning of list, wrap around to end
	if (current <= 0) { current = capacity-1; } 
	else { current--; }
	
	return table[current];
}



// print table
template<class T>
void Linear<T>::print_table() {
	cout << endl;
	for (int i=0; i<capacity; i++) {
		cout << "item " << i << ": ";
		if (is_free(i)) {
			cout << "--NULL--\n";
		} else {
			string str = get_str(table[i]);
			cout << str << "\thash: " << hash_function(str) << endl;
		}
	}
}