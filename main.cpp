#include <iostream>
// #include <chrono>

// #include "src/ecs/ComponentStorage.hpp"
// #include "src/components/Health.hpp"
// #include "src/components/Transform.hpp"
// #include "src/components/Inventory.hpp"
// #include "src/components/Mana.hpp"
// #include "src/components/Velocity.hpp"
// #include "src/components/Damage.hpp"

// #include "src/systems/MovementSystem.hpp"
// #include "src/systems/CombatSystem.hpp"
// #include "src/systems/DamageSystem.hpp"

// #include "src/world/World.hpp"

#include "src/engine/Engine.hpp"
#include "src/game/Game.hpp"


int main() {

    Game game;

    Engine engine(game);

    engine.run();

    std::cout << "------------------\n" << "\n";
    std::cout << "bb" << std::endl;
    std::cout << "------------------\n" << "\n";
    return 0;
}








// EntityId player = world.create_entity();
    // EntityId goblin = world.create_entity();

    // EntityId item1 = world.create_entity();
    // EntityId item2 = world.create_entity();
    // EntityId item3 = world.create_entity();

    // world.add<Health>(player, Health{100, 100});
    // world.add<Health>(goblin, Health{200, 200});

    // world.add<Damage>(player, Damage{20});
    
    // world.add<Mana>(player, Mana{300, 300});
    
    // std::cout << "goblin health - " << world.get<Health>(goblin).current << " : " << world.get<Health>(goblin).maximum << std::endl;
    // cs.attack(world, player, goblin);
    // world.emit<DamageEvent>(DamageEvent{player, goblin, 30});
    // for (const DamageEvent event : world.getEvents<DamageEvent>()) {
    //     std::cout << event.damage << "damage from " << event.source << "to" << event.target << "\n";
    // }
    // ds.update(world);
    // std::cout << "goblin health - " << world.get<Health>(goblin).current << " : " << world.get<Health>(goblin).maximum << std::endl;
    // std::cout << world.get<Damage>(player).amount << "\n";

    // MovementSystem ms;

    // auto previousTime = std::chrono::steady_clock::now();
    // update(previousTime);
    // float dt = update(previousTime);
    // for (EntityId entity : world.query<Transform>()) {
    //     std::cout << entity << "\n";
    // }
    // std::cout << "aboba velocity - " << world.get<Velocity>(aboba).x << " : " << world.get<Velocity>(aboba).y << std::endl;
    // std::cout << "aboba position - " << world.get<Transform>(aboba).x << " : " << world.get<Transform>(aboba).y << std::endl;
    // std::cout << "------------------\n" << "\n";
