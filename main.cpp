#include <iostream>
#include <SDL3/SDL.h>
#include <GL/gl.h>

#include "src/engine/Engine.hpp"
#include "src/game/Game.hpp"

const int width = 600;
const int height = 480;
const int gridWidth = 20;
const int gridHeight = 16;
const int cellSize_x = width / gridWidth;
const int cellSize_y = height / height;


int main() {

    if ( SDL_Init(SDL_INIT_VIDEO) != 0 ) {
        std::cout << "SDL_init error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow( "Rogue Huegue",
                                            width,
                                            height,
                                            SDL_WINDOW_OPENGL);
    
    if ( !window ) {
        std::cout << "SDL_CreateWindow error: " << SDL_GetError() << std::endl;
        return 1;
    }

    
    
    return 0;
}


    // Game game;
    // Engine engine(game);
    // engine.run();
    // std::cout << "------------------\n" << "\n";
    // std::cout << "bb" << std::endl;
    // std::cout << "------------------\n" << "\n";