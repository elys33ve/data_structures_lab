#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "This.h"
#include "This.cpp"


using namespace std;





int main() {
	Tree tree;

	tree.insert(5);
	tree.insert(3);
	tree.insert(2);
	tree.insert(6);
	tree.insert(7);
	tree.insert(8);
	
	cout << tree.get_size() << endl;


	return 0;
}

