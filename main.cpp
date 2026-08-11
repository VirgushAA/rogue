#include <iostream>

#include "src/ecs/ComponentStorage.hpp"
#include "src/components/Health.hpp"

int main() {

    ComponentStorage<Health> a;
    a.add(1, Health{100, 100});
    a.add(2, Health{200, 200});

    for (const auto& [entity, health] : a) {
        std::cout << entity << ": " << health.current << '\n';
    }

    a.get(1).current -= 50;

    for (const auto& [entity, health] : a) {
        std::cout << entity << ": " << health.current << '\n';
    }

    a.add(1, Health{1000, 1000});

    std::cout << a.get(14);

    return 0;
}
