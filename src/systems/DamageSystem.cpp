#include "DamageSystem.hpp"


void DamageSystem::update(World& world) {

    for (const DamageEvent& event : world.getEvents<DamageEvent>()) {
        if (!world.has<Health>(event.target)) continue;

        world.get<Health>(event.target).current -= event.damage;
    }
}
