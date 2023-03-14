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
		const int SIZE = Array<T>::SIZE;
		int half = (int)(SIZE/2);
		int compare = 0;
		int move = 0;
	public:

		// add item - begin at middle of array
		void add_item(T* item);
		// remove item - begin at middle of array, ensure no empty spaces
		void remove_item(T item);

		void print();

		// test if left/right side full
		bool r_full();
		bool l_full();

		int get_compare() { return compare; }
		int get_move() { return move; }
};


// ----------------------------------------------------------------------------------

// insert
// insert item starting in center
template<class T>
void Center<T>::add_item(T* item){
	// error if array is full
	if (Array<T>::is_full()) {
		throw "overflow error";
        return;
	}
	int i;
	compare++;

	// first insert
	if (Array<T>::arr_size == 0) {					
		Array<T>::arr[half] = item;
		move++;
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
				move++;
			}
			Array<T>::arr[i] = item;
			move++;
		}
		// if not full
		else {
			for (i=half; i<SIZE; i++) {
				if (Array<T>::arr[i] == nullptr) {
					Array<T>::arr[i] = item;
					move++;
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
			compare++;
			move++;
			move++;
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
				move++;
			}
			Array<T>::arr[i] = item;
			move++;
		}
		// if not full
		else {
			for (i=half; i>-1; i--) {
				if (Array<T>::arr[i] == nullptr) {
					Array<T>::arr[i] = item;
					move++;
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
			compare++;
			move++;
			move++;
		}
	}
	Array<T>::arr_size += 1;
}


// remove
// remove item starting in center
template<class T>
void Center<T>::remove_item(T item){
	// test if empty
	if (Array<T>::is_empty()) {
		throw "underflow error";
		return;
	}
	int i;
	bool found = false;

	// go right
	if ((Array<T>::arr[half] != nullptr) && (*Array<T>::arr[half] < item)) {
		for (i=half; i<SIZE-1; i++) {
			compare++;
			// shift over
			if (((Array<T>::arr[i] != nullptr) && (*Array<T>::arr[i] == item)) || (found == true)) {
				Array<T>::arr[i] = Array<T>::arr[i+1];
				move++;
				found = true;
			}
		}
		if (found == true) {
			Array<T>::arr[SIZE-1] = nullptr;
			move++;
		}
	}	
	// go left
	else {
		for (i=half; i>0; i--) {
			compare++;
			// shift over
			if (((Array<T>::arr[i] != nullptr) && (*Array<T>::arr[i] == item)) || (found == true)) {
				Array<T>::arr[i] = Array<T>::arr[i-1];
				move++;
				found = true;
			}
		}
		if (found == true) {
			Array<T>::arr[0] = nullptr;
			move++;
		}
	}
	
	Array<T>::arr_size -= 1;
}


// left side full
template<class T>
bool Center<T>::l_full() {
	for (int i=0; i<(int)(SIZE/2); i++) {
		if (Array<T>::arr[i] == nullptr) {
			return false;
		}
	}
	return true;
}
// right side full
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
	std::cout << "--- Center\n";
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