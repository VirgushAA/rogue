#include "MovementSystem.hpp"

#include "../components/Transform.hpp"
#include "../components/Velocity.hpp"


void MovementSystem::update(World& world, float dt) {

    for (EntityId entity : world.query<Transform, Velocity>()) {

        auto& transform = world.get<Transform>(entity);
        auto& velocity = world.get<Velocity>(entity);
        
        transform.x += velocity.x * dt;
        transform.y += velocity.y * dt;

    }
}
