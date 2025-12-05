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

    void playMenuMusic();
    void playGameplayMusic();
    void playImpactSound();
    void playMenuUISound();

    void stopMusic();
    void setMusicVolume(float volume);
    void setSFXVolume(float volume);

private:
    sf::Music menuMusic;
    sf::Music gameplayMusic;

    sf::SoundBuffer impactBuffer;
    sf::SoundBuffer menuUIBuffer;

    sf::Sound impactSound;
    sf::Sound menuUISound;

    float musicVolume = 50.f;
    float sfxVolume = 70.f;

    const std::string audioPath = "resources/audio/";
};

    }
}