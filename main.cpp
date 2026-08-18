#include <iostream>
#include <chrono>

#include "src/ecs/ComponentStorage.hpp"
#include "src/components/Health.hpp"
#include "src/components/Transform.hpp"
#include "src/components/Inventory.hpp"
#include "src/components/Mana.hpp"
#include "src/components/Velocity.hpp"
#include "src/systems/MovementSystem.hpp"

// #include "src/world/World.hpp"

// debug for now

float update(auto& previousTime);

int main() {

    World world;

    EntityId player = world.create_entity();
    EntityId goblin = world.create_entity();

    EntityId item1 = world.create_entity();
    EntityId item2 = world.create_entity();
    EntityId item3 = world.create_entity();

    world.add<Health>(player, Health{100, 100});
    world.add<Health>(goblin, Health{200, 200});
    
    world.add<Mana>(player, Mana{300, 300});
    
    std::cout << "player hp - " << world.get<Health>(player).current << " : " << world.get<Health>(player).maximum;
    std::cout << "   |   ";
    std::cout << "goblin hp - " << world.get<Health>(goblin).current << " : " << world.get<Health>(goblin).maximum << std::endl;
    std::cout << "player mana - " << world.get<Mana>(player).current << " : " << world.get<Mana>(player).maximum << std::endl;

    world.add<Transform>(player, Transform{10, 20});
    world.add<Transform>(goblin, Transform{11, 19});

    world.add<Inventory>(player, Inventory{{item1, item3}});
    world.add<Inventory>(player, Inventory{{item2}});

    world.get<Health>(player).current -= 30;
    world.get<Mana>(player).current -= 50;
    world.get<Health>(goblin).current -= 20;

    std::cout << "player position - " << world.get<Transform>(player).x << " : " << world.get<Transform>(player).y;
    std::cout << "   |   ";
    std::cout << "goblin position - " << world.get<Transform>(goblin).x << " : " << world.get<Transform>(goblin).y << std::endl;
    std::cout << "------------------\n" << "\n";
    std::cout << "player hp - " << world.get<Health>(player).current << " : " << world.get<Health>(player).maximum;
    std::cout << "   |   ";
    std::cout << "goblin hp - " << world.get<Health>(goblin).current << " : " << world.get<Health>(goblin).maximum << std::endl;
    std::cout << "player mana - " << world.get<Mana>(player).current << " : " << world.get<Mana>(player).maximum << std::endl;
    std::cout << "----------------------\n" << "\n";

    EntityId aboba = 42;
    world.add<Health>(aboba, Health{1000, 1000});
    world.add<Transform>(aboba, Transform{1000, 1000});
    world.add<Inventory>(aboba, Inventory{{item1, item2, item3}});
    world.add<Mana>(aboba, Mana{1000, 1000});
    world.add<Velocity>(aboba, Velocity{1000, 1000});


    //--- пример обновления для теста систем

    MovementSystem ms;

    auto previousTime = std::chrono::steady_clock::now();
    update(previousTime);
    float dt = update(previousTime);

    std::cout << "aboba velocity - " << world.get<Velocity>(aboba).x << " : " << world.get<Velocity>(aboba).y << std::endl;
    std::cout << "aboba position - " << world.get<Transform>(aboba).x << " : " << world.get<Transform>(aboba).y << std::endl;
    std::cout << "------------------\n" << "\n";

    ms.update(world, dt);

    std::cout << "aboba velocity - " << world.get<Velocity>(aboba).x << " : " << world.get<Velocity>(aboba).y << std::endl;
    std::cout << "aboba position - " << world.get<Transform>(aboba).x << " : " << world.get<Transform>(aboba).y << std::endl;
    std::cout << "------------------\n" << "\n";

    ms.update(world, dt);

    std::cout << "aboba velocity - " << world.get<Velocity>(aboba).x << " : " << world.get<Velocity>(aboba).y << std::endl;
    std::cout << "aboba position - " << world.get<Transform>(aboba).x << " : " << world.get<Transform>(aboba).y << std::endl;
    std::cout << "------------------\n" << "\n";

    auto& abobaVel = world.get<Velocity>(aboba);
    abobaVel.x = -1000;
    abobaVel.y -= 2000;
    ms.update(world, dt);

    std::cout << "aboba velocity - " << world.get<Velocity>(aboba).x << " : " << world.get<Velocity>(aboba).y << std::endl;
    std::cout << "aboba position - " << world.get<Transform>(aboba).x << " : " << world.get<Transform>(aboba).y << std::endl;
    std::cout << "------------------\n" << "\n";

    for (EntityId entity : world.query<Transform>()) {
        std::cout << entity << "\n";
    }
    // std::cout << world.has<Transform>(player) << "\n";


    std::cout << "We are here!" << std::endl;

    return 0;
}

float update(auto& previousTime) {
    auto currentTime = std::chrono::steady_clock::now();
    auto deltaTime = currentTime - previousTime; // разница
    previousTime = currentTime; // обновляем "якорь" для следующего кадра

    return deltaTime.count(); // в секундах
}