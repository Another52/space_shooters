#include "EnemyManager.hpp"

EnemyManager::EnemyManager(const sf::Sprite& player, const sf::RenderWindow& window, TextureManager& texManager,
						   std::string filename, sf::IntRect rectangle)
	:
	player(player), window(window), texManager(texManager),
	filename(filename), rectangle(rectangle)
{
}

void EnemyManager::Update(float deltatime)
{
	spawnTimer += deltatime;
	if (spawnTimer > spawnInterval)
	{
		Spawn();
	}

	for (auto& enemy : enemies)
	{
		enemy->Update(deltatime);
	}

	enemies.erase(
		std::remove_if(enemies.begin(), enemies.end(),
					   [](const std::unique_ptr<Enemy>& e) { return e->IsDead(); }),
		enemies.end());
}

void EnemyManager::Draw(sf::RenderWindow& window)
{
	for (auto& enemy : enemies)
	{
		enemy->Draw(window);
	}
}

void EnemyManager::Collide()
{
	for (auto& enemy : enemies)
	{
		//enemy->Update();
	}
}

void EnemyManager::Spawn()
{
	enemies.push_back(std::make_unique<Enemy>(player, window, texManager, filename, rectangle));
}