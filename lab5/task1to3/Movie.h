#include <string>

class Movie{
private:
	std::string title;
	std::string description;
	std::string credits;

public:
	Movie();
	Movie(std::string t);
	Movie(std::string t, std::string d);

	void set_title(std::string t) { title = t; };
	void set_description(std::string d) { description = d; };
	void set_credits(std::string c) { credits = c; };

	std::string get_title() { return title; };
	std::string get_description() { return description; };
	std::string get_credits() { return credits; };

	void Play();
};