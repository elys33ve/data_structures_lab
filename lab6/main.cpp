#include <iostream>
#include <cstdlib>
#include "Stack.h"
#include "Queue.h"

// order files are compiled is important - compile headers first


int main () {
	int stack_size = 4;

	Stack<int> *stack = new Stack<int>(stack_size);

	int* ptr = new int; *ptr = 5;
	int a = 5;

	stack->push(&a);

	// throw errors in class, catch in driver
	// (try/catch in main)




	return 0;
}