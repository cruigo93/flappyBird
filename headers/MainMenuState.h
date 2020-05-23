#pragma once

#include "State.h"
#include "Game.h"
namespace Cruigo{

    class MainMenuState: public State{
    public:
        MainMenuState(gameDataRef data);

        void init();
        void handleInput();
        void update(float dt);
        void draw(float dt);
    private:
        gameDataRef _data;
        sf::Sprite _background;
        sf::Sprite _title;
        sf::Sprite _playButton;
    };
}