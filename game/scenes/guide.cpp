#include "guide.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>


namespace Game
{
    namespace Scenes
    {
        void Guide::instruct(sf::RenderWindow& window)
        {
            // Adding custom font and styling for title
            font.loadFromFile("resources/HUSKYSTA.otf");
            sf::Text localTitle("How to play Moonfall", font, 88);
            title = localTitle;
            title.setFillColor(sf::Color(255, 255, 224));
            title.setPosition({ 350.f, 50.f });

            // Creating gradient background colour
            sf::VertexArray localSky(sf::Quads, 4);
            sky = localSky;
            sky[0].position = sf::Vector2f(0, 0);
            sky[1].position = sf::Vector2f(window.getSize().x, 0);
            sky[2].position = sf::Vector2f(window.getSize().x, window.getSize().y);
            sky[3].position = sf::Vector2f(0, window.getSize().y);
            sf::Color deep(7, 7, 41);
            sf::Color light(24, 66, 75);
            sky[0].color = deep;
            sky[1].color = deep;
            sky[3].color = light;
            sky[2].color = light;

            sf::ConvexShape localStar;
            starOne = localStar;
            starOne.setPointCount(10);
            starOne.setPoint(0, sf::Vector2f(8, -2));
            starOne.setPoint(1, sf::Vector2f(10, 3));
            starOne.setPoint(2, sf::Vector2f(15, 3));
            starOne.setPoint(3, sf::Vector2f(11, 6));
            starOne.setPoint(4, sf::Vector2f(12, 11));
            starOne.setPoint(5, sf::Vector2f(8, 8));
            starOne.setPoint(6, sf::Vector2f(4, 11));
            starOne.setPoint(7, sf::Vector2f(5, 6));
            starOne.setPoint(8, sf::Vector2f(1, 3));
            starOne.setPoint(9, sf::Vector2f(6, 3));
            starOne.setFillColor(sf::Color(255, 253, 208));
            starOne.setPosition(337,380);

            sf::ConvexShape localStarTwo;
            starTwo = localStarTwo;
            starTwo.setPointCount(10);
            starTwo.setPoint(0, sf::Vector2f(8, -2));
            starTwo.setPoint(1, sf::Vector2f(10, 3));
            starTwo.setPoint(2, sf::Vector2f(15, 3));
            starTwo.setPoint(3, sf::Vector2f(11, 6));
            starTwo.setPoint(4, sf::Vector2f(12, 11));
            starTwo.setPoint(5, sf::Vector2f(8, 8));
            starTwo.setPoint(6, sf::Vector2f(4, 11));
            starTwo.setPoint(7, sf::Vector2f(5, 6));
            starTwo.setPoint(8, sf::Vector2f(1, 3));
            starTwo.setPoint(9, sf::Vector2f(6, 3));
            starTwo.setFillColor(sf::Color(255, 253, 208));
            starTwo.setPosition(350, 410);

            sf::ConvexShape localStarThree;
            starThree = localStarThree;
            starThree.setPointCount(10);
            starThree.setPoint(0, sf::Vector2f(8, -2));
            starThree.setPoint(1, sf::Vector2f(10, 3));
            starThree.setPoint(2, sf::Vector2f(15, 3));
            starThree.setPoint(3, sf::Vector2f(11, 6));
            starThree.setPoint(4, sf::Vector2f(12, 11));
            starThree.setPoint(5, sf::Vector2f(8, 8));
            starThree.setPoint(6, sf::Vector2f(4, 11));
            starThree.setPoint(7, sf::Vector2f(5, 6));
            starThree.setPoint(8, sf::Vector2f(1, 3));
            starThree.setPoint(9, sf::Vector2f(6, 3));
            starThree.setFillColor(sf::Color(255, 253, 208));
            starThree.setPosition(377, 420);

            //Making sparkle shape

            sf::ConvexShape localSparkleOne;
            sparkleOne = localSparkleOne;
            sparkleOne.setPointCount(8);
            sparkleOne.setPoint(0, sf::Vector2f(40, 70));
            sparkleOne.setPoint(1, sf::Vector2f(45, 60));
            sparkleOne.setPoint(2, sf::Vector2f(55, 55));
            sparkleOne.setPoint(3, sf::Vector2f(45, 50));
            sparkleOne.setPoint(4, sf::Vector2f(40, 30));
            sparkleOne.setPoint(5, sf::Vector2f(35, 50));
            sparkleOne.setPoint(6, sf::Vector2f(25, 55));
            sparkleOne.setPoint(7, sf::Vector2f(35, 60));
            sparkleOne.setFillColor(sf::Color(255, 253, 208));
            sparkleOne.setPosition(250, 50);

            sf::ConvexShape localSparkleTwo;
            sparkleTwo = localSparkleTwo;
            sparkleTwo.setPointCount(8);
            sparkleTwo.setPoint(0, sf::Vector2f(40, 70));
            sparkleTwo.setPoint(1, sf::Vector2f(45, 60));
            sparkleTwo.setPoint(2, sf::Vector2f(55, 55));
            sparkleTwo.setPoint(3, sf::Vector2f(45, 50));
            sparkleTwo.setPoint(4, sf::Vector2f(40, 30));
            sparkleTwo.setPoint(5, sf::Vector2f(35, 50));
            sparkleTwo.setPoint(6, sf::Vector2f(25, 55));
            sparkleTwo.setPoint(7, sf::Vector2f(35, 60));
            sparkleTwo.setFillColor(sf::Color(255, 253, 208));
            sparkleTwo.setPosition(1275, 50);
            

            // Creating instruction box and exit button
            guide.setSize({ 1000.f,500.f });
            guide.setPosition(300.f, 250.f);
            exit.setSize({ 380.f,65.f });
            exit.setPosition(600.f,800.f);

            guide.setFillColor(sf::Color(8, 9, 42));
            exit.setFillColor(sf::Color(8, 9, 42));

            //Making Moon example
            sf::CircleShape localMoon(30);
            moon = localMoon;
            moon.setFillColor(sf::Color(255, 255, 224));
            moon.setPosition(340.f, 290.f);

            //Making Clock shape
            sf::CircleShape localClockface(30);
            clockface = localClockface;
            clockface.setFillColor(sf::Color(255, 255, 224));
            clockface.setPosition(348.f, 475.f);
            clockface.setOutlineThickness(6);
            clockface.setOutlineColor(sf::Color(136,8,8));

            //adding Clock hands
            bigClockhand.setSize({ 30.f,5.f });
            bigClockhand.setPosition(380.f, 480.f);
            bigClockhand.setFillColor(sf::Color(0, 0, 0));
            bigClockhand.rotate(90);

            smallClockhand.setSize({ 20.f,3.f });
            smallClockhand.setPosition(380.f, 507.f);
            smallClockhand.setFillColor(sf::Color(0, 0, 0));

            //adding key shape
            sf::ConvexShape localAKey;
            aKey = localAKey;
            aKey.setPointCount(4);
            aKey.setPoint(0, sf::Vector2f(0.1,0));
            aKey.setPoint(1, sf::Vector2f(1.9,0));
            aKey.setPoint(2, sf::Vector2f(2,2));
            aKey.setPoint(3, sf::Vector2f(0,2));
            aKey.setFillColor(sf::Color(211, 211, 211));
            aKey.setPosition(480, 620);
            aKey.scale(30.f, 30.f);

            sf::ConvexShape localWKey;
            wKey = localWKey;
            wKey.setPointCount(4);
            wKey.setPoint(0, sf::Vector2f(0.1, 0));
            wKey.setPoint(1, sf::Vector2f(1.9, 0));
            wKey.setPoint(2, sf::Vector2f(2, 2));
            wKey.setPoint(3, sf::Vector2f(0, 2));
            wKey.setFillColor(sf::Color(211, 211, 211));
            wKey.setPosition(750, 620);
            wKey.scale(30.f, 30.f);

            sf::ConvexShape localDKey;
            dKey = localDKey;
            dKey.setPointCount(4);
            dKey.setPoint(0, sf::Vector2f(0.1, 0));
            dKey.setPoint(1, sf::Vector2f(1.9, 0));
            dKey.setPoint(2, sf::Vector2f(2, 2));
            dKey.setPoint(3, sf::Vector2f(0, 2));
            dKey.setFillColor(sf::Color(211, 211, 211));
            dKey.setPosition(1027, 620);
            dKey.scale(30.f, 30.f);
            

            //Making text blocks for guide
            sf::Text localMoonText("YOU ARE THE MOON. YOU HAVE FALLEN OUT OF THE SKY ONTO AN UNSUSPECTING CITY.", font);
            moonText = localMoonText;
            moonText.setCharacterSize(20);
            moonText.setFillColor(sf::Color(255, 255, 224));
            moonText.setPosition(450.f, 300.f);

            sf::Text localStarText("YOU MUST COLLECT STARDUST TO RETURN TO YOUR RIGHTFUL PLACE IN THE SKY.", font);
            starText = localStarText;
            starText.setCharacterSize(20);
            starText.setFillColor(sf::Color(255, 255, 224));
            starText.setPosition(450.f, 390.f);

            sf::Text localTimeText("BE QUICK THOUGH, IF THE MOON DOESN'T RETURN BEFORE DAYBREAK, YOU LOSE.", font);
            timeText = localTimeText;
            timeText.setCharacterSize(20);
            timeText.setFillColor(sf::Color(255, 255, 224));
            timeText.setPosition(450.f, 490.f);

            //Text for keys
            sf::Text localaKeyText("A", font);
            aKeyText = localaKeyText;
            aKeyText.setCharacterSize(30);
            aKeyText.setFillColor(sf::Color(0, 0, 0));
            aKeyText.setPosition(495.f, 627.f);

            sf::Text localwKeyText("W", font);
            wKeyText = localwKeyText;
            wKeyText.setCharacterSize(30);
            wKeyText.setFillColor(sf::Color(0, 0, 0));
            wKeyText.setPosition(760.f, 630.f);

            sf::Text localdKeyText("D", font);
            dKeyText = localdKeyText;
            dKeyText.setCharacterSize(30);
            dKeyText.setFillColor(sf::Color(0, 0, 0));
            dKeyText.setPosition(1043.f, 630.f);

            //Text instructions for directions
            sf::Text localaMoveText("MOVE LEFT", font);
            aMoveText = localaMoveText;
            aMoveText.setCharacterSize(25);
            aMoveText.setFillColor(sf::Color(255, 255, 224));
            aMoveText.setPosition(440.f, 685.f);

            sf::Text localwMoveText("MOVE UP", font);
            wMoveText = localwMoveText;
            wMoveText.setCharacterSize(25);
            wMoveText.setFillColor(sf::Color(255, 255, 224));
            wMoveText.setPosition(725.f, 685.f);

            sf::Text localdMoveText("MOVE RIGHT", font);
            dMoveText = localdMoveText;
            dMoveText.setCharacterSize(25);
            dMoveText.setFillColor(sf::Color(255, 255, 224));
            dMoveText.setPosition(980.f, 685.f);

            //Text for back button
            sf::Text localExitText("Exit", font);
            exitText = localExitText;
            exitText.setCharacterSize(40);
            exitText.setFillColor(sf::Color(255, 255, 224));
            exitText.setPosition(740.f, 800.f);
        }

        

        void Guide::draw(sf::RenderWindow& window)
        {

            window.clear();
            window.draw(sky);
            window.draw(title);
            window.draw(guide);
            window.draw(moonText);
            window.draw(moon);
            window.draw(clockface);
            window.draw(bigClockhand);
            window.draw(smallClockhand);
            window.draw(starText);
            window.draw(timeText);
            window.draw(starOne);
            window.draw(starTwo);
            window.draw(starThree);
            window.draw(aKey);
            window.draw(wKey);
            window.draw(dKey);
            window.draw(aKeyText);
            window.draw(wKeyText);
            window.draw(dKeyText);
            window.draw(aMoveText);
            window.draw(wMoveText);
            window.draw(dMoveText);
            window.draw(sparkleOne);
            window.draw(sparkleTwo);
            window.draw(exit);
            window.draw(exitText);
            window.display();



        }







        void Guide::handleEvent(sf::RenderWindow& window, sf::Event& event, Game::State& gameState)
        {
            if (event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2f mouse = window.mapPixelToCoords(
                    sf::Mouse::getPosition(window)
                );
                if (exit.getGlobalBounds().contains(mouse))
                {
                    gameState = Game::State::Menu;
                    std::cout << "Back" << std::endl;
                }

            }


        }
    }
}
