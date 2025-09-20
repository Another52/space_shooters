#pragma once

#include "Entity.hpp"
#include <vector>

class Bullet : public Entity
{
public:
	Bullet(const Entity& obj, const sf::RenderWindow& window,
		   TextureManager& texManager, const std::string& filename, sf::IntRect& rectangle);
	void Update(float deltatime) override;

private:
	sf::Vector2f dir;
	float lifetime{ 2.f };
	float spawnDuration{ 0.f };
};