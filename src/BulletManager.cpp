#include "BulletManager.hpp"
#include <iostream>

void BulletManager::Add(std::unique_ptr<Bullet> bullet)
{
	bullets.push_back(std::move(bullet));
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
