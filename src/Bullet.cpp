#include "Bullet.hpp"
#include <iostream>

Bullet::Bullet(const sf::Sprite& obj, const sf::RenderWindow& window,
			   TextureManager& texManager, const std::string& filename, sf::IntRect& rectangle)
	:
	Entity(window, texManager, filename, rectangle)
{
	sprite.setOrigin(sprite.getLocalBounds().getCenter());
	sprite.setPosition(obj.getPosition());
	sprite.setRotation(obj.getRotation());
	std::cout << obj.getRotation().asDegrees() << std::endl;
	dir = static_cast<sf::Vector2f>(window.mapPixelToCoords(sf::Mouse::getPosition(window))).normalized();
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