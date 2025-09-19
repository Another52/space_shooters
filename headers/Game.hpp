#pragma once

#include "SFML/Graphics.hpp"
#include "Camera.hpp"
#include "TextureManager.hpp"
#include "Player.hpp"
#include "Background.hpp"
#include "Bullet.hpp"
#include <string>
#include <vector>

class Game
{
public:
	Game();
	void Run();
private:
	void pollEvents();
	void Update();
	void Render();
private:
	sf::Clock clock;
	float deltatime{};
	sf::Vector2u windowSize{ 1280, 720 };
	std::string windowName{ "Game" };
	sf::RenderWindow window{};
	Camera camera;

	//Game entities and what not
private:
	TextureManager texManager;
	Background bg;
	Player player;
	std::vector<std::unique_ptr<Bullet>> playerbullets;
};