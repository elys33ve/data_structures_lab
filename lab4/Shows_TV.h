#include <string>
#include "Shows.h"

#pragma once

// derived class for tv shows
class TV: public Shows{
	private:
		std::string list[10][10];		// 2D array for seasons and episodes
		
	public:
		TV();

		void set_list(std::string l, int ep, int sn);

		std::string get_item(int sn, int ep);		// return list item (season, episode)
		int get_seasons();							// return number of seasons
		int get_episodes(int sn);					// return number of episodes in season
		
		void Play();
		void Details();
};