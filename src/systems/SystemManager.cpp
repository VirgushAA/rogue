#include "SystemManager.hpp"
// #include "../world/World.hpp"

void SystemManager::update(World& world, float dt) {
    
    movement.update(world, dt);
    // static_cast<void>(dt);
    movement.update(world);
    combat.update(world);
    damage.update(world);

}

InputSystem& SystemManager::input() { return input_; }