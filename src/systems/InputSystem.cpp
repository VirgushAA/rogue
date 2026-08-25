#include "InputSystem.hpp"


#include "../components/PlayerControlled.hpp"

void InputSystem::update(World& world, char key) {
    switch (key) {
        case 'w':
            for ( EntityId entity : world.query<PlayerControlled>() ) {
                world.commands().push_back(MoveCommand {entity, 0, -1});
            }
            break;
        case 's':
            for ( EntityId entity : world.query<PlayerControlled>() ) {
                world.commands().push_back(MoveCommand {entity, 0, 1});
            }
            break;
        case 'a':
            for (EntityId entity : world.query<PlayerControlled>() ) {
                world.commands().push_back(MoveCommand {entity, -1, 0});
            }
            break;
        case 'd':
            for (EntityId entity : world.query<PlayerControlled>() ) {
                world.commands().push_back(MoveCommand {entity, 1, 0});
            }
        case ' ':
            //atteck handle
            break;
        default: break;
    }
}
