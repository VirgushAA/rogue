# include <iostream>

#include "Renderer.hpp"
#include "../components/Name.hpp"
#include "../components/Transform.hpp"

void Renderer::render(World& world) {
    std::vector<char> scene(width * height, ' ');

    drawElements(world, scene);
    drawGrid(scene);
}

void Renderer::drawGrid(std::vector<char>& scene) {
    for (int x = 0; x <= width; ++x) std::cout << '-';
    std::cout << "+\n";
    for (int y = 0; y < height; y++) {
        std::cout << '|';
        for (int x = 0; x < width; x++) {
            std::cout << scene[y * width + x];
        }
        std::cout << "|\n";
    }
    for (int x = 0; x <= width; ++x) std::cout << '-';
    std::cout << "+\n";
}

void Renderer::drawElements(World& world, std::vector<char>& scene) {
    for (EntityId entity : world.entities()) {
        Transform entityTransform = world.get<Transform>(entity);
        Name entotyName = world.get<Name>(entity);
        int entityIndex = entityTransform.y * width + entityTransform.x;
        
        if (entotyName.value == "Player") {
            scene[entityIndex] = '@';
        } else if (entotyName.value == "Goblin") {
            scene[entityIndex] = '%';
        }
    }
}
