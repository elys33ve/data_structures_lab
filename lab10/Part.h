#include <iostream>
#include <string>
#pragma once

using namespace std;

int curr_day = 19;
int curr_month = 4;
int curr_year = 2023;

// modified Part item class from lab 8
class Part {
	private:
		int SKU;					// stock keeping number
		string description;			// description
		int price;					// price
		string UOM;					// unit of measure
		double quantity_on_hand;	// quantity on hand
		int leadTime = 5;			// number of days takes to order if none on hand

	public:
		Part() {}
		Part(int sku);			// just sku for easier testing
		Part(int sku, string descript, int pr, string uom);
		Part(int sku, string descript, int pr, string uom, double quantity);
		~Part() {}
		
		// get part info -- returns str containing sku with description
		string get_info();

		// in stock -- returns bool for if the item is in stock
		bool in_stock();

		// available -- accepts date as param, returns bool for if item is/can be in stock
		bool available(int day, int month, int year);

		// get sku number (key to hash)
		int get_sku () { return SKU; }						// return int sku
		string get_str_sku () { return to_string(SKU); }	// return str sku
		operator string () { return to_string(SKU); }		// operator overload that i forgot about but it is indeed here
		
		// get other info
		string get_description() { return description; }
		int get_price() { return price; }
		string get_uom() { return UOM; }
		double get_quantity() { return quantity_on_hand; }


		// show -- print key memebers of class to screen
		void show();
};





// constructors
Part::Part(int sku) {
	SKU = sku;
	description = "[description]";
	price = 10;
	UOM = "[unit of measure]";
	quantity_on_hand = 10;
}
Part::Part(int sku, string descript, int pr, string uom) {
	SKU = sku;
	description = descript;
	price = pr;
	UOM = uom;
	quantity_on_hand = 0;
}
Part::Part(int sku, string descript, int pr, string uom, double quantity) {
	SKU = sku;
	description = descript;
	price = pr;
	UOM = uom;
	quantity_on_hand = quantity;
}


// get part info
string Part::get_info() {
	return "SKU: " + to_string(SKU) + "\nDescription: " + description;
}

// in stock
bool Part::in_stock() {
	if (quantity_on_hand > 0) {
		return true;
	}
	return false;
}

// available
bool Part::available(int day, int month, int year) {
	if (in_stock()) { return true; }			// if in stock now

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
	std::cout << "quantity: " << quantity_on_hand << std::endl;
	std::cout << "lead time: " << leadTime << std::endl;
}






