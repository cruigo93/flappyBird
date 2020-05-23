#include "../headers/MainMenuState.h"
#include "../headers/GameState.h"
#include <sstream>
#include "../headers/DEFINITIONS.h"
#include <iostream>

namespace Cruigo{

    MainMenuState::MainMenuState(gameDataRef data) : _data(data){

    }
    void MainMenuState::init(){
        _data->assets.loadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
        _data->assets.loadTexture("Game Title", GAME_TITLE_FILEPATH);
        _data->assets.loadTexture("Play Button", PLAY_BUTTON_FILEPATH);
        _background.setTexture(_data->assets.getTexture("Main Menu Background"));
        _title.setTexture(_data->assets.getTexture("Game Title"));
        _playButton.setTexture(_data->assets.getTexture("Play Button"));

        _title.setPosition((SCREEN_WIDTH / 2) - (_title.getGlobalBounds().width / 2), 
                            _title.getGlobalBounds().height / 2);
        _playButton.setPosition((SCREEN_WIDTH / 2) - (_playButton.getGlobalBounds().width / 2), 
                            (SCREEN_HEIGHT / 2) - (_playButton.getGlobalBounds().height / 2));
    }
    void MainMenuState::handleInput(){
        sf::Event event;
        while(_data->window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                _data->window.close();
            }
            if (_data->input.isSpriteClicked(_playButton, sf::Mouse::Left, _data->window)){
                _data->machine.addState(stateRef(new GameState(this->_data)), true);
            }
        }
    }
    void MainMenuState::update(float dt){
        
    }
    void MainMenuState::draw(float dt){
        _data->window.clear();
        _data->window.draw(_background);
        _data->window.draw(_title);
        _data->window.draw(_playButton);
        _data->window.display();
    }
}