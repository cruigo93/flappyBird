#pragma once

#include <iostream>
#include <memory>
#include <string>
#include "SFML/Graphics.hpp"
#include "AssetManager.h"
#include "InputManager.h"
#include "StateMachine.h"

namespace Cruigo{
    struct GameData{
        StateMachine machine;
        sf::RenderWindow window;
        AssetManager assets;
        InputManager input;
    };

    typedef std::shared_ptr<GameData> gameDataRef;

    class Game{
    public:
        Game(int width, int height, std::string title);

    private:
        const float dt = 1.0f / 60.f;
        sf::Clock _clock;
        gameDataRef _data = std::make_shared<GameData>();
        void run();
    };

}