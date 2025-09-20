#include "Game.hpp"
#include <iostream>

Game::Game()
	:
	window(sf::VideoMode(windowSize), windowName),
	camera(230.f, window),
    player(window, texManager, "spaceShip\\stitchedFiles\\spaceships_c.png", sf::IntRect({ 0, 16 }, { 16, 16 })),
    bg(texManager, "background1.png"),
    enemy(player.GetSprite(), window, texManager, "spaceShip\\stitchedFiles\\spaceships_c.png", sf::IntRect({0, 0}, {16, 16}))
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
                /*playerbullets.emplace_back(player.GetSprite(), window, texManager,
                                     "spaceShip\\stitchedFiles\\projectiles_c.png", sf::IntRect({ 1, 0 }, { 2, 4 }));*/
                playerbullets.Add(std::make_unique<Bullet>(
                    player.GetSprite(), window, texManager,
                    "spaceShip\\stitchedFiles\\projectiles_c.png", sf::IntRect({ 1, 0 }, { 2, 4 }))
                );
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
    playerbullets.Update(deltatime);
    enemy.Update(deltatime);

    //Collision
    playerbullets.Collide(enemy);

    //Update Camera
    camera.Follow(player, deltatime);
    window.setView(camera.GetView());
}

void  Game::Render()
{
	window.clear(sf::Color(155, 155, 155));
    bg.Draw(window);
    playerbullets.Draw(window);
    player.Draw(window);
    enemy.Draw(window);
    window.display();
}