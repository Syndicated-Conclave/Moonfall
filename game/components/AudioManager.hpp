#pragma once
#include <SFML/Audio.hpp>
#include <string>

// namespace for all game specific things
namespace Game
{
    // namespace for all components
    namespace Components
    {

        class AudioManager
        {
        public:
            AudioManager();
            ~AudioManager();

            void playMenuMusic();
            void playGameplayMusic();
            void playImpactSound();
            void playMenuUISound();
            void playTwinkleSound();

            void stopMusic();
            void setMusicVolume(float volume);
            void setSFXVolume(float volume);

        private:
            // Music
            sf::Music menuMusic;
            sf::Music gameplayMusic;

            // Buffers for sound effects
            sf::SoundBuffer impactBuffer;
            sf::SoundBuffer menuUIBuffer;
            sf::SoundBuffer twinkleBuffer;

            // Sound effects
            sf::Sound impactSound;
            sf::Sound menuUISound;
            sf::Sound twinkleSound;

            float musicVolume = 50.f;
            float sfxVolume = 70.f;

            const std::string audioPath = "resources/audio/";
        };

    }
}
