#pragma once

#include "../game/Game.hpp"


class Engine {

public:
    Engine(Game& game) : game(game) {};

    void run();

private:

    Game& game;

};
