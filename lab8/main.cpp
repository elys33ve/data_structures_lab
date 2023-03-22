#include <iostream>
#include <string>
#include "List.h"
#include "Part.h"

using namespace std;

/*
	test ordered linked list template class List with Part items
		- present user with choice of public member functions in List
		- when selected, prompt user for any required information
		- create visualization of list using ascii art
*/


int main() {
	List<Part> list;
	Part* item = new Part;

	int* size = new int;

	bool quit = false;
	string in_function, yn;
	int in_int;

	string fstr[9] = {"addItem", "getItem", "seeNext", "seePrev", "seeAt", "reset", "isInList", "isEmpty", "size"};
	string fstr2[9] = {"add", "get", "next", "pre", "at", "reset", "inlist", "empty", "len"};

	// test list prompts
	cout << "this program is for testing an ordered linked list class." << endl;
	while (quit == false) {
		cout << "which function would you like to test?" << endl;
		cout << "(addItem, getItem, seeNext, seePrev, seeAt, reset, isInList, isEmpty, size)" << endl;
		cin >> in_function;

		if (in_function == fstr[0] || in_function == fstr2[0]) {		// add item
			int sku, price;
			string des, uom;
			double quan;

			// inputs
			cout << "\n\t" << "void addItem(T* item)" << endl;
			cout << "sku: "; cin >> sku;
			cout << "description: "; cin >> des;
			cout << "price: "; cin >> price;
			cout << "uom: "; cin >> uom;
			cout << "quantity on hand: "; cin >> quan;

			Part* part = new Part(sku, des, price, uom, quan);

			try { 
				item = part;
				list.addItem(item);

			} catch (char const* err) { cout << err << endl; }

			cout << "item added" << endl;
		}
		else if (in_function == fstr[1] || in_function == fstr2[1]) {	// get item
			int sku;

			// inputs
			cout << "\n\t" << "T* getItem(int* item)" << endl;
			cout << "sku: "; cin >> sku;

			try { 

				item = list.getItem(&sku);

				if (item == nullptr) {
					cout << "item not found" << endl;
				}
				else {
					cout << "item removed" << endl;
				}
				
			} catch (char const* err) { cout << err << endl; }
		}
		else if (in_function == fstr[2] || in_function == fstr2[2]) {	// see next
			cout << "\n\t" << "T* seeNext()" << endl;
			try { 
				
				item = list.seeNext();

				if (item == nullptr) {
					cout << "nullptr" << endl;
				}
				else {
					item->show();
				}

			} catch (char const* err) { cout << err << endl; }
		}
		else if (in_function == fstr[3] || in_function == fstr2[3]) {	// see previous
			cout << "\n\t" << "T* seePrev()" << endl;
			try { 

				item = list.seePrev();

				if (item == nullptr) {
					cout << "nullptr" << endl;
				}
				else {
					item->show();
				}
				
			} catch (char const* err) { cout << err << endl; }
		}
		else if (in_function == fstr[4] || in_function == fstr2[4]) {	// see at
			int idx;

			// inputs
			cout << "\n\t" << "T* seeAt(int* idx)" << endl;
			cout << "idx: "; cin >> idx;

			try { 

				item = list.seeAt(&idx);

				if (item == nullptr) {
					cout << "nullptr" << endl;
				}
				else {
					item->show();
				}
				
			} catch (char const* err) { cout << err << endl; }
		}
		else if (in_function == fstr[5] || in_function == fstr2[5]) {	// reset
			cout << "\n\t" << "void reset()" << endl;
			try { 

				list.reset();
				
			} catch (char const* err) { cout << err << endl; }
		}
		else if (in_function == fstr[6] || in_function == fstr2[6]) {	// is in list
			int sku;

			// inputs
			cout << "\n\t" << "bool isInList(int* find)" << endl;
			cout << "sku: "; cin >> sku;

			bool in_list = list.isInList(&sku);

			if (in_list == true) { cout << "item found in list" << endl; }
			else { cout << "item not found" << endl; }
		}
		else if (in_function == fstr[7] || in_function == fstr2[7]) {	// is empty
			cout << "\n\t" << "bool isEmpty()" << endl;
			
			bool is_empty = list.isEmpty();

			if (is_empty == true) { cout << "list empty" << endl; }
			else { cout << "list not empty" << endl; }
		}
		else if (in_function == fstr[8] || in_function == fstr2[8]) {	// size
			cout << "\n\t" << "int* size()" << endl;
			
			size = list.size();

			cout << "list size = " << *size << endl;			
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