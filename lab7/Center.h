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

};

// insert
// insert item starting in center
template<class T>
void Center<T>::add_item(T* item){
	int i;
	if (shift == false) { i = 12; }		// if already shifted over, start at center+1
	else { i = 13; }

	if (!Array<T>::is_full()) {
		while ((i < SIZE) && (Array<T>::arr[i] != nullptr)) {	// start at center, move right first
			i++;
		}

		if ((i >= SIZE) && (shift == false)) {		// if no more space to right but empty to left
			for (i=0; i<13; i++) {
				Array<T>::arr[i] = Array<T>::arr[i+12];		// shift everything from right over to left
			}
			shift = true;
		}
		
		Array<T>::arr[i] = item;
		Array<T>::arr_size += 1;
	}
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





