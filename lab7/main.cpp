#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

#include "Array.h"
#include "Center.h"
#include "Blanks.h"

using namespace std;


int rand_int() {
	return rand() % 100;
}


int main () {
	Array<int> array;
	Center<int> center;
	Blanks<int> blanks;

	// set true or false to include tests
	bool tst_a = false;
	bool tst_c = false;
	bool tst_b = true;
	bool prints = true;

	int SIZE = 25;
	srand(time(NULL));

	int* vals = new int[25];
	for (int i=0; i<SIZE; i++) {		// get array of rand int pointers
		vals[i] = rand_int();
	}

	/* center.add_item(&vals[1]);
	center.add_item(&vals[2]);
	center.add_item(&vals[3]); */

	// test Array
	if (tst_a) {
		// insert
		for (int i=0; i<SIZE; i++){
			array.add_item(&vals[i]); 
		}
		
		// test print
		if (prints) {
			array.print(); cout << endl;
		}

		// remove
		for (int i=0; i<SIZE; i++) {
			array.remove_item(vals[i]);
		}
	}

	// test Center
	if (tst_c) {
		// insert
		for (int i=0; i<SIZE; i++){
			center.add_item(&vals[i]);
		}

		// test print
		if (prints) {
			center.print(); cout << endl;
		}

		// remove
		for (int i=0; i<SIZE; i++) {
			center.remove_item(vals[i]);
		}
	}

	// test Blanks
	if (tst_b) {
		// insert
		for (int i=0; i<SIZE; i++){
			blanks.add_item(&vals[i]);
		}

		// test print
		if (prints) {
			blanks.print(); cout << endl;
		}

		// remove
		for (int i=0; i<SIZE; i++) {
			blanks.remove_item(vals[i]);
		}
	}



	delete vals;

	return 0;
}