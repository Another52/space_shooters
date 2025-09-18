#include "Game.hpp"
#include <iostream>

Game::Game()
	:
	window(sf::VideoMode(windowSize), windowName),
	camera(230.f),
    player(window, texManager, "spaceShip\\stitchedFiles\\spaceships_c.png", sf::IntRect({ 0, 0 }, { 16, 16 })),
    bg(texManager, "background1.png")
    //bullet(player.GetSprite(), texManager, "spaceShip\\stitchedFiles\\projectiles_c.png", sf::IntRect({1, 0}, {2, 4}))
{
	window.setFramerateLimit(60);
    camera.Update(windowSize);
    window.setView(camera.GetView());
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
            camera.Update(windowSize);
            window.setView(camera.GetView());
        }

        //Mouse Buttons
        if (const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>())
        {
            if (mouseButtonPressed->button == sf::Mouse::Button::Left)
            {
                bullets.emplace_back(player.GetSprite(), window, texManager,
                                     "spaceShip\\stitchedFiles\\projectiles_c.png", sf::IntRect({ 1, 0 }, { 2, 4 }));
            }
        }
    }
}

void Game::Update()
{
    //calculate deltatime
	deltatime = clock.restart().asSeconds();
    pollEvents();

    //Update entities
    player.Update(deltatime);

    for(auto& bullet : bullets)
    {
        bullet.Update(deltatime);
    }

    //Update Camera
    camera.Follow(player, deltatime);
    window.setView(camera.GetView());
}

void  Game::Render()
{
	window.clear(sf::Color(155, 155, 155));
    bg.Draw(window);
    player.Draw(window);
    for (auto& bullet : bullets)
    {
        bullet.Draw(window);
    }
    window.display();
}