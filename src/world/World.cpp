#include "World.hpp"
#include "../core/EntityId.hpp"


EntityId World::create_entity() {
    EntityId entity = next_entity_id++;

    entities_.insert(entity);

    return entity;
}

const std::unordered_set<EntityId>& World::entities() const { return entities_; }

std::vector<MoveCommand> World::commands() { return commands_; }
