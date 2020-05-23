#include <iostream>
#include "SFML/Graphics.hpp"
#include "../headers/Game.h"
#include "../headers/DEFINITIONS.h"

int main(){
    Cruigo::Game(SCREEN_WIDTH, SCREEN_HEIGHT, "Flappy Bird");
    return EXIT_SUCCESS;
}