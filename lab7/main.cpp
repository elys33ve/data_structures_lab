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
	int SIZE = 25;
	srand(time(NULL));

	int* vals = new int[25];
	for (int i=0; i<SIZE; i++) {		// get array of rand int pointers
		vals[i] = rand_int();
	}


	center.add_item(&vals[1]);
	center.add_item(&vals[2]);
	center.add_item(&vals[3]);

	// insert items Array
	for (int i=0; i<SIZE; i++){
		//array.add_item(&vals[i]);
		//center.add_item(&vals[i]);
		//blanks.add_item(&vals[i]);
	}


	for (int i=0; i<SIZE; i++) {
		cout << center.get(i) << endl;
	}

	
	// remove items from array
	for (int i=0; i<SIZE; i++) {
		//array.remove_item(vals[i]);
		//center.remove_item(vals[i]);
		//blanks.remove_item(vals[i]);
	}





	delete vals;

	return 0;
}