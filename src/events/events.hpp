#pragma once

#include "../core/EntityId.hpp"

struct DamageEvent {
    EntityId source;
    EntityId target;
    int value;
};

struct CollisionEvent {
    EntityId first;
    EntityId secobd;
};
