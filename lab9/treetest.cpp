
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Tree.h"
//#include "Data.h"
//#include "Test.h"

using namespace std;

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
		cout << "got " << word << endl;
		
		Data text(word);
		Data* x;
		x = tree.find_item(text); 
		if (x == nullptr) {
			try {
				tree.insert(text);
			} catch (const char* msg) { cout << msg << endl; }
		}

	}

	tree.x();




	return 0;
}