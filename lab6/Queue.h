#pragma once
#include <iostream>

template<typename T>
class Queue {
private:
    T* queue_array; // array to store data
    int queue_head; // index of the front of the queue
    int queue_tail; // index of the back of the queue
    int queue_capacity; // maximum size of the queue
    int queue_count; // number of elements currently in the queue
public:
    // constructor with parameter for array size
    Queue(int size) {
        queue_array = new T[size];
        queue_head = 0;
        queue_tail = -1;
        queue_capacity = size;
        queue_count = 0;
    }

    // destructor to delete array itself
    ~Queue() {
        delete[] queue_array;
    }

    // insert pointer at end of queue - doesnt need to create memory
    void enqueue(T item) {
        if (queue_count == queue_capacity) {
            throw std::runtime_error("Queue is full.");
        }
        queue_tail = (queue_tail + 1) % queue_capacity;
        queue_array[queue_tail] = item;
        queue_count++;
    }

    // remove obj at front of queue - doesnt need delete memory
    T dequeue() {
        if (queue_count == 0) {
            throw std::runtime_error("Queue is empty.");
        }
        T item = queue_array[queue_head];
        queue_head = (queue_head + 1) % queue_capacity;
        queue_count--;
        return item;
    }

    // returns pointer to front of queue - doesnt remove
    T front() {
        if (queue_count == 0) {
            throw std::runtime_error("Queue is empty.");
        }
        return queue_array[queue_head];
    }

    // return int with number of items currently in queue
    int size() {
        return queue_count;
    }

    // empty queue array of all contents
    bool empty() {
        return queue_count == 0;
    }
};