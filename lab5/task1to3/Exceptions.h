#include <string>
#include "Shelf.h"
#include "Movie.h"

#pragma once


class FullShelf{
	public:
		FullShelf() { }
		
		void full(int num_movies);
};


class EmptyShelf{
	public:
		EmptyShelf() { }

		std::string empty(int num_movies);
		std::string dne(bool exist);

};