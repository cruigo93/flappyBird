#pragma once

#include "State.h"
#include "Game.h"
#include "Pipe.h"
#include "Land.h"
#include "Bird.h"
#include "Collision.h"
#include "Flash.h"
#include "HUD.h"

#include "SFML/Audio.hpp"
namespace Cruigo{

    class GameState: public State{
    public:
        GameState(gameDataRef data);

        void init();
        void handleInput();
        void update(float dt);
        void draw(float dt);
    private:
        gameDataRef _data;
        sf::Sprite _background;

        Pipe *pipe;
        Land *_land;
        Bird *_bird;
        Flash *_flash;
        HUD *_hud;
        Collision _collision;
        sf::Clock _clock;

        int _gameState;
        int _score;

        sf::SoundBuffer _hitSoundBuffer;
        sf::SoundBuffer _wingSoundBuffer;
        sf::SoundBuffer _pointSoundBuffer;

        sf::Sound _hitSound;
        sf::Sound _wingSound;
        sf::Sound _pointSound;
    };
}