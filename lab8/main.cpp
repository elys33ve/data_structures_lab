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
	int* size = test.size();

	int a = 1111; int b = 2222; int c = 3333;
	int seeat = 1;

	int* i1 = new int; int* i2 = new int; int* i3 = new int;
	int* o = new int;

	// --------------
	i1 = &a;
	i2 = &b;
	i3 = &c;
	o = &seeat;

	test.addItem(i1);
	cout << *size << endl;
	test.addItem(i2);
	cout << *size << endl;
	test.addItem(i3);
	cout << *size << endl;

	o = test.seeAt(o);
	o = test.seeNext();
	o = test.seePrev();

	o = test.getItem(i3);
	cout << *o << endl;
	cout << *size << endl;



	//i2 = test.getItem(i2);
	
		


	//try { } catch (char const* err) { cout << err << endl; }

	delete i1;
	delete i2, i3, o;

	return 0;
}