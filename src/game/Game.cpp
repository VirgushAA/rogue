#include "Game.hpp"


void Game::update(float dt) {
    systems.update(world, dt);
}
