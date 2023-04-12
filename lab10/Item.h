#include <iostream>
#include <string>
#pragma once

using namespace std;



// ------------------------------ class Item ------------------------------ //

// object for storing item value
class Item {
	public:
		string str;
		int value;

		Item() { str = ""; value = 0; }
		Item(string word) { str = word; value = 0; }
		Item(string word, int integer) { str = word; value = integer; }
};


// ------------------------------ exceptions ------------------------------ //

const char* tableIsFull() {
	return "error: table is full.";
}

const char* tableIsEmpty() {
	return "error: table is empty.";
}



