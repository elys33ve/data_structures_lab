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
	public:
		// add item - insert halfway between any two items in array where it belongs
		void add_item(T* item);
		// remove item - will not move any items in array, instead, make spot = to null
		void remove_item(T item);
};


// insert
// insert item between other items
template<class T>
void Blanks<T>::add_item(T* item){
	int i = 0;
	if (!Array<T>::is_full()) {
		while ((i < Array<T>::arr_size) && (Array<T>::arr[i] != nullptr)) {	
			i++;
		}
		Array<T>::arr[i] = item;
		Array<T>::arr_size += 1;
	}
	else {
		throw "overflow error";
	}
}

// remove
// change to null pointer without moving anything else
template<class T>
void Blanks<T>::remove_item(T item){	
	if (!Array<T>::is_empty()) {
		for (int i=0; i<SIZE; i++) {
			if (*Array<T>::arr[i] == item) {
				Array<T>::arr[i] = nullptr;
			}
		}
	}
	else {
		throw "underflow error";
	}
}