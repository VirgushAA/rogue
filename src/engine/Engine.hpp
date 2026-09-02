#pragma once

#include <chrono>

#include "../game/Game.hpp"


float updateTime(std::chrono::steady_clock::time_point& previousTime);

class Engine {
    
    public:
    Engine(Game& game) : game(game) {};
    
    void run();
    
    private:
    
    Game& game;
    
};
