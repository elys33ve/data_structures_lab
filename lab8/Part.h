#include <iostream>
#include <string>

#pragma once

using namespace std;

/*
	class to be used as item stored in list:
		- overloaded >, <, and == operators

*/



class Part {
	private:
		int SKU;					// stock keeping number
		string description;
		int price;
		string UOM;					// unit of measure
		double quantityOnHand;
		int leadTime;				// number of days takes to order if none on hand

	public:
		Part();
		Part(int sku, string descript, int price_, string uom, double quantity=0);
		~Part();
		

		// get part info -- returns str containing sku with description
		string getPartInfo();

		// get price -- returns price
		int getPrice();

		// in stock -- returns bool for if the item is in stock
		bool inStock();

		// available -- accepts date as param, returns bool for if item is/can be in stock
		bool available(int day, int month, int year);


		// operator overloads -- compare sku member of two Part instances
		void operator>(Part &sku);
		void operator<(Part &sku);
		void operator==(Part &sku);
};