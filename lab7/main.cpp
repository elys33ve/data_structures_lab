#include <iostream>
#include <string>
#include <cstdlib>
#include "Array.h"
#include "Center.h"
#include "Blanks.h"

using namespace std;

int main () {
	Array<int> array;
	Center<int> center;
	Blanks<int> blanks;

	int rand_int, i;
	int SIZE = 25;

	int* int_ptr = new int;


	for (i=0; i<SIZE; i++){
		rand_int = rand() % 100;
		int_ptr = &rand_int;
		array.add_item(int_ptr);
	}

	


	delete int_ptr;

	return 0;
}