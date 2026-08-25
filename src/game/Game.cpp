#include "Game.hpp"


void Game::update(float dt) {
    systems.update(world, dt);
}

World& Game::getWorld() { return world; }

void Game::action(char action) {
    systems.input().update(world, action);
}

void Game::moc() {
    ef.createPlayer(world);
    ef.createGoblin(world);
}
