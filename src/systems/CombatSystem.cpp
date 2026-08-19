#include "CombatSystem.hpp"


void CombatSystem::update(World& world) {
    attack(world, 1, 2);
}

void CombatSystem::attack(World& world, EntityId attacker, EntityId target) {
    int damage = calculateDamage(world, attacker);

    world.emit<DamageEvent>(DamageEvent{
        attacker,
        target,
        damage
    });
}

int CombatSystem::calculateDamage(World& world, EntityId attacker) { return world.get<Damage>(attacker).amount; }
// дополнить логику урона
