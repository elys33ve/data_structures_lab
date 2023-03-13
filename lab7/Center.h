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

		void print();
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
	int i, j, start, stop;
	bool found = false;

	if (!Array<T>::is_empty()) {
		// if not shifted over to left
		if (shift == false) {
			start = (int)(SIZE/2); 
			stop = Array<T>::arr_size + start;
		}
		// if shifted to the left
		else {
			start = 0;
			stop = SIZE;
		}
		// find item in array and shift over
		for (i=start; i<stop; i++) {
			if ((item == *Array<T>::arr[i]) || (found == true)) {
				if (i == SIZE-1) {
					Array<T>::arr[i] = nullptr;
				}
				Array<T>::arr[i] = Array<T>::arr[i+1];
				found = true;
			}
		}
		Array<T>::arr_size -= 1;
	}
	else {
		throw "underflow error";
	}
}


// test print
template<class T>
void Center<T>::print() {
	for (int i=0; i<SIZE; i++) {
		if (Array<T>::arr[i] != nullptr) {
			std::cout << *Array<T>::arr[i] << std::endl;
		}
	}
}