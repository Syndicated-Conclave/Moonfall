#pragma once
#include <SFML/Graphics.hpp>

namespace Game
{
    namespace Components
    {
        class AI
        {
        public:
            static sf::Vector2f getDirection(sf::Vector2f previousDirection, sf::Vector2f spawnPosition, sf::Vector2f currentPosition, sf::Vector2f moonPosition, int type);

            static constexpr float FLEE_DISTANCE = 250.f;
            static constexpr float FLEE_SPEED = 5.f;

        private:
            static sf::Vector2f getLyraDirection(sf::Vector2f previousDirection, sf::Vector2f spawnPosition, sf::Vector2f currentPosition);
            static sf::Vector2f getLeoDirection(sf::Vector2f spawnPosition, sf::Vector2f currentPosition, sf::Vector2f moonPosition);
            static sf::Vector2f normaliseDirection(sf::Vector2f direction);
            static bool goalReached(sf::Vector2f current, sf::Vector2f goal);
        };
    }
}

/*

FROM THE LABS:


#pragma once
#include <engine_em.hpp>
#include "engine_ai.hpp"
#include <vector>

class SteeringComponent : public Component
{
protected:
    Seek _seek;
    Flee _flee;
    Entity *_player;
    bool validMove(const sf::Vector2f &) const;

public:
    void update(double) override;
    void move(const sf::Vector2f &);
    void move(float x, float y);
    void render() override {}
    explicit SteeringComponent(Entity *p, Entity *player);
    SteeringComponent() = delete;
};

// steering behaviour output
struct SteeringOutput
{
    // Direction of travel.
    sf::Vector2f direction;
    // Rotation of travel.
    float rotation;
};

// Base class for steering behaviour
class SteeringBehaviour
{
public:
    virtual ~SteeringBehaviour() = default;

    // Getsoutput from a steering behaviour.
    virtual SteeringOutput getSteering() const noexcept = 0;
};

class Flee : public SteeringBehaviour
{
private:
    Entity *_character;
    Entity *_target;
    float _maxSpeed;

public:
    Flee() = delete;
    Flee(Entity *character, Entity *target, float maxSpeed)
        : _character(character), _target(target), _maxSpeed(maxSpeed) {}
    SteeringOutput getSteering() const noexcept;
};
*/