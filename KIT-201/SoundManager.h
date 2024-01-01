#pragma once
#include "SFML\Audio.hpp"
#include <string.h>

class SoundManager {

private:
	sf::Music music;

public:
	
	SoundManager();

	void setMusic(std::string music);
	void putMusicOnLoop(bool levelIsDone);

};