#include "EntityFactory.hpp"


EntityId EntityFactory::createPlayer(World& world) {
    EntityId id = world.create_entity();

    world.add<Name>(id, {"Player"});
    world.add<PlayerControlled>(id, {true});
    world.add<Transform>(id, {40, 22});
    world.add<Velocity>(id, {0, 0});
    world.add<Health>(id, {100, 100});
    world.add<Mana>(id, {100, 100});
    world.add<Inventory>(id, {});
    world.add<Damage>(id, {10});

    return id;
}

EntityId EntityFactory::createGoblin(World& world) {
    EntityId id = world.create_entity();

    world.add<Name>(id, {"Goblin"});
    world.add<Transform>(id, {60, 5});
    world.add<Velocity>(id, {0, 0});
    world.add<Health>(id, {50, 50});
    world.add<Mana>(id, {100, 100});
    world.add<Inventory>(id, {});
    world.add<Damage>(id, {10});

    return id;
}

EntityId EntityFactory::createItem(World& world) {
    EntityId id = world.create_entity();

    world.add<Name>(id, {"Player"});

    return id;
}
