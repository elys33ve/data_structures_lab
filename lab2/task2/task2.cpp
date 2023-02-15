// Data Structures Lab 2: Task 2
// modify code from lab 1 task 2 to write the outputs to a file
// rather than the command line. take user input for file name.
// if the file exists, append task 2 output to the end. if file does
// not exist, create file to output data
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;



// lab 1 task 2 modified to output everything to file
void task2 (string filename) {         
	const int NUM_DIVS = 3;           // Number of divisions
	const int NUM_QTRS = 4;           // Number of quarters
	double sales[NUM_DIVS][NUM_QTRS]; // Array with 3 rows and 4 columns.
	double totalSales = 0;            // To hold the total sales.
	int div, qtr;                     // Loop counters.

    fstream outfile(filename, ios::app);    // append to file

	cout << "\nThis program will calculate the total sales of\n";
	cout << "all the company's divisions.\n";
	cout << "Enter the following sales information:\n\n";

	// Nested loops to fill the array with quarterly
	// sales figures for each division.
	for (div = 0; div < NUM_DIVS; div++)		
	{
		for (qtr = 0; qtr < NUM_QTRS; qtr++)
		{
			cout << "Division " << (div + 1);
			cout << ", Quarter " << (qtr + 1) << ": $";
			cin >> sales[div][qtr];
		}
		cout << endl;
	}

	outfile << fixed << showpoint << setprecision(2);
	outfile << "The sales for the company is: $" << endl;
	outfile << "Div" << "\t\t" << "Q1" << "\t\t" << "Q2" << "\t\t" << "Q3" << "\t\t" << "Q4" << endl;

	// Nested loops to display the quarterly sales figures for each division.
	for (div = 0; div < NUM_DIVS; div++)
	{
		outfile << div + 1 << "\t";
		for (qtr = 0; qtr < NUM_QTRS; qtr++)
		{
			outfile << "$" << sales[div][qtr] << "\t";		// output sales from array
            totalSales += sales[div][qtr];
		}
		outfile << endl; // Print blank line.
	}

	outfile << endl;
	outfile << "The total sales for the company are: $";
	outfile << totalSales << endl;

    outfile.close();
}



int main() {   
    string filename;            // str to hold user inputed filename
	cout << "output file:  ";
    cin >> filename;            // get user input for filename
    

    ifstream outfile(filename);         // test if file exists

    // file exists -- append data to file
    while (outfile.fail()){                           
        fstream outfile(filename, ios::app);        // append newlines after existing data in file
		outfile.close();
    }
    

    task2(filename);        // run lab 1 task 2 but output results to chosen file

    return 0;
}