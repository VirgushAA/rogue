#pragma once

#include "../game/Game.hpp"


class Engine {

public:
    Engine(Game& gane);

    void run();

private:

    Game& game;

};
