#include "MovementSystem.hpp"

#include "src/components/Transform.hpp"
#include "src/components/Velocity.hpp"


void MovementSystem::update(World& world, float dt) {

    // получает сущности ,у которых есть Transform и Velocity
    // переделать в query
    for (EntityId entity : world.query<Transform, Velocity>()) {

        auto& transform = world.get<Transform>(entity);
        auto& velocity = world.get<Velocity>(entity);
        
        transform.x += velocity.x * dt;
        transform.y += velocity.y * dt;
    }
    
    // для каждой:
    // Transform + Velocity * deltaTime
}
