#pragma once

#include "State.h"
#include "Game.h"
namespace Cruigo{

    class SplashState: public State{
    public:
        SplashState(gameDataRef data);

        void init();
        void handleInput();
        void update(float dt);
        void draw(float dt);
    private:
        gameDataRef _data;
        sf::Clock _clock;
        sf::Sprite _background;
    };
}