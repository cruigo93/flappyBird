#pragma once

#include "SFML/Graphics.hpp"
#include "Game.h"
#include <vector>
#include "DEFINITIONS.h"

namespace Cruigo{
    class Pipe{
    public:
        Pipe(gameDataRef data);
        void spawnBottomPipe();
        void spawnTopPipe();
        void spawnScoringPipe();
        void spawnInvinsiblePipe();
        void movePipes(float dt);
        void drawPipes();
        void randomizePipeOffset();

        const std::vector<sf::Sprite> &getSprites() const;
        std::vector<sf::Sprite> &getScoringSprites();
    private:
        gameDataRef _data;
        std::vector<sf::Sprite> _pipeSprites;
        std::vector<sf::Sprite> _scoringSprites;
        int _landHeight;
        int _pipeSpawnYOffset;
    };
}