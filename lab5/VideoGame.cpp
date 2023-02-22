#include "VideoGame.h"
#include <iostream>
VideoGame::VideoGame() {
	this->name = "";
	this->Description = "";
}

VideoGame::VideoGame(std::string name) {
	this->name = name;
	this->Description = "";
}

VideoGame::VideoGame(std::string name, std::string desc) {
	this->name = name;
	this->Description = desc;
}

std::string VideoGame::getDesc() {
	return this->Description;
}

void VideoGame::setDesc(std::string desc) {
	this->Description = desc;
}

std::string VideoGame::getName() {
	return this->name;
}

void VideoGame::setName(std::string name) {
	this->name = name;
}

void VideoGame::Play() {
	std::cout << "Now playing " << name << std::endl << "Summary: " << Description << std::endl;
}