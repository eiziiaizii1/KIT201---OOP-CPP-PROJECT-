#include "SoundManager.h"
#include <iostream>
SoundManager::SoundManager() {
	this->setMusic("Sound/Music/Level1Music.ogg"); // default music for now
	this->music.play();
	this->music.setVolume(5.f);
	bool levelIsDone = false; //false for now
	this->putMusicOnLoop(levelIsDone);
	
}

void SoundManager::setMusic(std::string music) {

	if (!this->music.openFromFile(music)) {
		std::cout << "ERROR while setting Music" << std::endl;
	}

}

void SoundManager::putMusicOnLoop(bool levelIsDone) { 
	this->music.setLoop(!levelIsDone);
}