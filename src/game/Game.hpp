#pragma once

#include "../world/World.hpp"
#include "../systems/SystemManager.hpp"
#include "../factories/EntityFactory.hpp"


class Game {

    public:
    
    void update(float dt);
    World& getWorld();
    void action(char action);

    void moc();

    private:

    World world;
    SystemManager systems;

    EntityFactory ef;

};
