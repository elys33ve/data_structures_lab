#include <iostream>
#include <string>
#include "Part.h"

using namespace std;





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






