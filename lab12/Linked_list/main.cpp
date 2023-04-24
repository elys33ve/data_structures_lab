#include <iostream>
#include <string>
#include "LinkedList.h"

// again, ill delete later but vscode being annoying and i dont have time to 
// deal w it rn
#include "LinkedList.cpp"

using namespace std;


int main() {
	List list;
	
	string firstnames[5] = { "xasfdf", "fkkfkf", "eeeeef", "ssdsdsdf", "pppppf" };
	string lastnames[5] = { "sdfsdfl", "kkkkkkl", "ytytytl", "wwwwwl", "trl" };
	int id_nums[5] = { 1212, 333, 4424, 99, 3200 };
	Info *info[5] = { };

	for (int i=0; i<5; i++) {
		info[i] = new Info(firstnames[i], lastnames[i], id_nums[i]);
		list.addItem(info[i]);
	}

	list.print_list();



	for (int i=0; i<5; i++) { delete info[i]; }

	return 0;
}