// #include <ctime>

#include "Engine.hpp"
#include "../game/Game.hpp"

void Engine::run() {

    while (!0) {
        
        float dt = 0; // clock.delta() скорее всего через chrono duration_cast

        game.update(dt);

        // renderer.render(game.world())
    }
}

