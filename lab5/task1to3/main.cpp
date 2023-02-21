#include <iostream>
#include "Shelf.h"

using namespace std;

int main(){
	Shelf shelf;
	string input;
	string title;
	string description;
	string credits;

	while (true){
		cout << "Press 1 to add a movie to the shelf." << endl;
		cout << "Press 2 remove a movie from the shelf." << endl;
		cout << "Press 3 see how many movies are currently on the shelf." << endl;
		cout << "Press 4 to quit." << endl;

		cin >> input;
		
		// add movie
		if (input == "1"){	
			// get new movie attributes to add
			cout << endl << endl << "title of movie: ";
			cin >> title;
			cout << endl << "description of movie: ";
			cin >> description;
			cout << endl << "credits: ";
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
			cout << endl << endl << "title of movie to remove: ";
			cin >> title;

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
		// get current number of movies on shelf
		else if (input == "3"){
			cout << endl << "there are currently " << shelf.num_movies << " on shelf" << endl;
		}
		// quit
		else if (input == "4"){
			break;
		}

	}

	return 0;
}