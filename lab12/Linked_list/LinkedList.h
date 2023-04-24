#pragma once

#include <iostream>
#include <string>
#include "Info.h"
#include "Node.h"

using namespace std;



class List {
	private:
		int location;
		int length;

		Node *head;


		void bubble_sort(int x);		// sort firstname
		void insertion_sort(Node *node);	// sort lastname
		void radix_sort(Node *node);		// sort id number

	public:
		List();
		~List();

		void addItem(Info *item);


		void swap(Node *x, Node *y);


		void bubble_sort_ascending() { bubble_sort(0); }
		void bubble_sort_descending() { bubble_sort(1); }


		bool isEmpty();

		void print_list();

		int size() { return length; }

		bool higher(string word1, string word2);
		bool lower(string word1, string word2);
		bool same(string word1, string word2);
};

