#pragma once
#include "SoundManager.h"
#include <iostream>
SoundManager::SoundManager() {
	this->setMusic("Sound/Music/Level1Music.ogg"); // default music for now
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