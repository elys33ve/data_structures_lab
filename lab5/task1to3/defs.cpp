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
void Shelf::add_movie(Movie* obj){
	if (num_movies >= number_of_movies){
		std::cout << "movie could not be added, shelf is full.\n";	// if movies array is full
	}
	else{
		movies[num_movies] = obj;
		num_movies += 1;
	}
}

// remove movie and update number of current total movies
Movie* Shelf::remove_movie(std::string m){
	Movie* movie;
	bool exist = false;

	for (int i=0; i<num_movies; i++){
		if (m == movies[i]->get_title()){			// if movie title found on shelf	
			exist = true;
			movie = movies[i];
			for (int j=i; j<num_movies-1; i++){
				movies[j] = movies[j+1];				// remove movie and replace following to reorder
			}
			num_movies -= 1;
			break;
		}
	}

	if (exist == false){						// if movie not on shelf
		std::cout << "movie with given title does not exist on shelf.\n";
		return movie;	// empty movie
	}
	else{
		return movie;	// removed movie
	}
}




// --------------------- Movie Class

Movie::Movie(){
	title = " ";
	description = " ";
	credits = " ";
}
Movie::Movie(std::string t){
	title = t;
	description = " ";
	credits = " ";
}
Movie::Movie(std::string t, std::string d){
	title = t;
	description = d;
	credits = " ";
}
Movie::Movie(std::string t, std::string d, std::string c){
	title = t;
	description = d;
	credits = c;
}


// Play
void Movie::Play() {
	std::cout << "Playing: " << title << std::endl;
	std::cout << "credits: " << credits << std::endl;
}
