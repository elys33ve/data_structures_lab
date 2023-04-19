#include <iostream>
#include <cstdlib>
#include <string>
#include "Part.h" 
#include "Chained.h"
#include "Linear.h"

using namespace std;

/*	Measure Performance of Linear Probing vs Chained Linking Hash Tables	
		- count number of compare operations performed for chained linking
		- count number of times an index is checked for linear probing
*/

int main () {
	int linear_compares[4], chained_compares[4];		// totals
	int capacity;
	Part* item = new Part;		// item class
	Part* items = new Part[50];

	// generate keys (sku numbers)
	int keys[50];
	for (int i=0; i<50; i++) { 
		keys[i] = rand() % 500;		// get random-ish number

		// avoid duplicates
		for (int j=0; j<i; j++) {		
			if (keys[i] == keys[j]) { keys[i] += 500; }
		}
	}
	for (int i=0; i<50; i++) {
		cout << keys[i] << endl;
	}

	// --- capacity 50 ---
	capacity = 50;
	Linear<Part> linear(capacity);				// linear probing
	Chained<Part> chained(capacity);			// chained linking	

	cout << linear.get_capacity() << endl;

	delete item;
	delete items;

	return 0;
}