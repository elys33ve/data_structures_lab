#pragma once
#include <iostream>

/*
	templated ordered list class using array of pointers
*/

template<class T>
class Array {
	private:
		int SIZE = 25;
		T* arr[SIZE];
		int arr_size;
		
	public:
		Array();
		~Array();

		// add item - begin at start of array
		void add_item(T item);
		// delete item - begin at start of array, ensure no empty spaces between	
		T remove_item(T item);

		// empty array contents
		void make_empty();

		bool is_empty();
		bool is_full();

};		

// constructor
// allocate memory for new array
template<class T>
Array<T>::Array(){
	arr = new T*;
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
void Array<T>::add_item(T item){
	int i = 0;

	if (!is_full()) {
		while ((i < SIZE) && (arr[i] != NULL)) {	// start at beginning, search for no NULL
			
		}
	}
}


// remove item
template<class T>
T Array<T>::remove_item(T item){

}


// empty
template<class T>
void Array<T>::make_empty(){

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