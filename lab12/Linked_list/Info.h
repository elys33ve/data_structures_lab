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