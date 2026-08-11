#pragma once


class Engine {

public:
    Engine(Game& gane);

    void run();

private:

    Game& game;

};
