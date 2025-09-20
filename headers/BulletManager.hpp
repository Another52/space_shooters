#pragma once

#include "Entity.hpp"
#include "Bullet.hpp"
#include "Enemy.hpp"
#include <vector>
#include <memory>
#include <string>

class BulletManager
{
public:
	void Add(std::unique_ptr<Bullet> bullet);
	void Update(float deltatime);
	void Draw(sf::RenderWindow& window);
	void Collide(Entity& entity);
private:
	std::vector<std::unique_ptr<Bullet>> bullets;
};