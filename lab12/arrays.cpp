#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Arrays.h"
/*	program to generate arrays
	- sizes n = 10, 100, 500, 5000, 25,000, and 100,000 items
	- randomly generated integers w values between 0 and 2n
*/


// 10 items
int* arr10() { 
	static int arr[10]; 			// array to return
	for (int i=0; i<10; i++) { 
		arr[i] = rand() % (2 * 10);			// get random-ish number
	} return arr; 
}

// 100 items
int* arr100() { 
	static int arr[100];
	for (int i=0; i<100; i++) { 
		arr[i] = rand() % (2 * 100);
	} return arr; 
}

// 500 items
int* arr500() { 
	static int arr[500];
	for (int i=0; i<500; i++) { 
		arr[i] = rand() % (2 * 500);
	} return arr; 
}

// 5000 items
int* arr5000() { 
	static int arr[5000];
	for (int i=0; i<5000; i++) { 
		arr[i] = rand() % (2 * 5000);
	} return arr; 
}

// 25,000 items
int* arr25000() { 
	static int arr[25000];
	for (int i=0; i<25000; i++) { 
		arr[i] = rand() % (2 * 25000);
	} return arr; 
}

// 100,000 items
int* arr100000() { 
	static int arr[100000];
	for (int i=0; i<100000; i++) { 
		arr[i] = rand() % (2 * 100000);
	} return arr; 
}



int* create_array (int n) {
	srand (time(NULL));
	if (n == 10) { return arr10(); }			// 10 items
	if (n == 100) { return arr100(); }			// 100 items
	if (n == 500) { return arr500(); }			// 500 items
	if (n == 5000) { return arr5000(); }		// 5000 items
	if (n == 25000) { return arr25000(); }		// 25,000 items
	if (n == 100000) { return arr100000(); }	// 100,000 items
	return nullptr;
}

