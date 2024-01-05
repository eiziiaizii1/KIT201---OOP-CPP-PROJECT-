#pragma once

#include "SFML\Audio.hpp"
#include "StateManager.h"
#include "Entity.h"
#include <string>

/**
 * @brief Enum representing different sound effects.
 */
enum class SoundEffectsLibrary {
    JUMP, /**< Jump sound effect. */
    FALL, /**< Fall sound effect. */
    SHOOT, /**< Shoot sound effect. */
    GETHIT /**< Get hit sound effect. */
};

/**
 * @brief Manages game sounds and music.
 */
class SoundManager {
private:
    sf::Music music; /**< Background music. */
    sf::SoundSource::Status musicStatus; /**< Status of the background music (playing or not). */
    bool musicIsOnLoop; /**< Indicates if the music is on a loop. */
    sf::Time pauseOffset; /**< Used to continue the song after it's been paused. */

    sf::SoundBuffer bufferJump; /**< Sound buffer for jump sound effect. */
    sf::SoundBuffer bufferShoot; /**< Sound buffer for shoot sound effect. */
    sf::SoundBuffer bufferPause; /**< Sound buffer for pause sound effect. */
    sf::SoundBuffer bufferGetHit; /**< Sound buffer for get hit sound effect. */
    sf::Sound soundEffect; /**< Sound effect player. */

    /**
     * @brief Checks if any entity in the vector is hit.
     *
     * @param entityVector Vector of entities to check for hits.
     * @return true if any entity is hit, false otherwise.
     */
    bool checkAllIfHit(std::vector<std::unique_ptr<Entity>>& entityVector);

public:
    /**
     * @brief Constructs a SoundManager object.
     */
    SoundManager();

    /**
     * @brief Sets the background music.
     *
     * @param music Path to the music file.
     */
    void setMusic(std::string music);

    /**
     * @brief Updates the background music based on the game state.
     *
     * @param currentState The current game state.
     */
    void updateMusic(GameState& currentState);

    /**
     * @brief Updates the sound effects based on the game state manager.
     *
     * @param stateManager The game state manager.
     */
    void updateSoundEffect(StateManager& stateManager);
};
