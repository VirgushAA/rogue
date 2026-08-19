#pragma once

#include "../core/EntityId.hpp"

struct DamageEvent {
    EntityId source;
    EntityId target;
    int damage;
};

struct CollisionEvent {
    EntityId first;
    EntityId secobd;
};
