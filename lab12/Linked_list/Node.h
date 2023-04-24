#pragma once

#include <iostream>
#include <string>
#include "Info.h"

using namespace std;

class Node {
	public:
		Info* data;
		Node* prev;
		Node* next;

		Node() { data = nullptr; prev = next = nullptr; }
		Node(Info *d) { data = d; prev = next = nullptr; }
};
