#ifndef STACK_H
#define STACK_H

// errors such as underflow overflow throw custom class error

template <class T>
class Stack {			// design stack class using array - class should be template
	private:
		T** stack_array;		// pointer to array of pointers
		T* top;
		int stack_size;
		
		// array holding data is array of pointers
		// (** = pointer to array of pointers)

	public:
		// constructor with parameter for array size
		Stack (int size);
		// destructor to delete array itself
		~Stack ();

		// push func accept pointer and add to top of stack - doesnt need to create memory
		void push(T* item);
		// pop function return point - doesnt need delete memory
		T* pop();
		// top function return pointer to item on top of stack without removing
		T* stack_top();
		
		// length func return int with num items in stack
		int length();
		// empty func empties stack of all contents
		void empty_stack();
};

#endif