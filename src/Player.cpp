#include "Player.hpp"
#include <iostream>

Player::Player(const sf::RenderWindow& window, TextureManager& texManager,
			   const std::string& filename, const sf::IntRect& rect)
	:
	Entity(window, texManager, filename, rect)
{
	damage = 5;
}

void Player::Update(float dt)
{
	//LookAt
	sf::Vector2f mouse_pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
	sf::Vector2f dir = (mouse_pos - sprite.getPosition()).normalized();
	sprite.setRotation(sf::radians(std::atan2(dir.y, dir.x) - 80));


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
