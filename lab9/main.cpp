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



// function to strip word of extra spaces or punctuation
void strip (string* word) {
	string str = *word;
	int len = str.size();
	int j = 0;

	for (int i=0; i<len; i++) {		// remove non-alphabetic characters
		if (isalpha(str.at(j)) || (str.at(j) == '-' && i < len-1)) {
			char x = str.at(j);
			str.erase(str.begin()+j);
			str.push_back(x);
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
	string word;
	while (!file.eof()) {
		// get and strip word for punctuation / spaces
		file >> word;
        strip(&word);		
		
	}
	//------- for any inserts make catch()
	char x[] = "abcdef";

	
	
	
	

	
	cout << endl << tree.get_size() << endl;


	int j = 0;
	int* i = &j;

	//x = tree.get_descending(tree.root);
/* 
 	Data* arr = tree.get_all_descending();


	Data x;
	for (int i=0; i<tree.get_size(); i++) {
		x = *(arr + i);
		cout << x.word << endl;
	} */
	
	
	return 0;
}