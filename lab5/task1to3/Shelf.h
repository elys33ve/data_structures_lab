#include <string>
#include "Movie.h"
#pragma once

const int number_of_movies = 10;		// global constant for number of movies

class Shelf{
	private:
		Movie* movies[number_of_movies];				// array to hold movies

	public:
		Shelf();
		
		int num_movies;					// current number of movies being held in array

		void add_movie(Movie* obj);				// add new movie to shelf
		Movie* remove_movie(std::string m);		// remove movie by title
};
