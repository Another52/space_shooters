#pragma once

#include "SFML/Graphics.hpp"
#include "Camera.hpp"
#include "Background.hpp"
#include "TextureManager.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "BulletManager.hpp"
#include "EnemyManager.hpp"
#include <string>
#include <vector>

enum GAMESTATE
{
	GAMEPAUSE,
	GAMERUNNING,
};

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
	GAMESTATE gamestate{ GAMEPAUSE };
	TextureManager texManager;
	Background bg;
	Player player;
	BulletManager playerbullets;
	EnemyManager enemies;
};