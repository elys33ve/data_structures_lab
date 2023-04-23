#include <iostream>
#include <cstdlib>
#include <string>
#include "arrays.cpp"
#include "Sort.h"
#include "Sort.cpp"

using namespace std;

/*	Performance difference in sorting methods
		- program to generate arrays
			- sizes n = 10, 100, 500, 5000, 25,000, and 100,000 items
			- randomly generated integers w values between 0 and 2n

		- create implementation for the following sort operations:
			* bubble sort
			* insertion sort
			* merge-sort
			* quicksort
			* counting sort
			* radix sort
			* heap-sort

		- test each sort operation and record the time it takes to complete
		- test for each array size a minimum of 10 times
		- use the output to create a table
		- (if any test run takes longer than 5 mins, discontinue)
		- record predictions for each sort operation based on big O notation

		- create a linked list class that can store student information
			* include: first name, last name, id number, other info
		- include 3 of the above sorting algorithms to support sorting by first name,
			last name, and id number as the sort key and includes parameter for 
			ascending / descending
		- make data from 50 students that will result in different order
			for each of the fields
		- menu interface to select sort method and direction to display info

	high resolution clock: https://cplusplus.com/reference/chrono/high_resolution_clock/
	example: https://stackoverflow.com/questions/3220477/how-to-use-clock-in-c
*/

int main () {
	Sort sort;
	int *arr10  = create_array(10);
	int *arr100 = create_array(100);
	int *arr500 = create_array(500);
	int *arr5000 = create_array(5000);
	int *arr25000 = create_array(25000);
	int *arr10000 = create_array(100000);

	//int arr[10]; for (int i=0; i<10; i++) { arr[i] = arr10[i]; }
	//sort.bubble_sort(arr10, 10);
	//sort.insertion_sort(arr10, 10);
	//sort.merge_sort(arr10, 10);
	//sort.quick_sort(arr10, 10);
	//sort.counting_sort(arr10, 10);
	//sort.radix_sort(arr10, 10);
	sort.heap_sort(arr10, 10);

	for (int i=0; i<10; i++) { cout << arr10[i] << endl; }


	return 0;
}
