#include <string>
#include "Shows.h"

#pragma once

// derived class for movies
class Movie: public Shows{
	private:
		std::string credits;

	public:
		Movie();

		void set_credits(std::string c);

		std::string get_credits();

		void Play();
};
