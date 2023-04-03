#include <string>

#pragma once


// class for holding data
class Data {
	public:
		std::string word;		// word / key
		int freq;				// word frequency

		Data () { }
		Data (std::string w, int f) {
			word = w;
			freq = f;
		}
};