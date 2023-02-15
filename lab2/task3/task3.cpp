// This program produces a sales report for DLC, Inc.
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "t3_class.h"

using namespace std;


// Function prototypes
void showOrder(Sales, int);
void dualSort(Sales, int);
void showTotals(Sales, int);

// NUM_PRODS is the number of products produced.
const int NUM_PRODS = 9;        // could do (lines in file) / (6)

int main() {
    Sales x[NUM_PRODS];         
    ifstream file;
    string filename = "t3_input.txt";   // t3_input.txt , t3_empty.txt
    file.open(filename, ios::in);
    string ids;
    int len;

    // test if file exists
    if (!file.is_open()) {
        std::cout << "File does not exist" << endl;
        return 0;
    }

    // set values from input file
    for (int i = 0; i < NUM_PRODS; i++) {

        
        getline(file,ids);
        if (ids.length() == 0) {        // if empty file/less products than NUM_PRODS
            for (i; i < NUM_PRODS; i++) {
                x[i].setId(0);
                x[i].setUnits(0);
                x[i].setPrices(0);
                x[i].setTax(0);
            }
            break; 
        }

        // id
        ids = ids.substr(4,ids.length()-1);
        if (ids.length() != 0) { x[i].setId(stoi(ids)); }   // if not empty
        else { x[i].setId(0); }

        // units
        getline(file,ids);
        ids = ids.substr(7, ids.length()-1);
        if (ids.length() != 0) { x[i].setUnits(stoi(ids)); }   // if not empty
        else { x[i].setUnits(0); }

        // price
        getline(file,ids);
        ids = ids.substr(7, ids.length()-1);                  
        if (ids.length() != 0) { x[i].setPrices(stod(ids)); }   // if not empty
        else { x[i].setPrices(0); }

        // tax
        getline(file,ids);  
        ids = ids.substr(11, ids.length()-1);
        if (ids == "True") { x[i].setTax(true); }           // if true
        else if (ids == "False") { x[i].setTax(false); }    // if false

        // description
        getline(file,ids);
        ids = ids.substr(13, ids.length()-1);
        if (ids.length() != 0) { x[i].setDescription(ids); }   // if not empty

        getline(file,ids);
    }

    // output
    cout << "Product Number\tSales\n";
    cout << "----------------------------------\n";
    for (int index = 0; index < NUM_PRODS; index++){
        cout << x[index].getId() << "\t\t$";
        cout << setw(8) << x[index].sale_amt() << endl;
    }
    cout << endl;

    int totalUnits = 0;
    double totalSales = 0.0;

    for (int index = 0; index < NUM_PRODS; index++)
    {
        totalUnits += x[index].getUnits();
        totalSales += x[index].sale_amt();
    }
    cout << "Total units Sold:  " << totalUnits << endl;
    cout << "Total sales:      $" << totalSales << endl;

    return 0;
}
