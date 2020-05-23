#include "../headers/SplashState.h"
#include "../headers/MainMenuState.h"
#include <sstream>
#include "../headers/DEFINITIONS.h"
#include <iostream>

namespace Cruigo{

    SplashState::SplashState(gameDataRef data) : _data(data){

    }
    void SplashState::init(){
        this->_data->assets.loadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);
        _background.setTexture(this->_data->assets.getTexture("Splash State Background"));
    }
    void SplashState::handleInput(){
        sf::Event event;
        while(this->_data->window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                this->_data->window.close();
            }
        }
    }
    void SplashState::update(float dt){
        if (this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME){
            this->_data->machine.addState(stateRef(new MainMenuState(this->_data)), true);
        }
    }
    void SplashState::draw(float dt){
        this->_data->window.clear();
        this->_data->window.draw(this->_background);
        this->_data->window.display();
    }
}