#pragma once

#include "../world/World.hpp"

#include "../components/Transform.hpp"
#include "../components/Velocity.hpp"


class MovementSystem {

    public:
    void update(World& world, float deltaTime);
    
};
