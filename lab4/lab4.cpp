#include <iostream>
#include <string>
#include <vector>
#include "Shows.h"
#include "Shows_TV.h"
#include "Shows_Movie.h"

using namespace std;



//////////////////////// Shows

// Shows CONSTRUCTORS
Shows::Shows(){
	title = "";
	description = "";
}
Shows::Shows(string t, string d){
	title = t;
	description = d;
}


// Shows SETTERS
void Shows::set_title(string t){
	title = t;
}
void Shows::set_description(string d){
	description = d;
}


// Shows GETTERS
string Shows::get_title(){
	return title;
}
string Shows::get_description(){
	return description;
}


// Shows VIRTUAL FUNCTION Play
void Shows::Play(){
	cout << title << " playing in a moment" << endl;
}


// Shows NON-VIRTUAL FUNCTION Details
void Shows::Details(){
	cout << "Details: " << endl;
	cout << "\t" << title << endl;
	cout << "\t" << description << endl;
}



//////////////////////// TV: Shows

TV::TV() {}


// SETTER
void TV::set_list(string l, int ep, int sn){	
	list[sn][ep] = { l }; 
}

// GETTERS
std::string TV::get_item(int sn, int ep){			// return list item (season, episode)
	return list[sn][ep];	
}
int TV::get_seasons(){							// return number of seasons
	int sn = 0;
	for (int i=0; i<(sizeof(list)/sizeof(list)); i++){
		sn++;
	}
	return sn;
}
int TV::get_episodes(int sn){					// return number of episodes in season
	int ep = 0;
	for (int i=0; i<(sizeof(list[sn])/sizeof(list[sn])); i++){
		ep++;
	}
	return ep;
}

// Play
void TV::Play(){
	int sn, ep;		// user input season and episode
	
	cout << "season: ";		// get season
	cin >> sn;
	cout << endl;

	cout << "episode: ";	// get episode
	cin >> ep;
	cout << endl << endl;

	cout << "now playing: " << get_item(sn, ep) << endl; 	// print item from list
}


// Details
void TV::Details(){
	cout << "Details: " << endl;
	cout << "\t" << get_title() << endl;
	//cout << "\t" << get_seasons() << " seasons" << endl;
	cout << "\t" << get_description() << endl;
}


//////////////////////// Movie: Shows

Movie::Movie(){ }

// SETTER
void Movie::set_credits(string c){
	credits = c;
}

// GETTER
string Movie::get_credits(){
	return credits;
}


// Play
void Movie::Play(){
	cout << "credits: " << credits << endl;
}