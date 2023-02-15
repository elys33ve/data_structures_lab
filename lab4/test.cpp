#include <iostream>
#include <string>
#include <vector>
#include "Shows.h"
#include "Shows_TV.h"
#include "Shows_Movie.h"

using namespace std;


int main(){
	TV test;                                //This part tests if the list works
	test.set_title("test");                  
	test.set_description("also test");
	test.Details();
	test.set_list("sn1ep1", 1, 1);
	test.set_list("sn1ep2", 2, 1); 
	test.set_list("sn1ep3", 3, 1);
	test.set_list("sn2ep1", 1, 2);
	test.set_list("sn2ep2", 2, 2);
	test.set_list("sn2ep3", 3, 2);
	test.Play();

	/* --- Task 3 starts here --- */

	bool flag = true;
	int opt;
	string title, desc, oc;
	char cont;

	while (flag) {
		cout << "Press 1 for an instance of Show." << endl <<
			"Press 2 for an instance of Movie." << endl <<
			"Press 3 for an instance of TV Show." << endl <<
			"Press 4 for an instance of a MOVIE declared as a Show" << endl <<
			"Press 5 for an instance of a TV Show declared as a Show" << endl;
		cin >> opt;

		if (opt == 1) {
			cout << "enter title: " << endl; 
			cin >> title;
			cout << "enter description: " << endl;
			cin >> desc;
			Shows x;
			x.set_title(title);
			x.set_description(desc);
			x.Details();
		}
		else if(opt == 2) {
			cout << "enter title: " << endl;
			cin >> title;
			cout << "enter description: " << endl;
			cin >> desc;
			cout << "enter opening credits: " << endl;
			cin >> oc;
			Movie x;
			x.set_title(title);
			x.set_description(desc);
			x.set_credits(oc);
			x.Details();
		}
		else if (opt == 3) {
			char option;
			bool flag2 = true;
			cout << "enter title: " << endl;
			cin >> title;
			cout << "enter description: " << endl;
			cin >> desc;
			cout << "Do you want to set episodes details? (y or n) " << endl;
			cin >> option;
			TV x;
			x.set_title(title);
			x.set_description(desc);
			while (flag2) {
				int sn, ep;
				string epi;
				cout << "enter season number: " << endl;
				cin >> sn;
				cout << "enter episode number: " << endl;
				cin >> ep;
				cout << "enter episode name: " << endl;
				cin >> epi;
				x.set_list(epi, ep, sn);
				cout << "Do you want to continue?" << endl;
				cin >> option;
				if (option != 'y') {
					flag2 = false;
				}
			}
			x.Details();
		}
		else if (opt == 4) {                               // I am not sure if this is what they ment by option 4 and 5 
			cout << "enter movie title: " << endl;
			cin >> title;
			cout << "enter movie description: " << endl;
			cin >> desc;
			Shows x;
			x.set_title(title);
			x.set_description(desc);
			x.Details();
		}

		else if (opt == 5) {
			cout << "enter show title: " << endl;
			cin >> title;
			cout << "enter show description: " << endl;
			cin >> desc;
			Shows x;
			x.set_title(title);
			x.set_description(desc);
			x.Details();
		}

		else {
			cout << "Please enter a valid option" << endl;
		}
		cout << "Do you want to continue?(y or n)" << endl;
		cin >> cont;
		if (cont != 'y') {
			flag = false;
		}
	}
	return 0;


}