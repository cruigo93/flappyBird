#pragma once

#include "SFML/Graphics.hpp"

#include "DEFINITIONS.h"
#include "Game.h"
#include <vector>
namespace Cruigo{

    class Bird{
    public:    
        Bird(gameDataRef data);
        void draw();
        void animate(float dt);
        void update(float dt);
        void tap();
        const sf::Sprite &getSprite() const;
    private:
        gameDataRef _data;
        sf::Sprite _birdSprite;
        std::vector<sf::Texture> _animationFrames;
        unsigned int _animationIterator;
        sf::Clock _clock;
        sf::Clock _movementClock;
        int _birdState;
        float _rotation;
    };
}