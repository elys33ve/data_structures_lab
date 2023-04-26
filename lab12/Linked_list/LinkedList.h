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


		void swap(Node *x, Node *y);
		Node *max();

		void merge_sort(Node **head_ref, int x);	
		Node *sorted_merge(Node *n1, Node *n2, int x);

	public:
		List();
		~List();

		void addItem(Info *item);
		Node *find(int id_num);


		void bubble_sort(int x);			// sort firstname (x: 0=ascending, 1=descending)
		void insertion_sort(int x);			// sort lastname (x: 0=ascending, 1=descending)
		void merge_sort (int x) { merge_sort(&head, x); } // sort id number (x: 0=ascending, 1=descending)


		bool is_empty();

		void print_list();
		void print_list(Node *node);

		int size() { return length; }

		bool higher(string word1, string word2);
		bool lower(string word1, string word2);
		bool same(string word1, string word2);
};

