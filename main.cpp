#include <iostream>

#include "src/ecs/ComponentStorage.hpp"
#include "src/components/Health.hpp"
#include "src/components/Transform.hpp"
#include "src/components/Inventory.hpp"

// debug for now

int main() {

    ComponentStorage<Inventory> a;
    // a.add(1, Health{100, 100});
    // a.add(2, Health{200, 200});
    // a.add(1, Transform{300, 1500});

    EntityId item1 = 1111;
    EntityId item2 = 2222;

    a.add(1, Inventory{{item1,item2}});
    a.add(2, Inventory{{item2}});


    for (const auto& [entity, Inventory] : a) {
        for (const auto& EntityId : Inventory.Items) {
            std::cout << entity << ": " << EntityId << '\n';
        }
    }

    // нужен менеджер, что такое std::type_index

    // a.get(1).current -= 50;

    // for (const auto& [entity, health] : a) {
    //     std::cout << entity << ": " << health.current << '\n';
    // }

    // a.add(1, Health{1000, 1000});

    // std::cout << a.get(14).current;

    return 0;
}
