#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class Enemy : public Entity
{
public:
	Enemy(const sf::Sprite& player, const sf::RenderWindow& window,
		   TextureManager& texManager, const std::string& filename, sf::IntRect& rectangle);
	void Update(float deltatime) override;
private:
	sf::Vector2f GetOffScreenPos();
private:
	const sf::Sprite& player;
	float speed = 80.f;
	float spawnDuration{ 0.f };
	sf::Vector2f currentDir;
};