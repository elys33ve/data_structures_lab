#include <iostream>
#include <string>
#include "Hash.h" 
#include "Item.h"

using namespace std;

/*		Hash table that uses linear probing

Hash table class:
	- template class
	- overloaded == operator and string object conversion (in the data type stored in hash table)
	- methods implimented:
		- constructor -- overload indicates max number of items that can be stored. defult = 100
		- hash -- private function; accepts str and rtns int
			(sum of all ascii values passed in string, modulus by max size of table)
		- add item -- add item from list
		- remove item -- searches list for given item. if found, removes from list and returns. if not found, returns nullptr
		- get item -- returns pointer to item if found in list
		- get length -- returns int for number of items in table
		- destructor
	- all items passed to or from the class should be done via a pointer rather than by value
	- ensure there are no memory leaks
*/

int main () {
	int capacity = 10;
	Hash<Item> table(capacity);

	string s[10] = {"a", "aaa", "dd", "ssfd", "fdsd", "dddddd", "kk", "ddfss", "ooo", "b"};
	Item newitem[capacity];
	for (int i=0; i<10; i++) {
		Item k(s[i]);
		newitem[i] = k;
		table.add_item(&newitem[i]);
	}









	return 0;
}