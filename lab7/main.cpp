#include <iostream>
#include <string>
#include <cstdlib>
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

	int* vals = new int[25];

	for (int i=0; i<SIZE; i++) {		// get array of rand int pointers
		vals[i] = rand_int();
		cout << vals[i] << endl;
	}

	// insert items Array
	for (int i=0; i<SIZE; i++){
		cout << &vals[i] << endl;
		array.add_item(&vals[i]);
		center.add_item(&vals[i]);
		blanks.add_item(&vals[i]);
	}
	

	for (int i=0;i<25;i++){
		cout << *array.arr[i] << endl;
	}

	

	delete vals;

	return 0;
}