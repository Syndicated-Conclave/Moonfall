#pragma once
#include <SFML/Audio.hpp>
#include <string>

// namespace for all game specific things
namespace Game
{
    // namespace for all components
    namespace Components
    {

class AudioManager {
public:
    AudioManager();
    ~AudioManager();

    static void playMenuMusic();
    static void playGameplayMusic();
    static void playImpactSound();
    static void playMenuUISound();
    static void playTwinkleSound();

    static void stopMusic();
    static void setMusicVolume(float volume);
    static void setSFXVolume(float volume);

private:
    // Music
    static sf::Music menuMusic;
    static sf::Music gameplayMusic;

    // Buffers for sound effects
    static sf::SoundBuffer impactBuffer;
    static sf::SoundBuffer menuUIBuffer;
    static sf::SoundBuffer twinkleBuffer;

    // Sound effects
    static sf::Sound impactSound;
    static sf::Sound menuUISound;
    static sf::Sound twinkleSound;

    static float musicVolume;
    static float sfxVolume;

    static const std::string audioPath;
};

    }
} 
