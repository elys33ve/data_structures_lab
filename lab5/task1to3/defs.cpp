#include <iostream>
#include <string>
#include "Shelf.h"
#include "Movie.h"

using namespace std;

// default constructor
Shelf::Shelf(){
	num_movies = 0;
}




// add movies and update number of current total movies
void Shelf::add_movie(string m){

	num_movies += 1;
}

// remove movie and update number of current total movies
void Shelf::remove_movie(const Movies){
	for (int i=0; i<num_movies; i++){

	}
}


// SETTER
void Movie::set_credits(std::string c) {
	credits = c;
}

// GETTER
std::string Movie::get_credits() {
	return credits;
}

// Play
void Movie::Play() {
	std::cout << "credits: " << credits << std::endl;
}


// default constructor
Shelf::Shelf() {
	num_movies = 0;
}