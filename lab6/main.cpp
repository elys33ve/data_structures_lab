#include <iostream>
#include <string>
#include <fstream>
#include "Stack.h"
#include "Queue.h"

// order files are compiled is important - compile headers first
// throw errors from class - try/catch in main



int main () {
	std::string input;

	// prompt for either file or command line input
	while (input != "0" or input != "1") {
		std::cout << "\nuse data from file (0) or command line (1)?	";
		std::cin >> input;
	}

	// if user chooses file
	if (input == "0") {
		std::fstream input_file;
		std::string filename;
		std::string line;
		char* letter = new char;

		// prompt for name of file
		std::cout << "\nname of input file:\t";
		std::cin >> filename;

		input_file.open(filename, std::ios::in);	// open file to read

		// continue to ask filename if fails to open
		while (input_file.fail()) {			
			std::cout << "could not open file '" << filename << "'. please enter different file.\n";
			std::cout << "\nname of input file:\t";
			std::cin >> filename;
			input_file.open(filename, std::ios::in);
		}

		// read in each line of file and reverse order of letters in each word
		while (getline(input_file, line)){		// read file line by line
			int len = 0;	// current word length
			Stack<char> *stack = new Stack<char>(sizeof(line));		// (temp for individual words)
			Queue<char> *queue = new Queue<char>(sizeof(line));		// (contains full modified line)
			
			
			// get individual words in each line
			for (int i=0; i<line.length(); i++) {
				*letter = line[i];
				// add letters to stack
				if (!isspace(line[i])) {		// if character not whitespace, add to stack
					try {
						stack->push(letter);
					}
					catch (const char* msg) {				
						std::cout << msg << std::endl;		// if exception is thrown, output error message
					}
				}
				// add letters to queue in reverse order
				if (isspace(line[i]) || i == line.length()-1) {
					// reverse word order
					for (int j=0; j<len; j++) {
						try {
							queue->in_queue(stack->pop());		// add to queue from top of stack
						}
						catch (const char* msg) {				
							std::cout << msg << std::endl;		// if exception is thrown, output error message
						}
					}
					
					// add space
					if (i < line.length()-1) { 
						try {
							queue->in_queue(letter);
						}
						catch (const char* msg) {				
							std::cout << msg << std::endl;		// if exception is thrown, output error message
						} 
					}
	
					len = -1;
					stack->empty_stack();
				}
				len++;
			}

			// print modified line to screen
			std::cout << std::endl;
			for (int i=0; i<line.length(); i++) {
				std::printf("%c", queue->pop());
			}
			std::cout << std::endl;


			delete stack;
			delete queue;
		}

		input_file.close();
	}
	// if user chooses command line
	else if (input == "1") {
		while (input != "n" && input != "N") {
			// prompt user for line of text to modify
			std::string line;
			std::cout << "\nenter a line text to modify: \n";
			std::cin >> line;


			int len = 0;	// current word length
			Stack<char> *stack = new Stack<char>(sizeof(line));		// (temp for individual words)
			Queue<char> *queue = new Queue<char>(sizeof(line));		// (contains full modified line)
			char* letter = new char;
			
			// get individual words from line
			for (int i=0; i<line.length(); i++) {
				*letter = line[i];
				// add letters to stack
				if (!isspace(line[i])) {		// if character not whitespace, add to stack
					try {
						stack->push(letter);
					}
					catch (const char* msg) {				
						std::cout << msg << std::endl;		// if exception is thrown, output error message
					}
				}
				// add letters to queue in reverse order
				if (isspace(line[i]) || i == line.length()-1) {
					// reverse word order
					for (int j=0; j<len; j++) {
						try {
							queue->in_queue(stack->pop());		// add to queue from top of stack
						}
						catch (const char* msg) {				
							std::cout << msg << std::endl;		// if exception is thrown, output error message
						}
					}
					
					// add space
					if (i < line.length()-1) {
						try {
							queue->in_queue(letter);
						}
						catch (const char* msg) {				
							std::cout << msg << std::endl;		// if exception is thrown, output error message
						} 
					}
	
					len = -1;
					stack->empty_stack();
				}
				len++;
			}

			// print modified line to screen
			std::cout << std::endl;
			for (int i=0; i<line.length(); i++) {
				std::printf("%c", queue->pop());
			}
			std::cout << std::endl;

			delete stack;
			delete queue;

			// ask user if they would like to continue
			std::cout << "\nwould you like to continue? (y/n)\t";
			std::cin >> input;
		}
	}

	return 0;
}