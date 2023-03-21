#include <iostream>
#include <string>
#include "List.h"
//#include "Part.h"

using namespace std;

/*
	test ordered linked list template class List with Part items
		- present user with choice of public member functions in List
		- when selected, prompt user for any required information
		- create visualization of list using ascii art
		
*/


int main() {
	List<int> test;

	int a = 1;
	int b = 2;
	int c = 3;

	int* i1 = new int;
	int* i2 = new int;
	int* i3 = new int;

	i1 = &a;

	test.addItem(i1);

	return 0;
}