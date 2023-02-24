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
	for (int i=0; i < stack_size; i++) {	//--need to verify if this is right
		delete stack_array [i];
	}
}	


// push
// add new item to stack
template <class T>
void Stack<T>::push (T* item) {
	// check if stack is full

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
	// check if stack is empty

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
	return top;
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


// is empty
// return true if stack is empty
template <class T>
bool Stack<T>::is_empty () {
	if (stack_size == 0) {		// if stack is empty
		return true //maybe throw underflow error here idky
	}
	else {
		return false;
	}
}


// is full
// return true is stack is full
template <class T>
bool Stack<T>::is_full () {
	if (stack_size <= length()) {
		return true; //maybe throw overflow error
	}
	else {
		return false;
	}
}



/*
stack functions - algorithm
https://www.geeksforgeeks.org/introduction-to-stack-data-structure-and-algorithm-tutorials/
queue functions - algorithm
https://www.geeksforgeeks.org/introduction-and-array-implementation-of-queue/

stack implementation using templates
https://www.geeksforgeeks.org/implementing-stack-using-class-templates-in-cpp/

*/