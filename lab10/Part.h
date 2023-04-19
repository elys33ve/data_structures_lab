#include <iostream>
#include <string>
#pragma once

using namespace std;



// ------------------------------ class Item ------------------------------ //

/*	from lab 8:
	class to be used as item stored in list:
		- overloaded >, <, and == operators
*/

int curr_day = 21;
int curr_month = 3;
int curr_year = 2023;

class Part {
	private:
		int SKU;					// stock keeping number
		string description;
		int price;
		string UOM;					// unit of measure
		double quantityOnHand;
		int leadTime = 5;				// number of days takes to order if none on hand

	public:
		Part() {}
		Part(int sku, string descript, int pr, string uom);
		Part(int sku, string descript, int pr, string uom, double quantity);
		~Part() {}
		

		// get part info -- returns str containing sku with description
		string getPartInfo();

		// get price -- returns price
		int getPrice();

		// in stock -- returns bool for if the item is in stock
		bool inStock();

		// available -- accepts date as param, returns bool for if item is/can be in stock
		bool available(int day, int month, int year);


		// operator overload
		operator string ();

		int getSku () { return SKU; }
		string getStrSku () { return to_string(SKU); }

		// show -- print key memebers of class to screen
		void show();
};



// ------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------



// constructor
Part::Part(int sku, string descript, int pr, string uom) {
	SKU = sku;
	description = descript;
	price = pr;
	UOM = uom;
	quantityOnHand = 0;
}
Part::Part(int sku, string descript, int pr, string uom, double quantity) {
	SKU = sku;
	description = descript;
	price = pr;
	UOM = uom;
	quantityOnHand = quantity;
}


// get part info
string Part::getPartInfo() {
	return "SKU: " + to_string(SKU) + "\nDescription: " + description;
}

// get price
int Part::getPrice() {
	return price;
}

// in stock
bool Part::inStock() {
	if (quantityOnHand > 0) {
		return true;
	}
	return false;
}

// available
bool Part::available(int day, int month, int year) {
	if (inStock()) { return true; }			// if in stock now

	int days = 365*(year - curr_year) + 30*(month - curr_month) + (day - curr_day);

	if (days > leadTime) { return true; }		// if can be available
	return false;
}


// show
void Part::show() {
	std::cout << "sku: " << SKU << std::endl;
	std::cout << "description: " << description << std::endl;
	std::cout << "price: " << price << std::endl;
	std::cout << "uom: " << UOM << std::endl;
	std::cout << "quantity: " << quantityOnHand << std::endl;
	std::cout << "lead time: " << leadTime << std::endl;
}


// operator overloads
Part::operator string() {
	return to_string(SKU);
}






