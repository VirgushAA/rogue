#pragma once

#include "../world/World.hpp"


class Game {

    public:
    
    void update(float dt);

    private:

    World world;

};
