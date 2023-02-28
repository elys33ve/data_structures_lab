#ifndef STACK_H
#define STACK_H

// errors such as underflow overflow throw custom class error

template <class T>
class Stack {			// design stack class using array - class should be template
	private:
		T** stack_array;		// pointer to array of pointers
		int stack_top;			// indicate top of stack by index
		int stack_size;			// stack size taken by constructor

	public:
		// constructor with parameter for array size
		Stack (int size);
		// destructor to delete array itself
		~Stack ();

		// add obj to top of stack - doesnt need to create memory
		void push(T* obj);
		// remove top obj and return as ptr - doesnt need delete memory
		T* pop();
		// return ptr to item on top of stack without removing
		T* top();
		
		// return int with number of objects currently in stack
		int length();
		// empties stack of all contents
		void empty_stack();

		// helper functions to check whether stack is empty or full
		void is_empty();
		void is_full();
};

#endif