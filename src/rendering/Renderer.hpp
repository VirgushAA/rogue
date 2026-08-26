#pragma once

#include "../world/World.hpp"


class Renderer {
    public:

    void render(World& world);
    
    private:

    void drawGrid(std::vector<char>& scene);
    void drawElements(World& World, std::vector<char>& scene);

    const int height = 25;
    const int width = 80;

    private:
};
