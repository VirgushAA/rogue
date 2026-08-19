#include "SystemManager.hpp"
// #include "../world/World.hpp"

void SystemManager::update(World& world, float dt) {
    movement.update(world, dt);
    combat.update(world);
    damage.update(world);

}