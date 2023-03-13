#pragma once
#include "Array.h"

/*
	class Center to investigate the theory that by starting from the center,
	fewer items will need to be moved on ever insert 

	when inserting, moves right but can't go past end of array. if there is
	still room in the array but not the direction needed, shift everything over
	when inserting
*/

template<class T>
class Center : public Array<T> {
	private:
		bool shift = false;		// true if right side was shifted to left
		const int SIZE = Array<T>::SIZE;
	public:

		// add item - begin at middle of array
		void add_item(T* item);
		// remove item - begin at middle of array, ensure no empty spaces
		void remove_item(T item);

		int get(int i) { return *Array<T>::arr[i]; }
};

// insert
// insert item starting in center
template<class T>
void Center<T>::add_item(T* item){
	int i, j, half, stop, start;

	// find half index
	if (shift == false) { 
		half = (int)(SIZE/2); 
	}		
	else { 
		half = (int)((SIZE+1)/2);
	}

	// insert item if array is not full
	if (!Array<T>::is_full()) {
		i = half;

		// search array for empty space
		while ((i <= SIZE) && (Array<T>::arr[i] != nullptr)) {
			i++;
		}

		// if array is full on half -- shift over to left side
		if ((i == SIZE) && (shift == false)) {
			for (j=0; j<(int)((SIZE+1)/2); j++) {
				Array<T>::arr[j] = Array<T>::arr[j+half];
				Array<T>::arr[j+half] = nullptr;
			}
			shift = true;
			i = (int)((SIZE+1)/2);
		}
		
		// insert item
		Array<T>::arr[i] = item;
		Array<T>::arr_size += 1;		

		// sort item in array
		if (shift == false) { 				// get start and stop points 
			start = half + Array<T>::arr_size-1; 
			stop = half;
		}		
		else { 
			start = Array<T>::arr_size-1;
			stop = 0; 
		}
		if (Array<T>::arr_size > 1) {		// sort
			for (i=start; i>stop; i--) { 
				if (*Array<T>::arr[i] < *Array<T>::arr[i-1]) {		// swap
					T* temp = Array<T>::arr[i-1];
					Array<T>::arr[i-1] = Array<T>::arr[i];
					Array<T>::arr[i] = temp;
				}
				else {
					break;
				}
			}
		}

		for (i=12; i<16; i++) {
			std::cout << *Array<T>::arr[i] << "  " << i  << "  " << *item << std::endl;
		}

	}
	// error if array is full
	else {
		throw "overflow error";
	}
}

// remove
// remove item starting in center
template<class T>
void Center<T>::remove_item(T item){
	int i;
	if (!Array<T>::is_empty()) {
		bool found = false;

		// right side
		for (i=12; i<SIZE; i++) {			// start at center, move right first
			if (*Array<T>::arr[i] == item) {
				for (i; i<SIZE-1; i++) {		// if found in first half, shift over to account for remove
					Array<T>::arr[i] = Array<T>::arr[i+1];
				}
				Array<T>::arr[i] = nullptr;
			}
		}

		// left side
		if ((found == false) && (shift == true)) {		// if not yet found, test left side
			for (i=0; i<13; i++) {
				if (*Array<T>::arr[i] == item) {
					for (i; i<SIZE-1; i++) {				// if found in second half, shift over to account for remove
						Array<T>::arr[i] = Array<T>::arr[i+1];
					}
					Array<T>::arr[i] = nullptr;
				}
			}
		}
		Array<T>::arr_size -= 1;
	}
	else {
		throw "underflow error";
	}
}


