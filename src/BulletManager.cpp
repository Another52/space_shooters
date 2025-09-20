#include "BulletManager.hpp"
#include <iostream>

BulletManager::BulletManager(const Entity& player, const sf::RenderWindow& window,
							 TextureManager& texManager, std::string filename, sf::IntRect rectangle)
	:
	player(player),
	window(window),
	texManager(texManager),
	filename(filename),
	rectangle(rectangle),
	shoot(RESOURCES_PATH "shoot.flac")
{
}

void BulletManager::Add()
{
	bullets.push_back(std::make_unique<Bullet>(player, window, texManager, filename, rectangle));
}

void BulletManager::Draw(sf::RenderWindow& window)
{
	for (auto& bullet : bullets)
	{
		bullet->Draw(window);
	}
}

void BulletManager::Update(float deltatime)
{
	for (auto& bullet : bullets)
	{
		bullet->Update(deltatime);
	}

	bullets.erase(
		std::remove_if(bullets.begin(), bullets.end(),
					   [](const std::unique_ptr<Bullet>& b)
					   {
						   return b->IsDead();
					   }),
		bullets.end());
}

void BulletManager::Collide(Entity& entity)
{
	for (auto& bullet : bullets)
	{
		if (bullet->active && bullet->Collision(entity))
		{
			bullet->active = false;
			entity.TakeDamage(bullet->GetDamage());
			bullet->MarkDead();
			break;
		}
	}
}
