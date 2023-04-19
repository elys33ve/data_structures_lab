#include <iostream>
#include <string>
#include "Hash.h" 
#include "Part.h"
#include "Linear.h"

using namespace std;

/*		Hash table that uses linear probing

Hash table class:
	- template class
	- overloaded == operator and string object conversion (in the data type stored in hash table)
	- methods implimented:
		- constructor -- overload indicates max number of items that can be stored. defult = 100
		- hash -- private function; accepts str and rtns int
			(sum of all ascii values passed in string, modulus by max size of table)
		- add item -- add item from table
		- remove item -- searches table for given item. if found, removes from table and returns. if not found, returns nullptr
		- get item -- returns pointer to item if found in table
		- get length -- returns int for number of items in table
		- destructor
	- all items passed to or from the class should be done via a pointer rather than by value
	- ensure there are no memory leaks
*/

int main () {
	int capacity = 10;
	Linear<Part> linear(capacity);				// linear probing
	Hash<Part> chained(capacity);			// chained linking	
	
	/*
	int sku[10] = {123,234,5323,432,444,6,663,75,77,22};	// test sku values

	// create array of test items -- testing
	Part newitem[capacity];			
	for (int i=0; i<10; i++) {
		Part k(sku[i], "asdf", 3, "meters");
		newitem[i] = k;
		table.add_item(&newitem[i]);
	} 
	*/

	Part* item = new Part;

	bool quit = false;				// stop loop
	string in_function, yn;
	int in_int;

	// function test options
	string fstr[] = {"add", "get item", "remove", "get length", "is empty", "show"};

	// test table prompts
	cout << "this program is for testing a hash table class." << endl;
	while (quit == false) {
		cout << "which function would you like to test?" << endl;
		cout << "(add, remove, get item, get length, is empty, show)" << endl;
		cin >> in_function;

		if (in_function == fstr[0]) {				// add item
			int sku, price;
			string des, uom;
			double quan;

			// inputs
			cout << "\n\t" << "void add_item(T* item)" << endl;
			cout << "sku: "; cin >> sku;
			cout << "description: "; cin >> des;
			cout << "price: "; cin >> price;
			cout << "uom: "; cin >> uom;
			cout << "quantity on hand: "; cin >> quan;

			Part* part = new Part(sku, des, price, uom, quan);

			try { 
				item = part;
				table.add_item(item);

			} catch (char const* err) { cout << err << endl; }

			cout << "item added" << endl;
		}
		else if (in_function == fstr[1]) {			// get item
			int sku;

			// inputs
			cout << "\n\t" << "T* get_item(string str)" << endl;
			cout << "sku: "; cin >> sku;
			string sku_str = to_string(sku);

			try { 

				item = table.get_item(sku_str);

				if (item == nullptr) {
					cout << "item not found" << endl;
				}
				else {
					cout << "item removed" << endl;
				}
				
			} catch (char const* err) { cout << err << endl; }
		}
		else if (in_function == fstr[2]) {			// remove item
			int sku;

			// inputs
			cout << "\n\t" << "T* remove_item(string str)" << endl;
			cout << "sku: "; cin >> sku;
			string sku_str = to_string(sku);

			try { 

				item = table.remove_item(sku_str);

				if (item == nullptr) {
					cout << "item not found" << endl;
				}
				else {
					cout << "item removed" << endl;
				}
				
			} catch (char const* err) { cout << err << endl; }
		}
		else if (in_function == fstr[3]) {			// get length
			cout << "\n\t" << "int get_length()" << endl;
			int len = table.get_length();
			cout << "length: " << len << endl;
		}
		else if (in_function == fstr[4]) {			// is empty
			cout << "\n\t" << "bool isEmpty()" << endl;
			
			bool is_empty = table.is_empty();

			if (is_empty == true) { cout << "table empty" << endl; }
			else { cout << "table not empty" << endl; }
		}
		else if (in_function == fstr[5]) {			// show
			table.show();		// display table
		}



		// ask to continue testing
		cout << "\nwould you like to test another function? (y/n)   ";
		cin >> yn;

		if (yn == "n" || yn == "no") {
			quit = true;
		}
	}

	delete item;

	return 0;
}