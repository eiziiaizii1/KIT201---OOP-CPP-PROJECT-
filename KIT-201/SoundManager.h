#pragma once
#include "SFML\Audio.hpp"
#include "StateManager.h"
#include <string.h>

class SoundManager {

private:
	sf::Music music;
	sf::SoundSource::Status musicStatus; // checks if it is playing or nor
	bool musicIsOnLoop; // checks if it is on loop
	sf::Time pauseOffset; //used to continue the song after it got paused

public:
	
	SoundManager();

	void setMusic(std::string music);
	void putMusicOnLoop(GameState& currentState);
	void updateMusic(GameState& currentState);

};