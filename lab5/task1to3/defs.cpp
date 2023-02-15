#include <string>
#include "Shelf.h"

using namespace std;

// default constructor
Shelf::Shelf(){
	num_movies = 0;
}



// add movies and update number of current total movies
void Shelf::add_movie(string m){
	// --- ENSURE ARRAY NOT FULL --- //	
	movies[num_movies] = m;
	num_movies += 1;
}

// remove movie and update number of current total movies
void Shelf::remove_movie(string m){
	for (int i=0; i<num_movies; i++){
		if (movies[i] == m){				// --- remove by str or index? ---
			// --- REMOVE AND CHANGE ARRAY ORDER --- //
			movies[i] = "";					
			num_movies -= 1;
		}
	}
}

