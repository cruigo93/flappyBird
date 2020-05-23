#pragma once

#include "State.h"
#include "Game.h"
namespace Cruigo{

    class GameOverState: public State{
    public:
        GameOverState(gameDataRef data, int score);

        void init();
        void handleInput();
        void update(float dt);
        void draw(float dt);
    private:
        gameDataRef _data;
        sf::Sprite _background;
        sf::Sprite _gameOverTitle;
        sf::Sprite _gameOverBody;
        sf::Sprite _gameOverContainer;
        sf::Sprite _retryButton;
        sf::Sprite _medal;

        sf::Text _scoreText;
        sf::Text _highScoreText;

        int _score;
        int _highScore;
    };
}