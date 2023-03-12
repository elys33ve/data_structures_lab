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
class Blanks {
	private:

	public:
		Blanks();

		// add item - insert halfway between any two items in array where it belongs
		void add_item(T item);
		// remove item - will not move any items in array, instead, make spot = to null
		T remove_item(T item);

};


template<class T>
Blanks<T>::Blanks(){

}

template<class T>
void Blanks<T>::add_item(T item){

}

template<class T>
T Blanks<T>::remove_item(T item){

}