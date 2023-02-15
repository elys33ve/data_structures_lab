#pragma once

class Distance {
private:
	int feet;
	double inches;
	double meters;
	
public:
	Distance();				// empty constructor
	Distance(int, double);	// set feet and inches constructor
	Distance(int);			// set feet constructor
	Distance(double);		// set inches constructor

	void set_feet(int x);		// set feet
	void set_inches(double x);	// set inches and overflow into feet if inches > 12
	void set_meters();			// set meters for current value of feet and inches

	int get_feet();
	double get_inches();
	double get_meters();

	void operator+(const Distance& obj);	//	+
	void operator-(const Distance& obj);	//	-
	void operator*(const Distance& obj);	//	*
	void operator/(const Distance& obj);	//	/
	bool operator==(const Distance& obj);	//	==

	void print();
};