#include <iostream>

#include "ecs/ComponentStorage.hpp"
#include "components/Health.hpp"

int main() {

    ComponentStorage<Health> a;
    a.add(1, Health{100, 100});
    a.add(2, Health{200, 200});

    a.get(1).current -= 50;

    std::cout << a.get(1).current << std::endl;

    for (const auto& [entity, health] : a) {
        std::cout << entity << ": " << health.current << '\n';
    }

    return 0;
}

// #include <windows.h>

// int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
//     ComponentStorage<Health> a;
//     a.add(1, Health{100, 100});
//     a.add(2, Health{200, 200});

//     a.get(1).current -= 50;

//     for (const auto item : a)
//     std::cout << item.first << std::endl; 
//     return 0;
// }