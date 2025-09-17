#include "Entity.hpp"

Entity::Entity(TextureManager& texManager)
	:
	sprite(texManager.GetTexture("spaceShip\\stitchedFiles\\spaceships_c.png"))
{
	sprite.setTextureRect(sf::IntRect({ 0, 0 }, { 16, 16 }));
}

void Entity::Update(float dt)
{
	//Keyboard Movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		sprite.move(sf::Vector2f(0.f, -1.f) * speed * dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		sprite.move(sf::Vector2f(0.f, 1.f) * speed * dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		sprite.move(sf::Vector2f(-1.f, 0.f) * speed * dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		sprite.move(sf::Vector2f(1.f, 0.f) * speed * dt);
	}
}

void Entity::Draw(sf::RenderWindow& window) const
{
	window.draw(sprite);
}
