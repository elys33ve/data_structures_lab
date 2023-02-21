#include <iostream>
#include <string>
#include <exception>
#include "Shelf.h"
#include "Movie.h"
#include "Exceptions.h"


// --------------------- Shelf Class

// default constructor
Shelf::Shelf(){
	num_movies = 0;
}


// test if shelf is full -- throw excepttion if true
void Shelf::shelf_full(){
	if (num_movies >= number_of_movies){
		throw "--shelf full--";
	}
}
// test if shelf is empty -- throw excepttion if true
void Shelf::shelf_empty(){
	if (num_movies == 0){
		throw "--shelf empty--";
	}
}


// add movies and update number of current total movies
void Shelf::add_movie(Movie* obj){
	try{
		shelf_full();			// test if shelf is full

		movies[num_movies] = obj;
		num_movies += 1;
		std::cout << "\nadded to shelf." << std::endl;
	}
	catch (const char* msg){
		std::cout << "\nfailed to add to shelf.\n";
		std::cerr << msg << std::endl;
	}
}

// find movie in array -- and throw exception if not found
int Shelf::find_movie(std::string m){
	for (int i=0; i<num_movies; i++){
		if (m == movies[i]->get_title()){			// if movie title found on shelf	
			return i;
		}
	}

	throw "--does not exist on shelf--";
}

// remove movie and update number of current total movies
Movie* Shelf::remove_movie(std::string m){
	try{
		shelf_empty();				// test if shelf is empty

		int i = find_movie(m);		// find index of movie in array
		Movie* movie = movies[i];

		for (i; i<num_movies-1; i++){
			movies[i] = movies[i+1];				// remove movie and replace following to reorder
		}
		num_movies -= 1;
		return movie;
	}
	catch (const char* msg){
		std::cout << "\nfailed to remove from shelf.\n";
		std::cerr << msg << std::endl;
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
void Movie::Play(){
	std::cout << "Playing: " << title << std::endl;
	std::cout << "credits: " << credits << std::endl;
}