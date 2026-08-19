#pragma once

#include "CombatSystem.hpp"
#include "DamageSystem.hpp"
#include "MovementSystem.hpp"

class SystemManager {
    public:

    void update(World& world, float dt);

    private:

    MovementSystem movement;
    CombatSystem combat;
    DamageSystem damage;
};
