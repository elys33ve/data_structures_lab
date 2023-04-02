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

	- get frequency of each word in input file 
	- 	



*/


// ------ fix: 
// public private functions


/* abcdefg
		
	c
   d a
  g  b


*/


int main () {
	Tree<Data> tree;
	cout << tree.tsize << endl;

	Data* c = new Data("c",1);
	Data* d = new Data("d",2);
	Data* a = new Data("a",3);
	Data *b = new Data("b",4);
	Data *g = new Data("g",5);
	

	tree.insert(c);
	tree.insert(d);
	tree.insert(a);
	tree.insert(b);
	tree.insert(g);

	cout << "size: " << tree.tsize << endl;
	cout << "current: " << tree.get_key() << endl;

	

	// how tf do you return an array of pointers

	int j = 0;
	int* i = &j;
	//x = tree.get_descending(tree.root);

 	Data* arr = tree.get_all_ascending();
	
	cout << endl << typeid(arr).name() <<endl;
	cout << arr <<endl;
	cout << arr->word <<endl;
	cout << arr->word << endl;


/* 
 	for (int k=0; k<5; k++) {
		cout << (arr + 1)->word << endl;	
	}

 */

	delete a,b,d,c,g;
	return 0;
}