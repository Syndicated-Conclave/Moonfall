#include "AudioManager.hpp"
#include <iostream>

// namespace for all game specific things
namespace Game
{
    // namespace for all components
    namespace Components
    {

AudioManager::AudioManager() {
    // Load music
    if (!menuMusic.openFromFile(audioPath + "menu_music.mp3")) {
        std::cerr << "Error: could not load menu_music.mp3\n";
    }
    if (!gameplayMusic.openFromFile(audioPath + "level1_music.mp3")) {
        std::cerr << "Error: could not load level1_music.mp3\n";
    }

    // Load sound effects
    if (!impactBuffer.loadFromFile(audioPath + "impact_soundEffect.mp3")) {
        std::cerr << "Error: could not load impact_soundEffect.mp3\n";
    }
    if (!menuUIBuffer.loadFromFile(audioPath + "menuUI_soundEffect.mp3")) {
        std::cerr << "Error: could not load menuUI_soundEffect.mp3\n";
    }

    impactSound.setBuffer(impactBuffer);
    menuUISound.setBuffer(menuUIBuffer);

    menuMusic.setVolume(musicVolume);
    gameplayMusic.setVolume(musicVolume);
    impactSound.setVolume(sfxVolume);
    menuUISound.setVolume(sfxVolume);
}

AudioManager::~AudioManager() {
    stopMusic();
}

void AudioManager::playMenuMusic() {
    stopMusic();
    menuMusic.setLoop(true);
    menuMusic.play();
}

void AudioManager::playGameplayMusic() {
    stopMusic();
    gameplayMusic.setLoop(true);
    gameplayMusic.play();
}

void AudioManager::playImpactSound() {
    impactSound.play();
}

void AudioManager::playMenuUISound() {
    menuUISound.play();
}

void AudioManager::stopMusic() {
    menuMusic.stop();
    gameplayMusic.stop();
}

void AudioManager::setMusicVolume(float volume) {
    musicVolume = volume;
    menuMusic.setVolume(volume);
    gameplayMusic.setVolume(volume);
}

void AudioManager::setSFXVolume(float volume) {
    sfxVolume = volume;
    impactSound.setVolume(volume);
    menuUISound.setVolume(volume);
}

    }
}