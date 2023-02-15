// SETTER
void Movie::set_credits(std::string c) {
	credits = c;
}

// GETTER
std::string Movie::get_credits() {
	return credits;
}

// Play
void Movie::Play() {
	std::cout << "credits: " << credits << std::endl;
}


// default constructor
Shelf::Shelf() {
	num_movies = 0;
}
