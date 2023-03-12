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
		T** arr;
		bool shift;		// true if right side was shifted to left
		const int SIZE = 25;
	public:
		Center();
		~Center();

		// add item - begin at middle of array
		void add_item(T* item);
		// remove item - begin at middle of array, ensure no empty spaces
		void remove_item(T item);

};


template<class T>
Center<T>::Center(){
	arr = new T* [SIZE];			// ---new array memory, initialize to null pointers
	for (int i=0; i<SIZE; i++) {
		arr[i] = nullptr;
	}
	arr_size = 0;
	shift = false;
}

template<class T>
Center<T>::~Center(){
	make_empty();
	delete arr;
}

// insert
// insert item starting in center
template<class T>
void Center<T>::add_item(T* item){
	int i = 13;

	if (!is_full()) {
		while ((i < SIZE) && (arr[i] != nullptr)) {	// start at center, move right first
			i++;
		}

		if ((i >= SIZE) && (shift == false)) {		// if no more space to right but empty to left
			for (i=0; i<13; i++) {
				arr[i] = arr[i+12];		// shift everything from right over to left
			}
			shift = true;
		}
		
		arr[i] = item;
		arr_size += 1;
	}
	else {
		throw "overflow error";
	}
}

// remove
// remove item starting in center
template<class T>
void Center<T>::remove_item(T item){
	int i = 13;

	if (!is_empty()) {
		while ((i < SIZE) && (arr[i] != nullptr)) {	// start at center, move right first
			i++;
		}

		if (i >= SIZE) {			// if no more space to right
			for (i=0; i<13; i++) {
				arr[i] = arr[i+12];		// shift everything from right over to left
			}
		}
		
		arr[i] = item;
		arr_size -= 1;
	}
	else {
		throw "overflow error";
	}
}





