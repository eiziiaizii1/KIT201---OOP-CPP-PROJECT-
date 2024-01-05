#pragma once
#include "SFML\Audio.hpp"
#include "StateManager.h"
#include "Entity.h"
#include <string.h>

/**
 * @brief Enumeration defining sound effects available in the library.
 */
enum class SoundEffectsLibrary {
	JUMP, /**< Jump sound effect. */
	FALL, /**< Fall sound effect. */
	SHOOT, /**< Shoot sound effect. */
	GETHIT /**< Get hit sound effect. */
};

/**
 * @brief Manages the audio playback for the game.
 */
class SoundManager {

private:
	sf::Music music; /**< Music track to play. */
	sf::SoundSource::Status musicStatus; /**< Status of the music (playing or not). */
	bool musicIsOnLoop; /**< Indicates if music is on loop. */
	sf::Time pauseOffset; /**< Used to continue the song after it was paused. */

	sf::SoundBuffer bufferJump; /**< Sound buffer for the jump sound effect. */
	sf::SoundBuffer bufferShoot; /**< Sound buffer for the shoot sound effect. */
	sf::SoundBuffer bufferPause; /**< Sound buffer for the pause sound effect. */
	sf::SoundBuffer bufferGetHit; /**< Sound buffer for the get hit sound effect. */
	sf::Sound soundEffect; /**< Sound object for playing sound effects. */

	/**
	 * @brief Checks if any entity in the vector was hit.
	 * @param entityVector The vector of entities to check.
	 * @return true if any entity was hit, false otherwise.
	 */
	bool checkAllIfHit(std::vector<std::unique_ptr<Entity>>& entityVector);

public:
	/**
	 * @brief Default constructor for SoundManager.
	 */
	SoundManager();

	/**
	 * @brief Sets the music track.
	 * @param music Path to the music file.
	 */
	void setMusic(std::string music);

	/**
	 * @brief Updates the music based on the current game state.
	 * @param currentState The current game state.
	 */
	void updateMusic(GameState& currentState);

	/**
	 * @brief Updates the sound effects based on the game state manager.
	 * @param stateManager The state manager controlling the game states.
	 */
	void updateSoundEffect(StateManager& stateManager);
};
