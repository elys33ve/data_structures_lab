#include <iostream>
#include <string>
#include "Part.h"
#include "Bucket.h"
#pragma once

using namespace std;




// hash table class
template<class T>
class Chained : public Bucket<T> {
	private:
		Bucket<T> **table;			// array of pointers to items
		int current_size;	// current number of items in table
		int capacity;		// max size of array
		int current;		// current index

		int hash_function(string str);

	public:
		Chained() { capacity = 100; create_table(); }			// default constructor
		Chained(int c) { capacity = c; create_table(); }		// overloaded constructor
		~Chained() { empty_table(); }							// destructor

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
};


// show table info
template<class T>
void Chained<T>::show() {
	print_table();
	cout << "table size: " << get_length() << "\t\tcapacity: " << capacity << endl;
}


// create new table (constructor helper function)
template<class T>
void Chained<T>::create_table() {
	current_size = 0;
	table = new Bucket<T>* [capacity];
	current = 0;

	// make list items nullptr
	for (int i=0; i<capacity; i++) {
		Bucket<T> *bucket = new Bucket<T>(capacity);
		table[i] = bucket;
	}
}


// add item
template<class T>
void Chained<T>::add_item(T *item) {
	if (is_full()) { throw "error: table is full."; }		// throw overflow error
	int idx = hash_function(get_str(item));

	table[idx]->add_item(item);		// add to bucket
	current = idx;
	current_size++;
	return;
}




// remove item
template<class T>
T *Chained<T>::remove_item(string str) {
	if (is_empty()) { throw "error: table is empty."; }		// throw underflow error
	int idx = hash_function(str);

	
	T* rm = table[idx]->remove_item(str); cout << "sdfasdfasdf\n";
	if (rm != nullptr) { current_size--; }		// decrement if removed
	cout << "sdfasdfasdf\n";
}





// get item from table
template<class T>
T *Chained<T>::get_item(string str) {					// (class object)
	if (is_empty()) { throw "error: table is empty."; }		// throw underflow error
	int idx = hash_function(str);

	return table[idx]->get_item(str);
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
int Chained<T>::hash_function(string str) {
	int sum = 0;
	for (int i=0; i<str.size(); i++) {
		sum += int(str.at(i));
	}
	return sum % capacity;
}



// print table
template<class T>
void Chained<T>::print_table() {
	for (int i=0; i<capacity; i++) {
		//cout << "item " << i << ": ";
		cout << "bucket " << i << ": ";
		Bucket<T> *bucket = table[i];
		if (bucket->is_empty()) {
			cout << "--empty--\n";
		} else {
			bucket->disp();
			//cout << str << "\t\thash: " << hash_function(str) << endl;
		}
	}
}