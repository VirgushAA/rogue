#include "World.hpp"
#include "../core/EntityId.hpp"

EntityId World::create_entity() {
    return next_entity_id++;
}
