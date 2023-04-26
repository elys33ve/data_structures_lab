#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"


using namespace std;




// change duplicate ids
void fix_duplicates(int *ids, int j) {
	for (int i=0; i<j-1; i++) {
		while (ids[j] == ids[i] || ids[j] == 0) {
			ids[j] = (123456 * (rand() % 100)) % 100000;
			fix_duplicates(ids, j);
		}
	}
}



// fill student info arrays
void get_info(string *fnames, string *lnames, int *ids, int size) {
	string word, filename = "random_names.txt";
	ifstream file; file.open(filename);
	int f = 0, l = 0, i = 0;

	// get names from file
	while (!file.eof() && l < size) {
		file >> word;

		if (i % 2 == 0) {	// firstnames
			fnames[f] = word; f++;
		} else {			// lastnames
			lnames[l] = word; l++;
		}
		i++;
	} file.close();

	// create id numbers
	for (i=0; i<size; i++) {
		ids[i] = (123456 * (rand() % 100)) % 100000;
		fix_duplicates(ids, i);
	}
}





int main() {
	int n_students = 50;
	List list;
	int sort, direction;
	
	// student info
	string firstnames[n_students], lastnames[n_students]; int id_nums[n_students];
	get_info(firstnames, lastnames, id_nums, n_students);
	Info *info[n_students] = { };


	// add to linked list
	for (int i=0; i<n_students; i++) {
		info[i] = new Info(firstnames[i], lastnames[i], id_nums[i]);
		list.addItem(info[i]);
	}


	// user interface
	// choose sort methd
	cout << "choose a sort method:\n";
	cout << "\tbubble sort -- firstname (1)\n";
	cout << "\tinsertion sort -- lastname (2)\n";
	cout << "\tmerge sort -- id number (3)\n";
	cin >> sort;
	// choose direction
	cout << "\nshow in ascending [z to a] (0) or descending [a to z] (1) order?  ";
	cin >> direction;


	// descending order
	if (direction == 1 || direction == 0) {
		// bubble sort
		if (sort == 1) {
			list.bubble_sort(direction);
			list.print_list();
		}
		// insertion sort
		else if (sort == 2) {
			list.insertion_sort(direction);
			list.print_list();
		}
		// merge sort
		else if (sort == 3) {
			list.merge_sort(direction);
			list.print_list();
		}
	}


	// delete nodes
	for (int i=0; i<n_students; i++) { delete info[i]; }

	return 0;
}