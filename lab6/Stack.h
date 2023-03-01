#ifndef STACK_H
#define STACK_H

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

		// check for and throw errors for underflow or overflow
		void is_empty();
		void is_full();
};



// constructor
// create new array of size from parameter
template <class T>
Stack<T>::Stack (int size) {
	stack_array = new T*[size];		// create memory for array of pointers
	stack_size = 0;
	stack_top = -1;
}


// destructor
// fully delete array to avoid memory leaks
template <class T>
Stack<T>::~Stack () {
	delete [] stack_array;			// delete and de-allocate array memory
	//---- idk if this is correct ----
}	


// push
// add new item to stack
template <class T>
void Stack<T>::push (T* obj) {
	// check if stack is full
	is_full();
	stack_top++;						// incriment top
	stack_array[stack_top] = obj;	
}


// pop
// remove and return item from stack
template <class T>
T* Stack<T>::pop () {
	// check if stack is empty
	is_empty();
	stack_top--;						// decriment top
	return stack_array[stack_top+1];	// return pointer to previous top
}


// top
// return pointer to top of stack
template <class T>
T* Stack<T>::top () {
	// check if stack is empty
	is_empty();
	return stack_array[stack_top];
}


// length
// return length of current number of objects in stack
template <class T>
int Stack<T>::length () {
	return stack_top + 1;		// current number of objects in stack
}


// empty
// clear stack array and calls delete to avoid memory leaks
template <class T>
void Stack<T>::empty_stack () {
	for (int i=0; i < stack_size; i++) {
		delete stack_array[i];
	}
	stack_top = -1;
}


// is empty
// return true if stack is empty
template <class T>
void Stack<T>::is_empty () {
	if (stack_top < 0) {		// if stack is empty
		throw "underflow error";			//---need to verify how were supposed to throw the custom class errors
	}
}


// is full
// return true is stack is full
template <class T>
void Stack<T>::is_full () {
	if (stack_top >= stack_size-1) {
		throw "overflow error";			//---need to verify how were supposed to throw the custom class errors
	}
}



#endif