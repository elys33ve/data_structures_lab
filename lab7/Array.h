#pragma once
#include <iostream>

/*
	templated ordered list class using array of pointers
*/

template<class T>
class Array {
	public:
		int SIZE = 25;
		T* arr[SIZE];
		int arr_size;
		
		Array();
		~Array();

		// add item - begin at start of array
		void add_item(T* item);
		// delete item - begin at start of array, ensure no empty spaces between	
		T* remove_item(T item);

		// empty array contents
		void make_empty();

		bool is_empty();
		bool is_full();

};		

// constructor
// allocate memory for new array
template<class T>
Array<T>::Array(){
	arr = new T*;			// ----- new array memory, maybe initialize to null pointers
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
		while ((i < SIZE) && (arr[i] != NULL)) {	// start at beginning, search for no NULL
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
T Array<T>::remove_item(T item){
	int i = 0;
	T* temp;

	if (!is_empty()) {
		temp = arr[0];

		while ((i < arr_size) && (arr[i] != NULL)) {		// get first and shift everything else over
			arr[i] = arr[i+1];
			i++;
		}
		arr_size -= 1;
		return temp;
	}
	else {
		throw "underflow error";		//--------errros
	}
}


// empty
template<class T>
void Array<T>::make_empty(){
	for (int i=0; i<SIZE; i++) {
		if (arr[i] != NULL) {
			delete arr[i];
		}
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