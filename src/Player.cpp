#include "Player.hpp"

void Player::Update(float dt)
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
