#include "Game.hpp"
#include <iostream>

Game::Game()
	:
	window(sf::VideoMode(windowSize), windowName),
	camera(500.f)
{
	//window.setFramerateLimit(1000);
	window.setView(camera.GetView(windowSize));
    texManager.GetTexture("background1.png");
}

void Game::Run()
{
    while (window.isOpen())
    {
        Update();
        Render();
    }
}

void Game::pollEvents()
{
    while (const std::optional event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            window.close();
        }
        if (const auto* resized = event->getIf<sf::Event::Resized>())
        {
            window.setView(camera.GetView(window.getSize()));
        }
    }
}

void Game::Update()
{
    //calculate deltatime
	deltatime = clock.restart().asSeconds();


}

void  Game::Render()
{
	window.clear(sf::Color(155, 155, 155));
    
}