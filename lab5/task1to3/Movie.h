#include <string>

class Movie{
private:
	std::string title;
	std::string description;
	std::string credits;

public:
	Movie();
	Movie(std::string t, std::string d);

	void set_credits(std::string c);

	std::string get_credits();

	void Play();
};