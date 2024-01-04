#pragma once
#include "SoundManager.h"
#include <iostream>
SoundManager::SoundManager() {
	this->setMusic("Sound/Music/Level2Music.ogg"); // default music for now
	this->music.setVolume(5.f);
	this->music.play();
	this->musicStatus = this->music.getStatus();
	this->music.setLoop(true);
	this->musicIsOnLoop = true;
	
}

void SoundManager::setMusic(std::string music) {

	if (!this->music.openFromFile(music)) {
		std::cout << "ERROR while setting Music" << std::endl;
	}

}


void SoundManager::updateMusic(GameState& currentState) {
	
	this->musicStatus = this->music.getStatus(); // update status everytime

	if (currentState == GameState::Play && this->musicStatus == sf::SoundSource::Playing) {
		if (this->musicIsOnLoop == false) {
			this->music.setLoop(true);
			musicIsOnLoop = true;
		}
			
	}

	else if (currentState == GameState::Play && this->musicStatus == sf::SoundSource::Stopped) {
		if (this->musicIsOnLoop == false) {
			this->music.setLoop(true);
			musicIsOnLoop = true;
			this->music.play();
		}
		
		else {
			this->music.play();
		}

	}


	else if (currentState == GameState::Play && this->musicStatus == sf::SoundSource::Paused) {
		if (this->musicIsOnLoop == false) {
			this->music.setLoop(true);
			musicIsOnLoop = true;
			this->music.play();
			this->music.setPlayingOffset(pauseOffset);
		}

		else {
			this->music.play();
			this->music.setPlayingOffset(pauseOffset);
		}

	}

	else if (currentState == GameState::Pause && this->musicStatus == sf::SoundSource::Playing) {
		if (this->musicIsOnLoop == false) {
			this->pauseOffset = this->music.getPlayingOffset();
			this->music.pause();
			
		}

		else {
			this->music.setLoop(false);
			this->musicIsOnLoop = false;
			this->pauseOffset = this->music.getPlayingOffset();
			this->music.pause();
		}

	}

	else if (currentState == GameState::Pause && this->musicStatus == sf::SoundSource::Stopped) {
		if (this->musicIsOnLoop == false) {
			this->music.stop();

		}

		else {
			this->music.setLoop(false);
			this->musicIsOnLoop = false;
			this->music.stop();
		}

	}

	else if (currentState == GameState::Pause && this->musicStatus == sf::SoundSource::Paused) {
		if (this->musicIsOnLoop == false) {
			this->pauseOffset = this->music.getPlayingOffset();
			this->music.pause();

		}

		else {
			this->music.setLoop(false);
			this->musicIsOnLoop = false;
			this->pauseOffset = this->music.getPlayingOffset();
			this->music.pause();
		}

	}
}

void SoundManager::updateSoundEffect(GameState& currentState,Player& player) {

	

	if (currentState == GameState::Play) {
		
		if (player.getCanJump()) {
			if (!this->buffer.loadFromFile("Sound/SoundEffects/jump.wav"))
				std::cout << "Error while setting music" << std::endl;
			this->soundEffect.setBuffer(buffer);
			this->soundEffect.play();
		}
		if (player.getCanShoot()) {
			if (!this->buffer.loadFromFile("Sound/SoundEffects/shoot.wav"))
				std::cout << "Error while setting music" << std::endl;
			this->soundEffect.setBuffer(buffer);
			this->soundEffect.play();
		}

	}

	else if (currentState == GameState::Pause) {
		
		if (!this->buffer.loadFromFile("Sound/SoundEffects/pause.wav"))
			std::cout << "Error while setting music" << std::endl;
		this->soundEffect.setBuffer(buffer);
		this->soundEffect.play();

	}

	

	
}

/*void SoundManager::playSoundEffect(const SoundEffectsLibrary& selectedSoundEffect, GameState& currentState, Player& player) {

	switch (selectedSoundEffect) {

		case SoundEffectsLibrary::SHOOT:

			if (!this->buffer.loadFromFile("Sound/SoundEffects/shoot.wav"))
				std::cout << "Error while setting music" << std::endl;
			break;
		
		case SoundEffectsLibrary::JUMP:

			if (!this->buffer.loadFromFile("Sound/SoundEffects/jump.wav"))
				std::cout << "Error while setting music" << std::endl;
			break;

		case SoundEffectsLibrary::FALL:

			if (!this->buffer.loadFromFile("Sound/SoundEffects/fall.wav"))
				std::cout << "Error while setting music" << std::endl;
			break;
	}

	this->soundEffect.setBuffer(buffer);
	this->soundEffect.play();
}
*/
/*SoundManager& SoundManager::getSoundManager() {
	return this;
}*/
/*void SoundManager::playSoundEffect(const SoundEffectsLibrary& selectedSoundEffect, SoundManager& soundManager) {
	soundManager.setSoundEffect(selectedSoundEffect);
	soundManager.soundEffect.setBuffer(soundManager)
}
*/