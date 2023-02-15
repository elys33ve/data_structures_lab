#include <iostream>
#include <string>
#include "lab3.h"

using namespace std;


// test constructors, getters, and setters
void test_functions(){
	Distance test;			// empty constructor
	cout << "\n\tempty constructor" << endl;
	test.print();

	Distance test1(5, 3.2);	// cosntructor: set feet and inches
	cout << "\n\tset feet and inches (constructor)" << endl;
	test1.print();

	Distance test2(6);		// cosntructor: set feet
	cout << "\n\tset feet (constructor)" << endl;
	test2.print();

	Distance test3(11.0);	// cosntructor: set inches
	cout << "\n\tset inches (constructor)" << endl;
	test3.print();

	// test setters and getters
	cout << endl << "\tset_feet(3) and set_inches(18.2)" << endl;
	test.set_feet(3);
	test.set_inches(18.2);
	cout << "get_feet(): " << test.get_feet() << endl;
	cout << "get_inches(): " << test.get_inches() << endl;
	cout << "get_meters(): " << test.get_meters() << endl;
}


int main (){
	//if (true) { test_functions(); return 0; }

	Distance obj1;		// default empty constructor
	int feet;
	double inches;
	string op;			// user input string
	bool b;				// boolean for compare

	// get initial values for feet and inches
	cout << endl << "feet = ";
	cin >> feet;
	cout << "inches = ";
	cin >> inches;
	cout << endl;

	obj1.set_feet(feet);
	obj1.set_inches(inches);

	while (true) {
		// get operation to perform
		cout << "operation to perform (+, -, *, /, ==):" << endl;
		cin >> op;

		// get values for calculation
		cout << "values used in calculation:" << endl;	
		cout << "feet: ";
		cin >> feet;
		cout << "inches: ";
		cin >> inches;
		cout << endl;

		Distance obj2(feet, inches);	// constructor to set feet and inches

		// perform calculation
		if (op == "+") { obj1 + obj2; }				// 	+
		else if (op == "-") { obj1 - obj2; }		// 	-
		else if (op == "*") { obj1 * obj2; }		// 	*
		else if (op == "/") { obj1 / obj2; }		// 	/
		else if (op == "==") { b = obj1 == obj2; }	//	==
		else { op = "invalid"; }					// invalid input for operation

		// print results
		if (op != "invalid") {
			if ((op == "==") && (b == false)) { cout << "false" << endl; }		// compare bool = false
			else if ((op == "==") && (b == true)) { cout << "true" << endl; }	// compare bool = true
			
			if ((op == "*") || (op == "/")) {
				cout << "(units are not accurate since division or multiplication was used)" << endl;
			}
			obj1.print();
		}
		else {
			cout << "invalid input for operation" << endl;
		}

		// continue ?
		cout << endl << "do you wish to continue? (y/n)" << endl;
		cin >> op;
		cout << endl;
		if (op != "y") {
			break;
		}
	}

	return 0;
}