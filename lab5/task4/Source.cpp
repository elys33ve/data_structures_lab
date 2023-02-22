#include "EntertainmentCollection.h"
#include "VideoGame.h"
#include <iostream>

EntertainmentCollection<VideoGame> shelf;
int main() {
	int input{ 0 };
	while (input != 4) {
		std::cout << "Press 1 to add a video game to the shelf" << std::endl;
		std::cout << "Press 2 to remove a video game from the shelf" << std::endl;
		std::cout << "Press 3 to see how many games are currently on the shelf" << std::endl;
		std::cout << "Press 4 to quit." << std::endl;
		std::cin >> input;
		
		if (input == 1) {
			std::string name;
			std::string desc;
			std::cout << "enter the name of the video game\n> ";
			std::cin.ignore();
			std::getline(std::cin, name);
			std::cout << "Please enter a description\n> ";
			std::cin.ignore();
			std::getline( std::cin, desc);
			VideoGame* game = new VideoGame(name, desc);
			shelf.addItem(game);
			
		}
		else if (input == 2) {
			VideoGame* game;	
			game = shelf.removeItem();
		}
		else if (input == 3) {
			std::cout << "The shelf has " << shelf.numItemsInShelf() << " games." << std::endl;
		}
		else if (input == 4) {
			return 0;
		}
	}
	return 0;
}
