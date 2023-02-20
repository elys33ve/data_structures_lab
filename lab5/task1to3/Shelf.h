#include <string>
#include "Movie.h"
#pragma once


class Shelf{
	private:
		Movie movies[10];			// array to hold movies
		int num_movies;					// current number of movies being held in array

	public:
		Shelf();
		
		void add_movie(const Movie& obj);
		void remove_movie(const Movie& obj);
};
