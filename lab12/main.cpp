#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <ctime>
#include "Arrays.h"
#include "Sort.h"

#include "Sort.cpp"		// **** i need to delete these **** //
#include "Arrays.cpp"	// **** if i forget istg **** //
// visual studio only runs it if these are here for some reason but if u try
// to compile w makefile it gets really pissy


using namespace std;

/*	Performance difference in sorting methods
		- program to generate arrays

		- create implementation for the following sort methods

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
	clock reference: https://stackoverflow.com/questions/3220477/how-to-use-clock-in-c
*/

int main () {
	Sort sort10(10), sort100(100), sort500(500), sort5000(5000), sort25000(25000), sort100000(100000);
	double **time10, **time100, **time500, **time5000, **time25000, **time100000;
	int *arr10  = create_array(10);
	int *arr100 = create_array(100);
	int *arr500 = create_array(500);
	int *arr5000 = create_array(5000);
	int *arr25000 = create_array(25000);
	int *arr100000 = create_array(100000);
	

	int test[6] = {0, 0, 0, 0, 0, 1}; 	// test for {10, 100, 500, 5000, 25000, 100000}
	///////////////////////////////////////

	// test all sort functions 10 times for array size w 
	for (int i=0; i<10; i++) {
		if (test[0] == 1) { sort10.test_all(); }
		if (test[1] == 1) { sort100.test_all(); }
		if (test[2] == 1) { sort500.test_all(); }
		if (test[3] == 1) { sort5000.test_all(); }
		if (test[4] == 1) { sort25000.test_all(); }
		//if (test[5] == 1) { sort100000.test_all(arr100000); }
	}

	// test 100000 items (0-6 corresponds with sort functions)
	if (test[5] == 1) { 
		sort100000.test_10(arr100000, 6); 
	}


	// print array of times
	if (test[0] == 1) { sort10.print_avgs(); }
	if (test[1] == 1) { sort100.print_avgs(); }
	if (test[2] == 1) { sort500.print_avgs(); }
	if (test[3] == 1) { sort5000.print_avgs(); }
	if (test[4] == 1) { sort25000.print_avgs(); }
	if (test[5] == 1) { sort100000.print_avgs(); }
	
	

	return 0;
}
