#pragma once

#include "CombatSystem.hpp"
#include "DamageSystem.hpp"
#include "MovementSystem.hpp"
#include "InputSystem.hpp"

class SystemManager {
    public:

    void update(World& world, float dt);
    InputSystem& input();

    private:

    InputSystem input_;
    MovementSystem movement;
    CombatSystem combat;
    DamageSystem damage;
};
