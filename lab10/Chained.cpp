#include <iostream>
#include <string>
#include "Part.h"
#include "Bucket.h"
#include "Chained.h"


using namespace std;




// create new table (constructor helper function)
template<class T>
void Chained<T>::create_table() {
	current_size = current = compares = 0;
	table = new Bucket<T>* [capacity];

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

	T* rm = table[idx]->remove_item(str);
	if (rm != nullptr) { current_size--; }		// decrement if removed
}



// get item from table
template<class T>
T *Chained<T>::get_item(string str) {			// (class object)
	if (is_empty()) { throw "error: table is empty."; }		// throw underflow error
	int idx = hash_function(str);

	return table[idx]->get_item(str);
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




// ----------- print functions


// show table info
template<class T>
void Chained<T>::show() {
	print_table();
	cout << "table size: " << get_length() << "\t\tcapacity: " << capacity << endl;
}


// print table
template<class T>
void Chained<T>::print_table() {
	for (int i=0; i<capacity; i++) {
		cout << "bucket " << i << ": ";
		Bucket<T> *bucket = table[i];		// get each bucket

		if (bucket->is_empty()) {
			cout << "--empty--\n";
		} else {
			bucket->disp();
		}
	}
}