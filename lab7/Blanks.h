#pragma once
#include "Array.h"


/*
	derived class to investigate leaving blank spots (point to null) in array to
	reduce the number of moves when inserting 

	insert halfway between any two items in array where it belongs should only 
	move items in array if the inserting item sits between two items that are at
	contingious locations
*/

template<class T>
class Blanks : Array<T> {
	private:
		const int SIZE = Array<T>::SIZE;
		int compare = 0;
		int move = 0;
	public:
		// add item - insert halfway between any two items in array where it belongs
		void add_item(T* item);
		// remove item - will not move any items in array, instead, make spot = to null
		void remove_item(T item);

		void print();

		int get_compare() { return compare; }
		int get_move() { return move; }
};


// ----------------------------------------------------------------------------------

// add
// insert item between other items
template<class T>
void Blanks<T>::add_item(T* item){
	if (Array<T>::is_full()) {
		throw "overflow error";
		return;
	}
	int i, j, left, right;
	bool found = false;
	int idx = -1;

	// first insert
	if (Array<T>::arr_size == 0) {
		Array<T>::arr[0] = item;
		Array<T>::arr_size += 1;
		return;
	}
	
	// find place to insert 
	for (i=0; i<SIZE; i++) {
		compare++;								
		if ((Array<T>::arr[i] != nullptr) && (*item > *Array<T>::arr[i])) {	
			idx = i;
		} 
	}
	i = idx;

	// if new item smallest
	if (idx == -1) {
		// if idx 0 empty
		if (Array<T>::arr[0] == nullptr) {
			Array<T>::arr[0] = item;
			move++;
		}
		// shift right
		else {
			for (j=0; j<SIZE; j++) {
				if (Array<T>::arr[j] == nullptr) { right = j; break; }		// get index of null ptr to shift
			}
			for (j=right; j>0; j--) {
				Array<T>::arr[j] = Array<T>::arr[j-1];
				move++;
			}
			Array<T>::arr[j] = item;
			move++;
		}
	}
	// skip space and insert		
	else if ((i<SIZE-2) && ((Array<T>::arr[i+2] == nullptr) && (Array<T>::arr[i+1] == nullptr))) {			
		Array<T>::arr[i+2] = item;
		move++;
	}
	// dont skip but insert
	else if ((i<SIZE-1) && (Array<T>::arr[i+1] == nullptr)) {	
		Array<T>::arr[i+1] = item;
		move++;
	}
	// shift
	else {					
		left = SIZE+10; right = SIZE+10;

		// find closest null ptr
		for (j=i; j<SIZE; j++) {
			if (Array<T>::arr[j] == nullptr) { right = j; break; }		// get index of null ptr to shift
		}
		for (j=i; j>-1; j--) { 
			if (Array<T>::arr[j] == nullptr) { left = j; break; }
		}

		// shift right
		if (right-i < left+i) { 
			for (j=right; j>i+1; j--) {
				Array<T>::arr[j] = Array<T>::arr[j-1];
				move++;
			}
			Array<T>::arr[j] = item;
			move++;
		}
		// shift left
		else {
			for (j=left; j<i-1; j++) {
				Array<T>::arr[j] = Array<T>::arr[j+1];
				move++;
			}
			Array<T>::arr[j] = item;
			move++;
		}
	}
	Array<T>::arr_size += 1;
}


// remove
// change to null pointer without moving anything else
template<class T>
void Blanks<T>::remove_item(T item){	
	if (Array<T>::is_empty()) {
		throw "underflow error";
		return;
	}

	// replace with nullptr
	for (int i=0; i<SIZE; i++) {
		compare++;
		if ((Array<T>::arr[i] != nullptr) && (*Array<T>::arr[i] == item)) {
			Array<T>::arr[i] = nullptr;
			move++;
			Array<T>::arr_size -= 1;
			break;
		}
	}
}


// test print
template<class T>
void Blanks<T>::print() {
	std::cout << "--- Blanks\n";
	for (int i=0; i<SIZE; i++) {
		if (Array<T>::arr[i] != nullptr) {
			std::cout << *Array<T>::arr[i] << std::endl;
		}
		else {
			std::cout << "null" << std::endl;
		}
	}
	std::cout << "\ncompares: " << compare << std::endl;
	std::cout << "moves: " << move << std::endl;
}

