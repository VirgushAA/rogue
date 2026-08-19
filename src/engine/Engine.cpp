#include <chrono>

#include "Engine.hpp"

float updateTime(auto& previousTime);

// Engine::Engine(Game& game) : game(game) {};

void Engine::run() {
    
    bool running = true;
    auto previousTime = std::chrono::steady_clock::now();

    while (true) {

        float dt = updateTime(previousTime);

        game.update(dt);

        // renderer.render(game.world())
    }
}

float updateTime(std::chrono::steady_clock::time_point previousTime) {
    auto currentTime = std::chrono::steady_clock::now();
    std::chrono::duration<float> deltaTime = currentTime - previousTime; // разница
    previousTime = currentTime;

    return deltaTime.count(); // в секундах
}