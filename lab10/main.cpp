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
	int capacity[4] = {50, 150, 200, 250};
	Part* item = new Part;			// item class
	Part* items = new Part[50];		// objects to add in hash table

	// generate keys (sku numbers)
	int keys[50];
	for (int i=0; i<50; i++) { 
		keys[i] = rand() % 500;		// get random-ish number

		// avoid duplicates
		for (int j=0; j<i; j++) {		
			if (keys[i] == keys[j]) { keys[i] += 500; }
		}

		// create class objects
		items[i] = Part(keys[i]);
	}



	// hash table instances
	Linear<Part> l1(50), l2(150), l3(200), l4(250);
	Chained<Part> c1(50), c2(150), c3(200), c4(250);

	Linear<Part> linear[4] = {l1, l2, l3, l4};
	Chained<Part> chained[4] = {c1, c2, c3, c4};
	



	// test performance
	for (int i=0; i<4; i++) {	
		// add items
		for (int j=0; j<50; j++) {
			linear[i].add_item(&items[j]);
			chained[i].add_item(&items[j]); 
		}
		
		// get items
		for (int j=0; j<50; j++) {
			linear[i].get_item(items[j].get_str_sku());
			chained[i].get_item(items[j].get_str_sku());
		}

		// record compare operations
		linear_compares[i] = linear[i].get_compares();
		chained_compares[i] = chained[i].get_compares();	
	}

	// print results
	for (int i=0; i<4; i++) {
		cout << "\tcapacity: " << capacity[i] << endl;
		cout << "linear probing: " << linear_compares[i] << endl;
		cout << "chained linking: " << chained_compares[i] << endl;
		cout << endl;
	}
	
	delete item;
	delete items;

	return 0;
}