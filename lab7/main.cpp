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

	int i;
	int SIZE = 25;


	// insert items Array
	for (i=0; i<SIZE; i++){
		int x = rand_int();
		array.add_item(&x);
	}

	// insert items Center
	for (i=0; i<SIZE; i++){
		int x = rand_int();
		center.add_item(&x);
	}

	// insert items Blanks
	for (i=0; i<SIZE; i++){
		int x = rand_int();
		blanks.add_item(&x);
	}




	return 0;
}