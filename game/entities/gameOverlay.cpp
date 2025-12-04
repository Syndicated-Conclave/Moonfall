#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <game/entities/gameOverlay.hpp>
#include <game/main.cpp>
#include <iostream>

#define WIDTH 1600
#define HEIGHT 900



namespace Game
{
    namespace Entities
    {       
        sf::RenderWindow window(sf::VideoMode({ 1600, 900 }), "Moonfall");
        bool fullScreen;
        
        void UI::input(sf::RenderWindow &window)
        {
            sf::Event e;
            while(window.pollEvent(e))
            {
                if(e.type == sf::Event::Closed)
                window.close();
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::F))
                {
                if(fullScreen)
                window.create(sf::VideoMode::getFullscreenModes()[0], "Moonfall");
                if(!fullScreen)
                window.create(sf::VideoMode(WIDTH, HEIGHT), "Moonfall");
                }
                fullScreen = !fullScreen;
            }
        };

        // Adding custom font and styling for counter text
        int CollectedPoints;
        int RequiredPoints;
        
        sf::Text counterText("Star Dust Collected: " + CollectedPoints + " / " + RequiredPoints, font, 28);
        counterText.setFillColor(sf::Color(255, 255, 224));
        counterText.setPosition({300.f, 30.f});

        // Creating boxes for timer text
        sf::RectangleShape counterBlock({400.f, 65.f});
        counterBlock.setPosition(100.f, 20.f);
        sf::RectangleShape counterBox({180.f, 35.f});
        counterBox.setPosition(380.f, 33.f); 
        
        counterBlock.setFillColor(sf::Color(11, 11, 24));
        counterBox.setFillColor(sf::Color(8, 10, 43));
        
        // Adding custom font and styling for countdown text
        sf::Font font;
        font.loadFromFile("resources/HUSKYSTA.otf");
        sf::Text timerText("Time Till Sunrise: ", font, 28);
        timerText.setFillColor(sf::Color(255, 255, 224));
        timerText.setPosition({1200.f, 30.f});

        // Creating boxes for timer text
        sf::RectangleShape timerBlock({400.f, 65.f});
        timerBlock.setPosition(600.f, 20.f);
        sf::RectangleShape timerBox({1200.f, 35.f});
        timerBox.setPosition(1280.f, 33.f); 
        
        timerBlock.setFillColor(sf::Color(11, 11, 24));
        timerBox.setFillColor(sf::Color(8, 10, 43));

        

        //timer functionality
        sf::Clock timer;
        /*Setting game time to two minutes*/
        int gameTime = 120;
        sf::Text TimerText(" : ", font, 28);
        TimerText.setFillColor(sf::Color(255, 255, 224));
        TimerText.setPosition(890.f, 35.f);
        
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
            if (event.type == sf::Event::Closed)
            {
                
                window.close();
            }
            float timeLeft = countdown.getElapsedTime().asSeconds();
            float countdowntext = gameTime - timeLeft;
            if(countdowntext < 0) countdowntext = 0;
            CountdownText.setString(std::to_string((int)countdowntext));

            CollectedPoints = Game::Components::collectedPoints;
            RequiredPoints = Game::Components::requiredPoints;
            
            }

            window.clear();           
            window.draw(timerBlock);
            window.draw(timerBox);
            window.draw(timerText);
            window.draw(TimerText);
            window.draw(counterBlock);
            window.draw(counterBox);
            window.draw(counterText);           
            window.display();
        }

            // Game::Entities::UI *ui;
        
        // //while (Game::State gameState.Playing)
        // //{
        //     void UI::init(sf::RenderWindow &window)
        //     {
        //         Game::Entities::Timer timer;
        //         Game::Entities::StarDustCounter starDustCounter;

                
        //     };
            
        // //update method
        // void UI::update(sf::RenderWindow &window)
        // {                
        //     while (window.isOpen())
        //     {
                
        //         input();
        //         render();
        //         Game::Entities::Timer::init();
        //         Game::Entities::StarDustCounter::init();
                
                
        //         sf::Event event;
        //         while (window.pollEvent(event))
        //         {
        //             if (event.type == sf::Event::Closed)
        //             {
        //                 window.close();
        //             }
        //         }
        //     }
        // };

        //render method
        // void UI::render(sf::RenderWindow &window) //BUG NEEDS FIX
        // {
        //     sf::Event event;

        //     while(window.pollEvent(event))
        //     {
        //         if(event.type == sf::Event::Closed)
        //         {
        //             window.close();
        //         }

        //     };

        //     window.clear();
        //     window.draw(Game::Entities::Timer::timerText);
        //     window.draw(Game::Entities::StarDustCounter::starDustCounterText);               
        //     window.display();
            
        // };

        // void Timer::init()
        // {
        //     //timer
        //     sf::Clock countdown;
        //     /*Setting game time to two minutes*/
        //     int gameTime = 120;
        //     float timeTaken = countdown.getElapsedTime().asSeconds();
        //     int timeLeft = gameTime - countdown.getElapsedTime().asSeconds();
            
        //     //font object
        //     sf::Font font;
        //     font.loadFromFile("resources/HUSKYSTA.otf");

        //     //points
        //     int Game::Entities::StarDustCounter::points = 0;
            
        //     //timer variables
        //     timer.setFillColor(sf::Color(255, 255, 225));
        //     timer.setPosition({20.f, 10.f});
        //     timer.setFont(font);
        //     timer.setCharacterSize(48);
            
        //     timer.setString("Time Left: " + timeLeft);
        // }
        
        // void StarDustCounter::init()
        // {
        //     //font object
        //     sf::Font font;
        //     font.loadFromFile("resources/HUSKYSTA.otf");
            
        //     //star dust counter variables
        //     starDustCounter.setFillColor(sf::Color(255, 255, 225));
        //     starDustCounter.setPosition({1500.f, 10.f});
        //     starDustCounter.setFont(font);
        //     starDustCounter.setCharacterSize(48);
        //     starDustCounter.setString("Star Dust Collected: " + Game::Entities::StarDustCounter::points);
        // }

        //}
    }  
}