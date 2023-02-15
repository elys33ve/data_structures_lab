// definitions for class member functions
#include "t3_class.h"

double Sales::sale_amt() {
	return this -> units * this -> prices;
}


// set functions

void Sales::setId(int id) {
	this->id = id;
}

void Sales::setUnits(int unit) {
	this->units = unit;
}

void Sales::setPrices(double price) {
	this->prices = price;
}

void Sales::setDescription(std::string desc) {
	this->description = desc;
}

void Sales::setTax(bool x) {
	this->TaxExempt = x;
}


// get functions

int Sales::getId() {
	return this->id;
}

int Sales::getUnits() {
	return this->units;
}

double Sales::getPrice() {
	return this->prices;
}

std::string Sales::getDesc() {
	return this->description;
}

bool Sales::getTax() {
	return this->TaxExempt;
}
