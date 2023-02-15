// Data Structures Lab 2: Task 1
// create script that takes user input for name of file,
// then reads the first ten lines of that file.
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    int i = 0;
    string line;                        // initiate str var for readlines
    string filename;                    // user input for filename

    cout << "filename:  ";
    cin >> filename;

    fstream readfile;
    readfile.open(filename, ios::in);       // read from file

    while (getline (readfile, line) && i < 10){     // read file line by line
        cout << line << endl;
        i++;
    }

    return 0;
}