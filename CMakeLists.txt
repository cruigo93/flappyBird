cmake_minimum_required(VERSION 3.10)

project(flappyBird VERSION 1.0
                  DESCRIPTION "Fappy bird game"
                  LANGUAGES CXX)



#Set executable
add_executable(${PROJECT_NAME}
    src/main.cpp
    src/StateMachine.cpp
    src/AssetManager.cpp
    src/InputManager.cpp
    src/Game.cpp
    src/SplashState.cpp
    src/MainMenuState.cpp
    src/GameState.cpp
    src/GameOverState.cpp
    src/Pipe.cpp
    src/Land.cpp
    src/Bird.cpp
    src/Collision.cpp
    src/Flash.cpp
    src/HUD.cpp
)



#Set module path
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

find_package(SFML REQUIRED audio network graphics window system)

#Finally
target_link_libraries(${PROJECT_NAME} 
    ${SFML_LIBRARIES} 
    ${SFML_DEPENDENCIES}
)
