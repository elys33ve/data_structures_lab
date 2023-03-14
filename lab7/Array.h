#pragma once
#include <iostream>

/*
	ordered list class using array of pointers. insert and remove functions start
	at lowest index and search higher
*/

template<class T>
class Array {
	private:
		int compare = 0;
		int move = 0;
	public:
		const int SIZE = 10;
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

		virtual void print();

		virtual int get_compare() { return compare; }
		virtual int get_move() { return move; }

};		


// ----------------------------------------------------------------------------------

// constructor
// allocate memory for new array
template<class T>
Array<T>::Array(){
	arr = new T* [SIZE];
	for (int i=0; i<SIZE; i++) {
		arr[i] = nullptr;
	}
	arr_size = 0;
}

// destructor
// delete array items and array itself
template<class T>
Array<T>::~Array(){
	delete arr;
}


// add item
template<class T>
void Array<T>::add_item(T* item){
	if (!is_full()) {
		int i;
		for (i=0; i<arr_size+1; i++) {
			if (arr[i] == nullptr) {		// ins at end of list so far
				arr[i] = item;
				move++;
			}
		}

		// sort
		arr_size += 1;
		if (arr_size > 1) {
			for (i=arr_size-1; i>0; i--) {
				compare++;
				if (*arr[i] < *arr[i-1]) {		// swap
					T* temp = arr[i-1];
					arr[i-1] = arr[i];
					arr[i] = temp;
					move++;
					move++;
				}
				else {
					break;
				}
			}
		}
	}
	else {
		throw "overflow error";
	}
}


// remove item
template<class T>
void Array<T>::remove_item(T item){		// takes non-pointer and compares to pointer vals in array
	int i = 0;

	if (!is_empty()) {
		// find item
		for (int i=0; i<arr_size; i++) {
			compare++;
			if (*arr[i] == item) {
				// shift list
				for (i; i<arr_size-1; i++) {
					arr[i] = arr[i+1];
					move++;
				}
				arr[i] = nullptr;
				move++;
				arr_size -= 1;
				break;
			}
		}
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

// test print
template<class T>
void Array<T>::print() {
	std::cout << "--- Array\n";
	for (int i=0; i<SIZE; i++) {
		if (arr[i] != nullptr) {
			std::cout << *arr[i] << std::endl;
		}
		else {
			std::cout << "null" << std::endl;
		}
	}
	std::cout << "\ncompares: " << compare << std::endl;
	std::cout << "moves: " << move << std::endl;
}
