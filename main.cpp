#include <iostream>

#include "src/ecs/ComponentStorage.hpp"
#include "src/components/Health.hpp"
#include "src/components/Transform.hpp"
#include "src/components/Inventory.hpp"
#include "src/components/Mana.hpp"

#include "src/world/World.hpp"

// debug for now

int main() {

    World world;

    EntityId player = world.create_entity();
    EntityId goblin = world.create_entity();

    EntityId item1 = world.create_entity();
    EntityId item2 = world.create_entity();
    EntityId item3 = world.create_entity();

    world.add<Health>(player, Health{100, 100});
    world.add<Health>(goblin, Health{200, 200});

    std::cout << "player hp - " << world.get<Health>(player).current << " : " << world.get<Health>(player).maximum;
    std::cout << "   |   ";
    std::cout << "goblin hp - " << world.get<Health>(goblin).current << " : " << world.get<Health>(goblin).maximum << std::endl;
    std::cout << "----------------------\n" << "\n";

    world.add<Mana>(player, Mana{300, 300});

    std::cout << "player mana - " << world.get<Mana>(player).current << " : " << world.get<Mana>(player).maximum << std::endl;
    std::cout << "----------------------\n" << "\n";

    world.add<Transform>(player, Transform{10, 20});
    world.add<Transform>(goblin, Transform{11, 19});

    std::cout << "player position - " << world.get<Transform>(player).x << " : " << world.get<Transform>(player).y;
    std::cout << "   |   ";
    std::cout << "goblin position - " << world.get<Transform>(goblin).x << " : " << world.get<Transform>(goblin).y << std::endl;
    std::cout << "------------------\n" << "\n";


    world.add<Inventory>(player, Inventory{{item1, item3}});
    world.add<Inventory>(player, Inventory{{item2}});

    world.get<Health>(player).current -= 30;
    world.get<Mana>(player).current -= 50;
    world.get<Health>(goblin).current -= 20;

    std::cout << "----------------------\n" << "\n";
    std::cout << "player mana - " << world.get<Mana>(player).current << " : " << world.get<Mana>(player).maximum << std::endl;
    std::cout << "----------------------\n" << "\n";
    std::cout << "----------------------\n" << "\n";
    std::cout << "player hp - " << world.get<Health>(player).current << " : " << world.get<Health>(player).maximum;
    std::cout << "   |   ";
    std::cout << "goblin hp - " << world.get<Health>(goblin).current << " : " << world.get<Health>(goblin).maximum << std::endl;
    std::cout << "----------------------\n" << "\n";

    for (EntityId entity : world.query<Transform, Mana>()) {
        std::cout << entity << "\n";
    }
    // std::cout << world.has<Transform>(player) << "\n";

    std::cout << "We are here!" << std::endl;

    return 0;
}
