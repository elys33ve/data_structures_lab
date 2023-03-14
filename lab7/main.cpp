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
	int SIZE = 10;
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
		int* vals = new int[SIZE];
		for (int i=0; i<SIZE; i++) {		
			vals[i] = rand_int();
		}


		// test Array
		if (tst_a) {
			try {
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

				array_compare += array.get_compare();
				array_move += array.get_move();
			}
			catch (char const* err) { cout << err << endl; }
		}

		// test Center
		if (tst_c) {
			try {
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

				center_compare += center.get_compare();
				center_move += center.get_move();
			}
			catch (char const* err) { cout << err << endl; }
		}

		// test Blanks
		if (tst_b) {
			try {
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

				blanks_compare += blanks.get_compare();
				blanks_move += blanks.get_move();
			}
			catch (char const* err) { cout << err << endl; }
		}

		delete vals;
	}

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