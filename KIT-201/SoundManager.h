#pragma once
#include "SFML\Audio.hpp"
#include "StateManager.h"
#include <string.h>

enum class SoundEffectsLibrary {
	JUMP,
	FALL,
	SHOOT
};

class SoundManager {

private:



	sf::Music music;
	sf::SoundSource::Status musicStatus; // checks if it is playing or nor
	bool musicIsOnLoop; // checks if it is on loop
	sf::Time pauseOffset; //used to continue the song after it got paused
	
	sf::SoundBuffer bufferJump;
	sf::SoundBuffer bufferShoot;
	sf::SoundBuffer bufferPause;
	sf::Sound soundEffect;
	//void setSoundEffect(const SoundEffectsLibrary& selectedSoundEffect);
	
	

public:
	
	SoundManager();
	void setMusic(std::string music);
	void updateMusic(GameState& currentState);
	void updateSoundEffect(StateManager& stateManager);
	//static void playSoundEffect(const SoundEffectsLibrary& selectedSoundEffect,SoundManager& soundManager);
	//SoundManager& getSoundManager();
	

};