#pragma once

#include "../world/World.hpp"

#include "../components/Health.hpp"
#include "../components/Damage.hpp"

class DamageSystem {
    public:
    
    void update(World& world);
};
