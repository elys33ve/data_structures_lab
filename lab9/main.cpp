#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
//#include "Tree.h"
//#include "Data.h"
#include "Test.h"

using namespace std;


/*	Binary search tree
	- left subtree contains nodes with keys less than parent's key
	- right subtree contains nodes with keys greater than parent's key
	- no duplicate nodes

	- modify program from hw1 to read input	file
	- get frequency of each word, store word and frequency in a class
	- use Find function to update count, if it returns nullptr, use insert
	- after data is in tree, let user find word and display frequency
	- let user display list of words in descending/ascending order
*/

//------- balance binary tree
// ------ fix ptrs
// log2(n)-1
//operator overloads in node<T>
// make rebalace rotates into functions and add to resort
// fix spacing /tab
// comments
//delete namespace in header -- also not needed funcs in Tree


/*

*/



// function to strip word of extra spaces or punctuation
void strip (string* word) {
	string str = *word;
	int len = str.size();
	int j = 0;

	for (int i=0; i<len; i++) {		// remove non-alphabetic characters
		if (isalpha(str.at(j)) || (str.at(j) == '-' && i < len-1)) {
			char x = str.at(j);
			str.erase(str.begin()+j);
			str.push_back(tolower(x));
		}
		else { j++; }
	}
	str.erase(str.begin(), str.begin()+j);
	*word = str;
}




int main () {
	Tree<Data> tree;

	// open input file
	ifstream file;
	string filename = "test.txt";		
    file.open(filename);

    // test if file exists 
    while (file.fail()) {		// if filename is invalid, prompt for new file
        cout << endl << filename << " does not exist. please enter a different filename." << endl;
		cin >> filename;
		file.open(filename);
    } cout << endl;


	// read file contents by word
	string word, w;


	while (file >> word) {
		// get and strip word for punctuation / spaces

        strip(&word);	
		
		Data text(word);
		Data* x;
		x = tree.find_item(text);
		if (x == nullptr) { 
			try {
				tree.insert(text);
			} catch (const char* msg) { cout << msg << endl; }
		}
		
		//cout << " --" << word << "-- " <<endl;

		//cout << text.word << "\t" << tree.get_size() << endl;

	}
	tree.print_ascending();
	cout << "size: " << tree.get_size() << "\t\t\t" << "root: " << tree.get_root().word << endl;
	cout << "diff: " << tree.get_difference() << "\t\t" << "height: " << tree.get_height() << endl << endl;
	tree.x(); 
	cout << "size: " << tree.get_size() << "\t\t\t" << "root: " << tree.get_root().word << endl;
	cout << "diff: " << tree.get_difference() << "\t\t\t" << "height: " << tree.get_height() << endl << endl;
	tree.print_ascending();
	
	

	//----- put try catch for any insert

	return 0;
}