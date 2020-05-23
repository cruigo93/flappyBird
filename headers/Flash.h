#pragma once
#include "SFML/Graphics.hpp"
#include "Game.h"
#include "DEFINITIONS.h"

namespace Cruigo{

    class Flash{
    public:
        Flash(gameDataRef data);
        void show(float dt);
        void draw();
    private:
        gameDataRef _data;
        sf::RectangleShape _shape;
        bool _flashOn;
    };
}