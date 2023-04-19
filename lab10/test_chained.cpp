#include <iostream>
#include <string>
#include "Part.h" 
#include "Chained.h"

using namespace std;

/*	test chained linking hash table 	*/

int main () {
	int capacity = 10;
	Chained<Part> table(capacity);				// chained linking

	Part* item = new Part;
	Part* items[] = {};

	bool quit = false;				// stop loop
	string in_function, yn;
	int in_int;
	int n_items = 0;

	// function test options
	string fstr[] = {"add", "get_item", "remove", "get_length", "is_empty", "show"};

	// test table prompts
	cout << "this program is for testing a hash table class." << endl;
	while (quit == false) {
		cout << "which function would you like to test?" << endl;
		cout << "(add, get_item, remove, get_length, is_empty, show)" << endl;
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
			items[n_items] = part; n_items++;

			try { 
				item = part;
				table.add_item(item);

			} catch (char const* err) { cout << err << endl; }

			cout << "item added" << endl;
		}
		else if (in_function == fstr[1]) {			// get item
			int sku;

			// inputs
			cout << "\n\t" << "T* get_item(string sku)" << endl;
			cout << "sku: "; cin >> sku;
			string sku_str = to_string(sku);

			try { 
				item = table.get_item(sku_str);

				if (item == nullptr) {
					cout << "item not found" << endl;
				}
				else {
					cout << "sku: " << item->get_sku() << endl;
					cout << "description: " << item->get_description() << endl;
					cout << "price: " << item->get_price() << endl;
					cout << "uom: " << item->get_uom() << endl;
					cout << "quantity on hand: " << item->get_quantity() << endl;
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
			cout << "\n\t" << "bool is_empty()" << endl;
			bool is_empty = table.is_empty();

			if (is_empty == true) { cout << "table is empty" << endl; }
			else { cout << "table is not empty" << endl; }
		}
		else if (in_function == fstr[5]) {			// show
			table.show();			// display table
		}


		// ask to continue testing
		cout << "\nwould you like to test another function? (y/n)   ";
		cin >> yn;

		if (yn == "n" || yn == "no") { quit = true; }
	}

	// de-allocate memory
	for (int i=0; i<n_items; i++) { delete items[i]; }
	delete item;
	
	return 0;
}