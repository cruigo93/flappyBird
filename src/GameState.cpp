#include "../headers/GameState.h"
#include <sstream>
#include "../headers/DEFINITIONS.h"
#include <iostream>
#include "../headers/GameOverState.h"
namespace Cruigo{

    GameState::GameState(gameDataRef data) : _data(data){

    }
    void GameState::init(){

        if (!_hitSoundBuffer.loadFromFile(HIT_SOUND_FILEPATH)){
            std::cout << "Error loading Hit sound file" << std::endl;
        }
        if (!_wingSoundBuffer.loadFromFile(WING_SOUND_FILEPATH)){
            std::cout << "Error loading Wing sound file" << std::endl;
        }
        if (!_pointSoundBuffer.loadFromFile(POINT_SOUND_FILEPATH)){
            std::cout << "Error loading Point sound file" << std::endl;
        }
        _hitSound.setBuffer(_hitSoundBuffer);
        _wingSound.setBuffer(_wingSoundBuffer);
        _pointSound.setBuffer(_pointSoundBuffer);
        _data->assets.loadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
        _data->assets.loadTexture("Pipe Up", PIPE_UP_FILEPATH);
        _data->assets.loadTexture("Pipe Down", PIPE_DOWN_FILEPATH);
        _data->assets.loadTexture("Land", LAND_FILEPATH);
        _data->assets.loadTexture("Bird Frame 1", BIRD_FRAME_1_FILEPATH);
        _data->assets.loadTexture("Bird Frame 2", BIRD_FRAME_2_FILEPATH);
        _data->assets.loadTexture("Bird Frame 3", BIRD_FRAME_3_FILEPATH);
        _data->assets.loadTexture("Bird Frame 4", BIRD_FRAME_4_FILEPATH);
        _data->assets.loadTexture("Scoring Pipe", SCORING_PIP_FILEPATH);
        _data->assets.loadFont("Flappy Font", FLAPPY_FONT_FILEPATH);

        pipe = new Pipe(_data);
        _land = new Land(_data);
        _bird = new Bird(_data);
        _flash = new Flash(_data);
        _hud = new HUD(_data);
        _background.setTexture(_data->assets.getTexture("Game Background"));

        _score = 0;
        _hud->updateScore(_score);
        _gameState = GameStates::eReady;
    }
    void GameState::handleInput(){
        sf::Event event;
        while(this->_data->window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                this->_data->window.close();
            }
            if (_data->input.isSpriteClicked(_background, sf::Mouse::Left, _data->window)){
                if (_gameState != GameStates::eGameOver){
                    _gameState = GameStates::ePlaying;
                    _bird->tap();
                    _wingSound.play();
                }
            }
        }
    }
    void GameState::update(float dt){

        if (_gameState != GameStates::eGameOver){
            _bird->animate(dt);
            _land->moveLand(dt);
        }
        if (_gameState == GameStates::ePlaying){
            pipe->movePipes(dt);
            if (_clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY){
                pipe->randomizePipeOffset();
                pipe->spawnInvinsiblePipe();
                pipe->spawnBottomPipe();
                pipe->spawnTopPipe();
                
                pipe->spawnScoringPipe();

                _clock.restart();
            }
            
            _bird->update(dt);

            std::vector<sf::Sprite> landSprites = _land->getSprites();
            for (unsigned short i=0; i<landSprites.size(); i++){
                if (_collision.checkSpriteCollision(_bird->getSprite(), 0.7f, landSprites.at(i), 1.0f)){
                    _gameState = GameStates::eGameOver;
                    _clock.restart();
                    _hitSound.play();
                }
            }

            std::vector<sf::Sprite> pipeSprites = pipe->getSprites();
            for (unsigned short i=0; i<pipeSprites.size(); i++){
                if (_collision.checkSpriteCollision(_bird->getSprite(), 0.625f, pipeSprites.at(i), 1.0)){
                    _gameState = GameStates::eGameOver;
                    _clock.restart();
                    _hitSound.play();
                }
            }

            if (_gameState == GameStates::ePlaying){

                std::vector<sf::Sprite> &scoringSprites = pipe->getScoringSprites();
                for (unsigned short i=0; i<scoringSprites.size(); i++){
                    if (_collision.checkSpriteCollision(_bird->getSprite(), 0.625f, scoringSprites.at(i), 1.0)){
                        _score++;
                        std::cout << _score << std::endl;

                        scoringSprites.erase(scoringSprites.begin() + i);
                        _pointSound.play();
                    }
                }
                _hud->updateScore(_score);
            }

        }
        if (_gameState == GameStates::eGameOver){
            _flash->show(dt);
            if (_clock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER_APPEARS){
                _data->machine.addState(stateRef(new GameOverState(_data, _score)), true);
            }
        }
    }
    void GameState::draw(float dt){
        this->_data->window.clear();
        this->_data->window.draw(this->_background);
        pipe->drawPipes();
        _land->drawLand();
        _bird->draw();
        _flash->draw();
        _hud->draw();
        this->_data->window.display();
        
    }

}