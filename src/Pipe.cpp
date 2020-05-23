#include "../headers/Pipe.h"

namespace Cruigo{
    Pipe::Pipe(gameDataRef data) : _data(data){
        _landHeight = _data->assets.getTexture("Land").getSize().y;
        _pipeSpawnYOffset = 0;
    }

    void Pipe::spawnBottomPipe(){
        sf::Sprite sprite(_data->assets.getTexture("Pipe Up"));
        sprite.setPosition(_data->window.getSize().x, _data->window.getSize().y - sprite.getGlobalBounds().height - _pipeSpawnYOffset);
        _pipeSprites.push_back(sprite);

    }
    void Pipe::spawnTopPipe(){
        sf::Sprite sprite(_data->assets.getTexture("Pipe Down"));
        sprite.setPosition(_data->window.getSize().x, -_pipeSpawnYOffset);
        _pipeSprites.push_back(sprite);
    }
    void Pipe::spawnInvinsiblePipe(){
        sf::Sprite sprite(_data->assets.getTexture("Pipe Up"));
        sprite.setPosition(_data->window.getSize().x, _data->window.getSize().y - sprite.getGlobalBounds().height);
        sprite.setColor(sf::Color(0, 0, 0, 0));
        _pipeSprites.push_back(sprite);
    }

    void Pipe::spawnScoringPipe(){
        sf::Sprite sprite(_data->assets.getTexture("Scoring Pipe"));
        sprite.setPosition(_data->window.getSize().x, 0);
        _scoringSprites.push_back(sprite);
    }

    void Pipe::movePipes(float dt){
        for (unsigned short int i=0; i<_pipeSprites.size(); i++){
            if (_pipeSprites.at(i).getPosition().x < 0 - _pipeSprites.at(i).getGlobalBounds().width){
                _pipeSprites.erase(_pipeSprites.begin() + i);
            }
            else{
                sf::Vector2f position = _pipeSprites.at(i).getPosition();
                float movement = PIPE_MOVEMENT_SPEED * dt;
                _pipeSprites.at(i).move(-movement, 0);
            }
        }

        for (unsigned short int i=0; i<_scoringSprites.size(); i++){
            if (_scoringSprites.at(i).getPosition().x < 0 - _scoringSprites.at(i).getGlobalBounds().width){
                _scoringSprites.erase(_scoringSprites.begin() + i);
            }
            else{
                sf::Vector2f position = _scoringSprites.at(i).getPosition();
                float movement = PIPE_MOVEMENT_SPEED * dt;
                _scoringSprites.at(i).move(-movement, 0);
            }
        }
    }
    void Pipe::drawPipes(){
        for (unsigned short int i=0; i<_pipeSprites.size(); i++){
            _data->window.draw(_pipeSprites.at(i));
        }
    }
    void Pipe::randomizePipeOffset(){
        _pipeSpawnYOffset = rand() % (_landHeight + 1);
    }
    const std::vector<sf::Sprite> &Pipe::getSprites() const{
        return _pipeSprites;
    }
    std::vector<sf::Sprite> &Pipe::getScoringSprites(){
        return _scoringSprites;
    }
}