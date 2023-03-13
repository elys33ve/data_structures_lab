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

		// test if left/right side full
		bool r_full();
		bool l_full();
};


// insert
// insert item starting in center
template<class T>
void Center<T>::add_item(T* item){
	// error if array is full
	if (Array<T>::is_full()) {
		throw "overflow error";
        return;
	}
	int half = (int)(SIZE/2);
	int i;

	// first insert
	if (Array<T>::arr_size == 0) {					
		Array<T>::arr[half] = item;
	}
	// search on right
	else if (*item > *Array<T>::arr[half]) {			
		// if right side is full
		if (r_full()) {
			for (i=SIZE-1; i>0; i--) {
				if (Array<T>::arr[i] == nullptr) {		// find null ptr on right
					break;
				}
			}
			for (i; i<SIZE-1; i++) {
				Array<T>::arr[i] = Array<T>::arr[i+1];
			}
			Array<T>::arr[i] = item;
		}
		// if not full
		else {
			for (i=half; i<SIZE; i++) {
				if (Array<T>::arr[i] == nullptr) {
					Array<T>::arr[i] = item;
					break;
				}
			}
		}

		// sort
		while (*Array<T>::arr[i] < *Array<T>::arr[i-1]) {
			T* temp = Array<T>::arr[i-1];
			Array<T>::arr[i-1] = Array<T>::arr[i];
			Array<T>::arr[i] = temp;
			i--;
		}
	}
	// search on left
	else {									
		// if left side is full
		if (l_full()) {
			for (i=half; i<SIZE; i++) {
				if (Array<T>::arr[i] == nullptr) {		// find null ptr on left
					break;
				}
			}
			for (i; i>0; i--) {
				Array<T>::arr[i] = Array<T>::arr[i-1];
			}
			Array<T>::arr[i] = item;
		}
		// if not full
		else {
			for (i=half; i>-1; i--) {
				if (Array<T>::arr[i] == nullptr) {
					Array<T>::arr[i] = item;
					break;
				}
			}
		}

		// sort
		while (*Array<T>::arr[i] > *Array<T>::arr[i+1]) {
			T* temp = Array<T>::arr[i+1];
			Array<T>::arr[i+1] = Array<T>::arr[i];
			Array<T>::arr[i] = temp;
			i++;
		}
	}
	Array<T>::arr_size += 1;
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

// left full
template<class T>
bool Center<T>::l_full() {
	for (int i=0; i<(int)(SIZE/2); i++) {
		if (Array<T>::arr[i] == nullptr) {
			return false;
		}
	}
	return true;
}
// right full
template<class T>
bool Center<T>::r_full() {
	for (int i=(int)(SIZE/2)+1; i<SIZE; i++) {
		if (Array<T>::arr[i] == nullptr) {
			return false;
		}
	}
	return true;
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