#include <string>
#include "Movie.h"
#pragma once


class Shelf{
	private:
		Movie movies[10];				// array to hold movies

	public:
		Shelf();
		
		int num_movies;					// current number of movies being held in array

		void add_movie(Movie obj);			// add new movie to shelf
		void remove_movie(std::string m);	// remove movie by title
};
