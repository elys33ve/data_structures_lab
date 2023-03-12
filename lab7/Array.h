#pragma once
#include <iostream>

/*
	templated ordered list class using array of pointers
*/

template<class T>
class Array {
	public:
		const int SIZE = 25;
		T** arr;
		int arr_size;

		Array();
		~Array();

		// add item - begin at start of array
		virtual void add_item(T* item);
		// delete item - begin at start of array, ensure no empty spaces between	
		virtual void remove_item(T item);

		// empty array contents
		void make_empty();

		bool is_empty();
		bool is_full();

};		

// constructor
// allocate memory for new array
template<class T>
Array<T>::Array(){
	arr = new T* [SIZE];			// ---new array memory, initialize to null pointers
	for (int i=0; i<SIZE; i++) {
		arr[i] = nullptr;
	}
	arr_size = 0;
}

// destructor
// delete array items and array itself
template<class T>
Array<T>::~Array(){
	make_empty();
	delete arr;
}


// add item
template<class T>
void Array<T>::add_item(T* item){
	int i = 0;
	if (!is_full()) {
		while ((i < arr_size) && (arr[i] != nullptr)) {	// start at beginning, search for no NULL
			i++;
		}
		arr[i] = item;
		arr_size += 1;
	}
	else {
		throw "overflow error";
	}
}


// remove item
template<class T>
void Array<T>::remove_item(T item){		// (rn it takes non ptr to compare to ptrs in array)
	int i = 0;

	if (!is_empty()) {
		for (int i=0; i<arr_size; i++) {	// find item
			if (*arr[i] == item) {
				for (i; i<arr_size-1; i++) {		// shift list items to account for remove
					arr[i] = arr[i+1];
				}
				arr[i] = nullptr;
				break;
			}
		}
		arr_size -= 1;	
	}
	else {
		throw "underflow error";
	}
}


// empty
template<class T>
void Array<T>::make_empty(){
	for (int i=0; i<SIZE; i++) {
		delete arr[i];
	}
}


// is empty
template<class T>
bool Array<T>::is_empty(){
	if (arr_size <= 0) {
		return true;
	}
	else {
		return false;
	}
}

// is full
template<class T>
bool Array<T>::is_full(){
	if (arr_size >= SIZE) {
		return true;
	}
	else {
		return false;
	}
}