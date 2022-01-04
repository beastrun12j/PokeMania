# The minimum version of CMake required
cmake_minimum_required(VERSION 3.20)

# The project name
project(PokeMania)

# The C++ standard version for the project
set(CMAKE_CXX_STANDARD 14)

set(SFML_INCLUDE_DIR "./SFML/include")
set(SFML_LIBRARY_DIR "./SFML/build/lib")

link_directories(SFML_LIBRARY_DIR)
link_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)
add_executable(PokeMania main.cpp Game/engine/StateMachine/State.h Game/engine/StateMachine/StateMachine.cpp Game/engine/StateMachine/StateMachine.h Game/engine/InputManager/InputManager.cpp Game/engine/InputManager/InputManager.h Game/engine/AssetManager/AssetManager.cpp Game/engine/AssetManager/AssetManager.h Game/headers/SplashState.h Game/headers/MainMenuState.h Game/headers/GameState.h Game/headers/GameOverState.h Game/headers/Game.h Game/headers/Bird.h Game/headers/Collision.h Game/headers/Flash.h Game/headers/HUD.h Game/headers/Land.h Game/headers/Pipe.h Game/Bird.cpp Game/Collision.cpp Game/Flash.cpp Game/Game.cpp Game/GameOverState.cpp Game/GameState.cpp Game/HUD.cpp Game/Land.cpp Game/MainMenuState.cpp Game/Pipe.cpp Game/SplashState.cpp Game/headers/CONSTANTS.h)
target_link_libraries(PokeMania sfml-system sfml-window sfml-graphics sfml-audio sfml-network)