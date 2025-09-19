#include <iostream>
#include <SFML/Graphics.hpp>
#include "Camera.hpp"
#include "Game.hpp"

int main()
{
    std::srand(std::time(nullptr));
    Game game;
    game.Run();

    return 0;
}
