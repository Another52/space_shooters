#include "Game.hpp"
#include <iostream>

Game::Game()
	:
	window(sf::VideoMode(windowSize), windowName),
	camera(230.f, window),
    bg(texManager, player.GetSprite(), "background1.png"),
    player(window, texManager, "spaceShip\\stitchedFiles\\spaceships_c.png", sf::IntRect({ 0, 16 }, { 16, 16 })),
    enemies(player.GetSprite(), window, texManager,
            "spaceShip\\stitchedFiles\\spaceships_c.png", sf::IntRect({ 0, 0 }, { 16, 16 }))
{
    //do stuff
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

        //focus stuff
        if (event->is<sf::Event::FocusLost>())
            gamestate = GAMEPAUSE;
        if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
        {
            if (keyPressed->scancode == sf::Keyboard::Scan::Escape)
            {
                if (gamestate == GAMEPAUSE)
                    gamestate = GAMERUNNING;
                else if (gamestate == GAMERUNNING)
                    gamestate = GAMEPAUSE;
            }
        }
        //resized event
        if (const auto* resized = event->getIf<sf::Event::Resized>())
        {
            camera.Update(windowSize);
            window.setView(camera.GetView());
        }

        //Mouse Buttons
        if (gamestate != GAMERUNNING)
            return;
        if (const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>())
        {
            if (mouseButtonPressed->button == sf::Mouse::Button::Left)
            {
                playerbullets.Add(std::make_unique<Bullet>(
                    player, window, texManager,
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

    if(gamestate == GAMERUNNING)
    {
        //Update entities
        player.Update(deltatime);
        auto playerpos = player.GetSprite().getPosition();
        playerbullets.Update(deltatime);
        enemies.Update(deltatime);

        //Collision bullets with enemies
        enemies.Collide(playerbullets);

        //Update Camera
        camera.Follow(player, deltatime);
        window.setView(camera.GetView());
        bg.Update(window.getView());
    }
}

void  Game::Render()
{
	window.clear(sf::Color(155, 155, 155));
    bg.Draw(window);
    playerbullets.Draw(window);
    player.Draw(window);
    enemies.Draw(window);
    window.display();
}