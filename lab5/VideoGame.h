#pragma once
#include <string>
class VideoGame
{
private:
	std::string name;
	std::string Description;
public:
	VideoGame();
	VideoGame(std::string name);
	VideoGame(std::string name, std::string rating);
	std::string getDesc();
	void setDesc(std::string rating);
	std::string getName();
	void setName(std::string name);
	void Play();
};
