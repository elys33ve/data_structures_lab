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

		// helper functions to check whether queue is empty or full
		void is_empty();
		void is_full();
};

#endif