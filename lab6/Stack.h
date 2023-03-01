#pragma once
#include <iostream>

using namespace std;

class StackException : public exception {
public:
    const char* what() const throw() {
        return "Stack Exception";
    }
};

template<class T>
class Stack {
private:
    T** stack_arr; // Array holding the data
    int stack_size; // Size of the array
    int stack_top; // Index of the top of the stack

public:
    // Constructor
    // create new array of size from parameter
    Stack(int size) {
        stack_arr = new T * [size];
        this->stack_size = size;
        stack_top = -1;
    }

    // Destructor
    // fully delete array to avoid memory leaks
    ~Stack() {
        empty();
        delete[] stack_arr;    // delete and de-allocate array memory
    }

    // push
    // add new item to stack
    void push(T* ptr) {
        if (stack_top == stack_size - 1) {
            throw StackException(); // Throw an exception if the stack is full
        }
        stack_arr[++stack_top] = ptr;
    }

    // pop
    // remove and return item from stack
    T* pop() {
        if (stack_top == -1) {
            throw StackException(); // Throw an exception if the stack is empty
        }
        return stack_arr[stack_top--];
    }

    // top
    // return pointer to top of stack
    T* top() {
        if (stack_top == -1) {
            throw StackException(); // Throw an exception if the stack is empty
        }
        return stack_arr[stack_top];
    }

    // Length
    // return length of current number of objects in stack
    int length() {
        return stack_top + 1;
    }

    // Empty 
    // clear stack array and calls delete to avoid memory leaks
    bool empty() {
        while (stack_top >= 0) {
            return stack_top == -1;
        }
    }

};

