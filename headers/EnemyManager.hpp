#pragma once

#include "Enemy.hpp"
#include <vector>
#include <memory>

class EnemyManager
{
public:
	EnemyManager(const sf::Sprite& player, const sf::RenderWindow& window,
				 TextureManager& texManager, std::string filename, sf::IntRect rectangle);
	void Update(float deltatime);
	void Draw(sf::RenderWindow& window);
	void Collide();
	void Spawn();
	const std::vector<std::unique_ptr<Enemy>>& GetEnemies() { return enemies; }
private:
	std::vector<std::unique_ptr<Enemy>> enemies;
	const sf::Sprite& player;
	const sf::RenderWindow& window;
	TextureManager& texManager;
	std::string filename;
	sf::IntRect rectangle;
	float spawnTimer{ 0.f };
	float spawnInterval{ 2.f };
};