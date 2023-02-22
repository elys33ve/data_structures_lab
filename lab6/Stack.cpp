#include "Stack.h"


// constructor
// create new array of size from parameter
template <class T>
Stack<T>::Stack (int size) {
	stack_array = new T*[size];		// create memory for array of pointers
	stack_size = 0;
}


// destructor
// fully delete array to avoid memory leaks
template <class T>
Stack<T>::~Stack () {
	//delete stack array
}


// push
// add new item to stack
template <class T>
void Stack<T>::push (T* item) {
	// check if stack is full
	if (stack_size <= length()) {
		//throw overflow error
	}
	// increment top, assign new item for top
	else {
		T* temp1 = stack_top();
		T* temp2;	//--next item
		for (int i=0; i < stack_size; i++) {	// adjust array for push (?)
			stack_array[i]
		}
	}
}


// pop
// remove and return item from stack -- items popped in reverse order they are pushed
template <class T>
T* Stack<T>::pop () {
	//
	if (stack_size == 0) {		// if stack is empty
		//throw underflow error
	}
	else {
	T* temp = stack_array[i];	//store value of stack[top]
	//decrement top
	//return value
	}
}


// top
// return pointer to top of stack
template <class T>
T* Stack<T>::stack_top () {
	// return top
}


// length
// return length of current number of items in stack
template <class T>
int Stack<T>::length () {
	//
}


// empty
// clear stack array and calls delete to avoid memory leaks
template <class T>
void Stack<T>::empty_stack () {
	for (int i=0; i < stack_size; i++) {
		delete stack_array[i];
	}
	top = -1;
}

