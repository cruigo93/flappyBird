#pragma once

#include "Game.h"
#include "SFML/Graphics.hpp"
#include <vector>

namespace Cruigo{
    class Land{
    public:
        Land(gameDataRef data);

        void moveLand(float dt);
        void drawLand();
        const std::vector<sf::Sprite> &getSprites() const;
    private:
        gameDataRef _data;
        std::vector<sf::Sprite>_landSprites;
    };
}