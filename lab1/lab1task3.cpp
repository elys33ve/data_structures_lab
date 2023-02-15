// This program produces a sales report for DLC, Inc.
#include <iostream>
#include <iomanip>
using namespace std;



// NUM_PRODS is the number of products produced.
const int NUM_PRODS = 9;


struct sales {
    int id[NUM_PRODS];
    int units[NUM_PRODS];
    double prices[NUM_PRODS];
    double sale[NUM_PRODS];
};


// Function prototypes
void calcSales(sales&, int);
void showOrder(sales, int);
void dualSort(sales&, int);
void showTotals(sales, int);



int main()
{
    sales product_sales{ { 914, 915, 916, 917, 918, 919, 920, 921, 922 }, { 842, 416, 127, 514, 437, 269, 97, 492, 212 }, 
        { 12.95, 14.95, 18.95, 16.95, 21.95, 31.95, 14.95, 14.95, 16.95 }, {0,0,0,0,0,0,0,0,0} };


    // Calculate each product's sales.
    calcSales(product_sales, NUM_PRODS);

    // Sort the elements in the sales array in descending
    // order and shuffle the ID numbers in the id array to
    // keep them in parallel.
    dualSort(product_sales, NUM_PRODS);

   // Set the numeric output formatting.
    cout << setprecision(2) << fixed << showpoint;

    // Display the products and sales amounts.
    showOrder(product_sales, NUM_PRODS);

    // Display total units sold and total sales.
    showTotals(product_sales, NUM_PRODS);
    return 0;
}

//****************************************************************
// Definition of calcSales. Accepts product sales array as argument. 
// The size of these arrays is passed into the num parameter. 
// This function calculates each product's sales by multiplying 
// its units sold by each unit's price. The result is stored in 
// the sales.sale array.     
//****************************************************************

void calcSales(sales& product, int num)
{
    for (int index = 0; index < num; index++)
        product.sale[index] = product.units[index] * product.prices[index];
}

//***************************************************************
// Definition of function dualSort. Accepts product sales array
// as argument. The size of the arrays is passed into size.  
// This function performs a descending order selection sort on  
// the sales array. The elements of the id array are exchanged  
// identically as those of the sales array. size is the number  
// of elements in each array.                                   
//***************************************************************

void dualSort(sales& product, int size)
{
    int startScan, maxIndex, tempid;
    double maxValue;

    for (startScan = 0; startScan < (size - 1); startScan++)
    {
        maxIndex = startScan;
        maxValue = product.sale[startScan];
        tempid = product.id[startScan];
        for (int index = startScan + 1; index < size; index++)
        {
            if (product.sale[index] > maxValue)
            {
                maxValue = product.sale[index];
                tempid = product.id[index];
                maxIndex = index;
            }
        }
        product.sale[maxIndex] = product.sale[startScan];
        product.id[maxIndex] = product.id[startScan];
        product.sale[startScan] = maxValue;
        product.id[startScan] = tempid;
    }
}

//****************************************************************
// Definition of showOrder function. Accepts product sales array
// as argument. The size of these arrays is passed into num.    
// The function first displays a heading, then the sorted list   
// of product numbers and sales.                                 
//****************************************************************

void showOrder(sales product, int num)
{
    cout << "Product Number\tSales\n";
    cout << "----------------------------------\n";
    for (int index = 0; index < num; index++)
    {
        cout << product.id[index] << "\t\t$";
        cout << setw(8) << product.sale[index] << endl;
    }
    cout << endl;
}

//*****************************************************************
// Definition of showTotals function. Accepts product sales array 
// as argument. The size of these arrays is passed into num.     
// The function first calculates the total units (of all          
// products) sold and the total sales. It then displays these     
// amounts.                                                       
//*****************************************************************

void showTotals(sales product, int num)
{
    int totalUnits = 0;
    double totalSales = 0.0;

    for (int index = 0; index < num; index++)
    {
        totalUnits += product.units[index];
        totalSales += product.sale[index];
    }
    cout << "Total units Sold:  " << totalUnits << endl;
    cout << "Total sales:      $" << totalSales << endl;
}
