#include <string>
#pragma once


class Shelf{
	private:
		std::string movies[10];			// array to hold movies
		int num_movies;					// current number of movies being held in array

	public:
		Shelf();
		
		void add_movie(std::string m);
		void remove_movie(std::string m);
};
