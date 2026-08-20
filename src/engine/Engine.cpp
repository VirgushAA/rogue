#include <iostream>
#include <chrono>

#include "Engine.hpp"
#include "../rendering/Renderer.hpp"

float updateTime(std::chrono::steady_clock::time_point& previousTime);

// Engine::Engine(Game& game) : game(game) {};

void Engine::run() {
    
    bool running = true;
    auto previousTime = std::chrono::steady_clock::now();
    float dt = updateTime(previousTime);
    char action = 0;
    Renderer rd;
    game.moc();

    while (running) {

        dt = updateTime(previousTime);

        game.action(action);
        game.update(dt);
        
        rd.render(game.getWorld());

        std::cin.get(action);
        if (action != EOF) { if (action == 'q') running = false; }
    }
}

float updateTime(std::chrono::steady_clock::time_point& previousTime) {
    auto currentTime = std::chrono::steady_clock::now();
    std::chrono::duration<float> deltaTime = currentTime - previousTime; // разница
    previousTime = currentTime;

    return deltaTime.count(); // в секундах
}