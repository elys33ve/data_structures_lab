#include <iostream>
#include <string>
#include "Shelf.h"
#include "Movie.h"

using namespace std;

int main(){
	Shelf shelf;
	string input;
	string title;
	string description;
	string credits;

	while (true){
		cout << endl;
		cout << "Press 1 to add a movie to the shelf." << endl;
		cout << "Press 2 remove a movie from the shelf." << endl;
		cout << "Press 3 see how many movies are currently on the shelf." << endl;
		cout << "Press 4 to quit." << endl;

		cin >> input;
		
		// add movie
		if (input == "1"){	
			// get new movie attributes to add
			cout << endl << "title of movie: ";
			cin >> title;
			cout << "description of movie: ";
			cin >> description;
			cout << "credits: ";
			cin >> credits;

			Movie* movie = new Movie;

			// set new movie attributes
			movie->set_title(title);
			movie->set_description(description);
			movie->set_credits(credits);

			shelf.add_movie(movie);
		}
		// remove movie
		else if (input == "2"){
			cout << endl << "title of movie to remove: ";
			cin >> title;

			try{			// if movie with title is on shelf
				shelf.find_movie(title);

				Movie* removed_movie = new Movie;
				removed_movie = shelf.remove_movie(title);

				// print removed movie attributes
				if (removed_movie->get_title() != " "){		// if existed in shelf
					cout << endl << "removed " << removed_movie->get_title() << ".\n";
				}
				else{										// if not found on shelf
					cout << endl << "movie with title \"" << title << "\" not found on shelf\n";
				}
			}
			catch (const char* msg){
				std::cout << "\nfailed to remove from shelf.\n";
				std::cerr << msg << std::endl;
			}
		}
		// get current number of movies on shelf
		else if (input == "3"){
			cout << endl << "there are currently " << shelf.num_movies << " items on shelf" << endl;
			cout << "available space: " << number_of_movies - shelf.num_movies << endl;
		}
		// quit
		else if (input == "4"){
			break;
		}

	}

	return 0;
}