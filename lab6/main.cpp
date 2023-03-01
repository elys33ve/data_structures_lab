#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Stack.h"
#include "Queue.h"

using namespace std;

int main() {
    bool continueProgram = true;
    while (continueProgram) {
        cout << "use data from file (1) or command line (2)?, or quit (3): ";
        int opt;
        cin >> opt;
        cin.ignore(); 

        if (opt == 1) {
            ifstream inputFile;
            string filename;
            bool fileFound = false;
            while (!fileFound) {
                cout << "Enter the name of the file to read: ";
                getline(cin, filename);
                inputFile.open(filename);
                if (!inputFile) {
                    cout << "File not found. Please enter a valid filename." << endl;
                }
                else {
                    fileFound = true;
                }
            }

            Stack<char> wordStack(20);
            Queue<string> wordQueue(20);
            string line;
            while (getline(inputFile, line)) {
                stringstream ss(line);
                string word;
                while (ss >> word) {
                    string reversedWord = "";
                    for (int i = word.length() - 1; i >= 0; i--) {
                        reversedWord += word[i];
                    }
                    wordQueue.enqueue(reversedWord);
                }
                while (!wordQueue.empty()) {
                    cout << wordQueue.dequeue() << " ";
                }
                cout << endl;
            }

            inputFile.close();
            break;
        }

        else if (opt == 2) {
            string inputLine;
            cout << "Enter a line of text to reverse: ";
            getline(cin, inputLine);

            Stack<char> wordStack(20);
            Queue<string> wordQueue(20);
            stringstream ss(inputLine);
            string word;
            while (ss >> word) {
                string reversedWord = "";
                for (int i = word.length() - 1; i >= 0; i--) {
                    reversedWord += word[i];
                }
                wordQueue.enqueue(reversedWord);
            }
            while (!wordQueue.empty()) {
                cout << wordQueue.dequeue() << " ";
            }
            cout << endl;

            break;
        }

        else if (opt == 3) {
            continueProgram = false;
            break;
        }

        else {
            cout << "Invalid input. Please enter 1, 2, or 3." << endl;
            
        }
    }

    return 0;
}