#include "Game.hpp"


void Game::update(float dt) {
    systems.update(world, dt);
}

World& Game::getWorld() { return world; }

void Game::action(char action) {

    switch (action) {
        case 'w': world.get<Transform>(1).y -= 1;
        break;
        case 's': world.get<Transform>(1).y += 1;
        break;
        case 'a': world.get<Transform>(1).x -= 1;
        break;
        case 'd': world.get<Transform>(1).x += 1;
        break;
        default:
        break;
    }
}

void Game::moc() {
    ef.createPlayer(world);
    ef.createGoblin(world);
}
