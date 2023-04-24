#include <iostream>
#pragma once

using namespace std;

// student info
class Info {
	public:
		string firstname;
		string lastname;
		int id_number;

		Info () { }
		Info (string f, string l, int i) { firstname = f; lastname = l; id_number = i; }
};


class Node {
	public:
		Info* data;
		Node* prev;
		Node* next;

		Node() { data = nullptr; prev = next = nullptr; }
		Node(Info *d) { data = d; prev = next = nullptr; }
};


class List {
	private:
		int location;
		int length;

		Node *head;

	public:
		List();
		~List();

		void addItem(Info *item);

		bool isEmpty();

		void print_list();

		int size() { return length; }
};

