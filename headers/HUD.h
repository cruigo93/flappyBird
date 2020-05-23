#pragma once
#include "Game.h"
#include "DEFINITIONS.h"

namespace Cruigo{
    class HUD{
    public:
        HUD(gameDataRef data);
        void updateScore(int score);
        void draw();

    private:
        gameDataRef _data;
        sf::Text _scoreText;
    };
}