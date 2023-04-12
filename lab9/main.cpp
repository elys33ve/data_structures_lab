#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Tree.h"
//#include "Data.h"
//#include "Test.h"

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

	bool test = true;

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
	string word;
	while (file >> word) {
		// get and strip word for punctuation / spaces
        strip(&word);	
		
		// find word in tree
		Data text(word);
		Data* x = tree.find(text); 
		// if not found, insert word
		if (x == nullptr) {
			try {
				tree.insert(text);
			} catch (const char* msg) { cout << msg << endl; }
		}
	} 
	word = "0";		// clear for input


	// user interface stuff kinda
	cout << "file text has been added to tree.\n";
	cout << "would you like to view...\n";
	cout << "\twords in ascending order (1)\n";
	cout << "\twords in descending order (2)\n";
	cout << "\tget a specific word's frequency (3)\n";
	cout << "\tremove an item from tree (4)\n";
	cout << "\tshow tree/node info (5)\n";
	cout << "\texit (6)\n";


	// get input 
	while (true) {
		cin >> word;

		// print ascending
		if (word == "1") {				
			tree.print_ascending();
			break;	
		} 
		// print descending
		else if (word == "2") {		
			tree.print_descending();
			break;
		} 
		// get/find word frequency
		else if (word == "3") {		
			cout << "\nwhich word would you like to find? ";
			cin >> word;
			Data f;

			// get item
			try { f = tree.find(word);
			} catch (const char* msg) { cout << msg << endl; break; }

			// show result
			cout << "word: " << f.word << "\t\tfrequency: " << f.freq << endl;
			break;
		} 
		// remove item
		else if (word == "4") {		
			cout << "\nwhich item would you like to remove? ";
			cin >> word; strip(&word);
			Data *rm;
			
			// remove word
			try { rm = tree.remove(word);
			} catch (const char* msg) { cout << msg << endl; break; }

			// print result
			if (rm == nullptr) {
				cout << "could not remove word.\n";
			} else {
				cout << "removed " << rm->word << endl;
			} break;
		} 
		// show info
		else if (word == "5") {		
			tree.show();
			break;
		} 
		// exit
		else if (word == "6") {	break; }

		// invalid input
		cout << "please select a number to indicate your choice.\n";
	}

	return 0;
}