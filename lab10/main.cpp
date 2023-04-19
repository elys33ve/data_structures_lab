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
	Part* items[50];

	// generate keys (sku numbers)
	int keys[50];
	for (int i=0; i<50; i++) { 
		keys[i] = rand() % 1000; 
	}
	for (int i=0; i<50; i++) {
		for (int j=0; j<50; j++) {
			if (keys[i] == keys[j] && i != j) { keys[i] += 1000; }
		}
	}
	for (int i=0; i<50; i++) {
		// create item classes
		Part* part = new Part(keys[i]);
		items[i] = part;
	}

	// --- capacity 50 ---
	capacity = 50;
	Linear<Part> linear(capacity);				// linear probing
	Chained<Part> chained(capacity);			// chained linking	

	// add items
	for (int i=0; i<capacity; i++) { 
		linear.add_item(items[i]); 
		chained.add_item(items[i]);
		
	}
	// get items
	for (int i=0; i<capacity; i++) {
		string str = to_string(keys[i]);
		Part *l = linear.get_item(str); 
		Part *c = chained.get_item(str);
		cout << c->get_sku() << "  " << i << endl;
	}
	


	// --- capacity 150 ---
	capacity = 150;
	//linear = Linear<Part>(capacity);			// linear probing
	//chained = Chained<Part>(capacity);			// chained linking	
	Linear<Part> linear1(capacity);				// linear probing
	Chained<Part> chained1(capacity);			// chained linking
	
	// add items
	for (int i=0; i<capacity; i++) { 
		linear1.add_item(items[i]); 
		chained1.add_item(items[i]);
	}
	// get items
	for (int i=0; i<capacity; i++) {
		string str = to_string(keys[i]);
		Part *l = linear1.get_item(str); 
		Part *c = chained1.get_item(str);
		cout << c->get_sku() << endl;
	}


	

	
	
	for (int i=0; i<50; i++) { delete items[i]; }
	delete item;
	return 0;
}