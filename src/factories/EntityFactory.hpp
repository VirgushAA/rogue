#pragma once

#include "../world/World.hpp"


class EntityFactory {
    public:
    
    EntityId createPlayer(World& world);
    EntityId createGoblin(World& world);
    EntityId createItem(World& world);
    
};
