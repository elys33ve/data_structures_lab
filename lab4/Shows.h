#include <string>


#pragma once

/* 
class to abstractly model shows
*/


// base class for shows
class Shows{
	private:
		std::string title;
		std::string description;

	public:
		Shows();							    // defult constructor
		Shows(std::string t, std::string d);	// overload constructor

		void set_title(std::string t);
		void set_description(std::string d);

		std::string get_title();
		std::string get_description();

		virtual void Play();		// virtual function Play - for movies: credits, for shows: episode and season
		void Details();				// non virtual function Details - print attributes: title, description, (number of seasons if show)

};
