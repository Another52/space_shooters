#include "Bullet.hpp"
#include <iostream>

Bullet::Bullet(const Entity& obj, const sf::RenderWindow& window,
			   TextureManager& texManager, const std::string& filename, sf::IntRect& rectangle)
	:
	Entity(window, texManager, filename, rectangle)
{
	damage = obj.GetDamage();

	sprite.setPosition(obj.GetSprite().getPosition());
	sprite.setRotation(obj.GetSprite().getRotation());

	auto mousePos = static_cast<sf::Vector2f>(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
	dir = (mousePos - obj.GetSprite().getPosition()).normalized();
}

void Bullet::Update(float deltatime)
{
	sprite.move(dir * speed * deltatime);
	
	if (spawnDuration > lifetime)
	{
		dead = true;
	}
	spawnDuration += deltatime;
}