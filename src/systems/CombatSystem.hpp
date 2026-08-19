#pragma once

#include "../world/World.hpp"

#include "../components/Damage.hpp"
// #include "../components/Health.hpp"

class CombatSystem {
    public:

    void update(World& World);

    void attack(World& world, EntityId attacker, EntityId taret);

    private:

    int calculateDamage(World& world, EntityId attacker);

    //вызывается атакой
    //вычисляет урон
    // вызывает DamageSystem
};
