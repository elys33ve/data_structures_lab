#include <iostream>
#include <string>
#include "Shelf.h"
#include "Movie.h"




// --------------------- Shelf Class

// default constructor
Shelf::Shelf(){
	num_movies = 0;
}

// add movies and update number of current total movies
void Shelf::add_movie(Movie obj){
	movies[num_movies] = obj;
	num_movies += 1;
}

// remove movie and update number of current total movies
void Shelf::remove_movie(Movie obj){
	std::string title = obj.get_title();
	std::string credits = obj.get_credits();

	for (int i=0; i<num_movies; i++){
		if ((title == movies[i].get_title()) && (credits == movies[i].get_credits())){
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
	credits = " ";
};
Movie::Movie(std::string t){
	title = t;
	description = " ";
	credits = " ";
}
Movie::Movie(std::string t, std::string d) {
	title = t;
	description = d;
	credits = " ";
};

// Play
void Movie::Play() {
	std::cout << "Playing: " << title << std::endl;
	std::cout << "credits: " << credits << std::endl;
}
