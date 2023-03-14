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
	int SIZE = 50;
	int* vals = new int[SIZE];
	srand(time(NULL));

	// set true or false to include tests
	bool tst_a = true;
	bool tst_c = true;
	bool tst_b = true;
	bool prints = false;

	// compare / move results
	int array_compare = 0;
	int array_move = 0;
	int center_compare = 0;
	int center_move = 0;
	int blanks_compare = 0;
	int blanks_move = 0;

	int tsts = 100;				// number of tests


	// test classes
	for (int j=0; j<tsts; j++) {
		Array<int> array;
		Center<int> center;
		Blanks<int> blanks;

		// get array of rand int pointers
		for (int i=0; i<SIZE; i++) {		
			vals[i] = rand_int();
		}


		// test Array
		if (tst_a) {
			// insert
			for (int i=0; i<SIZE; i++){
				try {
					array.add_item(&vals[i]);
				}
				catch (char const* err) { cout << err << endl; }
			}
			
			// test print
			if (prints) {
				array.print(); cout << endl;
			}

			// remove
			for (int i=0; i<SIZE; i++) {
				try {
					array.remove_item(vals[i]);
				}
				catch (char const* err) { cout << err << endl; }
			}

			array_compare += array.get_compare();
			array_move += array.get_move();
		}

		// test Center
		if (tst_c) {
			// insert
			for (int i=0; i<SIZE; i++){
				try {
					center.add_item(&vals[i]);
				}
				catch (char const* err) { cout << err << endl; }
			}

			// test print
			if (prints) {
				center.print(); cout << endl;
			}

			// remove
			for (int i=0; i<SIZE; i++) {
				try {
					center.remove_item(vals[i]);
				}
				catch (char const* err) { cout << err << endl; }
			}

			center_compare += center.get_compare();
			center_move += center.get_move();
		}

		// test Blanks
		if (tst_b) {
			// insert
			for (int i=0; i<SIZE; i++){
				try {
					blanks.add_item(&vals[i]);
				}
				catch (char const* err) { cout << err << endl; }
			}

			// test print
			if (prints) {
				blanks.print(); cout << endl;
			}

			// remove
			for (int i=0; i<SIZE; i++) {
				try {
					blanks.remove_item(vals[i]);
				}
				catch (char const* err) { cout << err << endl; }
			}

			blanks_compare += blanks.get_compare();
			blanks_move += blanks.get_move();
		}
	}

	delete vals;

	cout << "Array:" << endl;
		cout << "\tavg compares: " << array_compare/tsts << endl;
		cout << "\tavg moves: " << array_move/tsts << endl;

	cout << "Center:" << endl;
		cout << "\tavg compares: " << center_compare/tsts << endl;
		cout << "\tavg moves: " << center_move/tsts << endl;

	cout << "Blanks:" << endl;
		cout << "\tavg compares: " << blanks_compare/tsts << endl;
		cout << "\tavg moves: " << blanks_move/tsts << endl;

	return 0;
}