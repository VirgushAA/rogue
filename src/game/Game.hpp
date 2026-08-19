#pragma once

#include "../world/World.hpp"
#include "../systems/SystemManager.hpp"


class Game {

    public:
    
    void update(float dt);

    private:

    World world;
    SystemManager systems;

};
