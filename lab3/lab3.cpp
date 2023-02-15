#include <iostream>
#include <string>
#include "lab3.h"

using namespace std;


// CONSTRUCTORS
Distance::Distance(){
	set_feet(0);
	set_inches(0);
}
Distance::Distance(int x, double y){		// set feet and inches
	set_feet(x);
	set_inches(y);
}
Distance::Distance(int x){					// set feet
	set_feet(x);
	set_inches(0);
}
Distance::Distance(double x){				// set inches
	set_feet(0);
	set_inches(x);
}


// SETTERS
void Distance::set_feet(int x){				// set feet
	feet = x;
	set_meters();	// update meters
}
void Distance::set_inches(double x){		// set inches; account for inches > 12
	int x_int = static_cast<int>(x);
	double x_dec = x - x_int;

	if (x < 12) {
		inches = x;
	}
	else {
		feet = feet + (x_int / 12);
		inches = (x_int % 12) + x_dec;
	}
	set_meters();	// update meters
}
void Distance::set_meters(){				// set meters for current value of feet and inches
	double x = 0.3048;		// feet to meters
	double y = 0.0254;		// inches to meters
	meters = (feet * x) + (inches * y);
}


// GETTERS
int Distance::get_feet(){
	return feet;
}
double Distance::get_inches(){
	return inches;
}
double Distance::get_meters(){
	return meters;
}


// OVERLOADED OPERATORS
void Distance::operator+(const Distance& obj){		//	+
	feet += obj.feet;
	set_inches(inches + obj.inches);
}
void Distance::operator-(const Distance& obj){		//	-
	double total_in1 = (feet * 12) + inches;			
	double total_in2 = (obj.feet * 12) + obj.inches;
	feet = 0;
	set_inches(total_in1 - total_in2);
}
void Distance::operator*(const Distance& obj){		//	*	(unrealistic for distance)
	feet *= obj.feet;
	set_inches(inches * obj.inches);
}
void Distance::operator/(const Distance& obj){		//	/	(unrealistic for distance)
	double total_in1 = (feet * 12) + inches;			
	double total_in2 = (obj.feet * 12) + obj.inches;
	feet = 0;
	if (total_in2 != 0) { set_inches(total_in1 / total_in2); }
	else { cout << "cannot divide by zero.\n\n"; }
}
bool Distance::operator==(const Distance& obj){		//	==
	double total_in1 = (feet * 12) + inches;			
	double total_in2 = (obj.feet * 12) + obj.inches;
	if (total_in1 == total_in2){
		return true;
	}
	else{ return false; }
}


// PRINT OUT
void Distance::print() {
	if (feet == 1) { cout << get_feet() << " foot, "; }					// "foot"
	else { cout << get_feet() << " feet, "; }							// "feet"		
	if (inches == 1) { cout << get_inches() << " inch" << endl; }		// "inch"
	else { cout << get_inches() << " inches" << endl; }					// "inches"
	cout << "(";
	if (meters == 1) { cout << get_meters() << " meter"; }				// "meter"
	else { cout << get_meters() << " meters"; }							// "meters"
	cout << ")" << endl;
}
