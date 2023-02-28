#include "Queue.h"


// constructor
// create new array of size from parameter
template <class T>
Queue<T>::Queue (int size) {
	queue_array = new T*[size];		// create memory for array of pointers
	queue_size = 0;
	queue_end = -1;
}


// destructor
// fully delete array to avoid memory leaks
template <class T>
Queue<T>::~Queue () {
	delete [] queue_array;			// delete and de-allocate array memory
	//---- idk if this is correct ----
}	


// insert
// add new obj to queue
template <class T>
void Queue<T>::in_queue (T* obj) {
	// check if queue is full
	if (is_full()) {
		throw "overflow";	//-----fix probably
	}
	else {
		queue_end++;
		queue_array[queue_end] = obj;	
	}
}


// pop
// remove obj at front of queue and return pointer
template <class T>
T* Queue<T>::pop () {
	// check if queue is full
	if (is_empty()) {
		throw "underflow";	//-----fix probably
	}
	else {
		queue_end++;
		queue_array[queue_end] = obj;	
	}
}


// front
// return ptr to obj at front of queue
template <class T>
T* Queue<T>::front () {
	// check if queue is empty
	if (is_empty()) {
		throw "underflow";	//-----fix probably
	}
	else {
		return queue_array[0];
	}
}


// end
// return pointer to obj at end of queue
template <class T>
T* Queue<T>::end () {
	// check if queue is empty
	if (is_empty()) {
		throw "underflow";	//-----fix probably
	}
	else {
		return queue_array[queue_end];
	}
}


// length
// return length of current number of objects in queue
template <class T>
int Queue<T>::length () {
	return queue_top + 1;		// current number of objects in queue
}


// empty
// clear queue array and calls delete to avoid memory leaks
template <class T>
void Queue<T>::empty_queue () {
	for (int i=0; i < queue_size; i++) {
		delete queue_array[i];
	}
	queue_top = -1;
}


// is empty
// return true if queue is empty
template <class T>
bool Queue<T>::is_empty () {
	if (queue_top < 0) {		// if queue is empty
		return true; //--maybe throw underflow error here and change to void func idky 
	}
	else {
		return false;
	}
}


// is full
// return true is queue is full
template <class T>
bool Queue<T>::is_full () {
	if (queue_top >= queue_size-1) {
		return true; //maybe throw overflow error
	}
	else {
		return false;
	}
}