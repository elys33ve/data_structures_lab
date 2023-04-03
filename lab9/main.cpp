#include <iostream>
#include <string>
#include <typeinfo>
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


int main () {
	Tree<Data> tree;


	Data* c = new Data("c",1);



	return 0;
}