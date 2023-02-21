#include <string>
#include "Movie.h"
#pragma once

const int number_of_movies = 3;		// global constant for number of movies

class Shelf{
	private:
		Movie* movies[number_of_movies];				// array to hold movies

	public:
		Shelf();
		
		int num_movies;					// current number of movies being held in array

		void shelf_full();					// test if shelf full
		void shelf_empty();					// test if shelf empty

		void add_movie(Movie* obj);				// add new movie to shelf
		int find_movie(std::string m);			// find index of movie in array
		Movie* remove_movie(std::string m);		// remove movie by title

};
