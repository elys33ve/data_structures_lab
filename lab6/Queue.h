#ifndef QUEUE_H
#define QUEUE_H

template <class T>
class Queue {
		T** queue_array;		// pointer to array of pointers
		int queue_end;			// indicate end of queue
		int queue_size;			// stack size taken by constructor
		
		// array holding data is array of pointers
		// (** = pointer to array of pointers)

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
		
		// length func return int with num items in stack
		int length();
		// empty queue array of all contents
		void empty_queue();

		// helper functions to check whether stack is empty or full
		bool is_empty();
		bool is_full();
};

#endif