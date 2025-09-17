#include <iostream>
#include <SFML/Graphics.hpp>
#include "Camera.hpp"
#include "Game.hpp"

int main()
{
    Game game;
    sf::Texture tex;
    tex.loadFromFile("blah.png");
    game.Run();

    return 0;
}
