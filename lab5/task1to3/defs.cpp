#include <iostream>
#include <string>
#include "Shelf.h"
#include "Movie.h"

using namespace std;




// --------------------- Shelf Class

// default constructor
Shelf::Shelf(){
	num_movies = 0;
}


// add movies and update number of current total movies
void Shelf::add_movie(const Movie& obj){
	movies[num_movies] = obj;
	num_movies += 1;
}

// remove movie and update number of current total movies
void Shelf::remove_movie(const Movie& obj){
	for (int i=0; i<num_movies; i++){			// (i need to fix this)
		if (obj == movies[i]){				// --- compare classes? ---
			for (int j=i; j<num_movies-1; i++){
				movies[i] = movies[i+1];			// --- adjsut list after remove ---
			}
		}
	}
	num_movies -= 1;
}




// --------------------- Movie Class

Movie::Movie() {
	title = " ";
	description = " ";
};
Movie::Movie(std::string t, std::string d) {
	title = t;
	description = d;
};



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
