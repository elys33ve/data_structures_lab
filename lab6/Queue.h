#ifndef QUEUE_H
#define QUEUE_H

template <class T>
class Queue {
		T** queue_array;		// pointer to array of pointers
		int queue_front;		// index front of queue
		int queue_end;			// index end of queue
		int queue_size;			// queue size taken by constructor

	public:
		// constructor with parameter for array size
		Queue (int size);
		// destructor to delete array itself
		~Queue ();

		// insert pointer at end of queue - doesnt need to create memory
		void in_queue(T* obj);
		// remove obj at front of queue - doesnt need delete memory
		T* pop();
		// returns pointer to front of queue - doesnt remove
		T* front();
		// returns pointer to end of queue - doesnt remove
		T* end();
		
		// return int with number of items currently in queue
		int length();
		// empty queue array of all contents
		void empty_queue();

		// check for and throw errors for underflow or overflow
		void is_empty();
		void is_full();
};


// constructor
// create new array of size from parameter
template <class T>
Queue<T>::Queue (int size) {
	queue_array = new T*[size];		// create memory for array of pointers
	queue_size = 0;
	queue_front = 0;
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
// add new obj to end of queue
template <class T>
void Queue<T>::in_queue (T* obj) {
	// check if queue is full
	is_full();
	queue_end++;
	queue_array[queue_end] = obj;	
}


// pop
// remove obj at front of queue and return pointer
template <class T>
T* Queue<T>::pop () {
	// check if queue is empty
	is_empty();
	queue_front++;
	return queue_array[queue_front-1];		//----have to verify if this is correct
}


// front
// return ptr to obj at front of queue
template <class T>
T* Queue<T>::front () {
	// check if queue is empty
	is_empty();
	return queue_array[queue_front];
}


// end
// return pointer to obj at end of queue
template <class T>
T* Queue<T>::end () {
	// check if queue is empty
	is_empty();
	return queue_array[queue_end];
}


// length
// return length of current number of objects in queue
template <class T>
int Queue<T>::length () {
	return (queue_end + 1) - queue_front;		// current number of objects in queue
}


// empty
// clear queue array and calls delete to avoid memory leaks
template <class T>
void Queue<T>::empty_queue () {
	for (int i=0; i < queue_size; i++) {
		delete queue_array[i];
	}
	queue_end = -1;
}


// is empty
// return true if queue is empty
template <class T>
void Queue<T>::is_empty () {
	if (queue_end < 0) {
		throw "underflow error";			//---need to verify how were supposed to throw the custom class errors
	}
}


// is full
// return true is queue is full
template <class T>
void Queue<T>::is_full () {
	if (queue_end >= queue_size-1) {
		throw "overflow error";			//---need to verify how were supposed to throw the custom class errors
	}
}


#endif