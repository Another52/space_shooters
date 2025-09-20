#include "Enemy.hpp"
#include <iostream>

Enemy::Enemy(const sf::Sprite& player, const sf::RenderWindow& window,
			 TextureManager& texManager, const std::string& filename, sf::IntRect& rectangle)
	:
	Entity(window, texManager, filename, rectangle),
	player(player)
{
	sprite.setPosition(GetOffScreenPos());
}

void Enemy::Update(float deltatime)
{
	//std::cout << sprite.getPosition().x << sprite.getPosition().y << std::endl;
	//get direction to enemy and normalize it
	sf::Vector2f targetDir = player.getPosition() - sprite.getPosition();
	targetDir = (targetDir.lengthSquared() > 0.f)
		? targetDir / std::sqrt(targetDir.lengthSquared())
		: sf::Vector2f{ 0.f, -1.f };

	currentDir += (targetDir - currentDir) * rotSmoothing * deltatime;

	sprite.setRotation(currentDir.angle());
	sprite.rotate(sf::radians(PI / 2));
	sprite.move(currentDir * speed * deltatime);

	if (sprite.getGlobalBounds().findIntersection(player.getGlobalBounds()))
	{
		//dead = true;
	}
	if (health <= 0)
	{
		dead = true;
	}
}

sf::Vector2f Enemy::GetOffScreenPos()
{
	const sf::View view = window.getView();
	
	//
	const sf::Vector2f padding = sprite.getLocalBounds().size / 2.f;
	const sf::Vector2f center = view.getCenter();
	constexpr sf::Vector2f margin{10.f, 10.f};
	const sf::Vector2i size = static_cast<sf::Vector2i>(view.getSize());
	const sf::Vector2f halfSize = view.getSize() / 2.f;

	sf::Vector2f left = { center.x - halfSize.x - padding.x - margin.x, float(rand() % size.y) };
	sf::Vector2f right = { center.x + halfSize.x + padding.x + margin.x, float(rand() % size.y) };
	sf::Vector2f top = { float(rand() % size.x), center.y - halfSize.y - padding.y - margin.y };
	sf::Vector2f bottom = { float(rand() % size.x), center.y + halfSize.y + padding.y + margin.y };

	int side = std::rand() % 4;
	switch (side)
	{
		case 0:
			return top;
		case 1:
			return bottom;
		case 2:
			return left;
		case 3:
			return right;
		default:
			return right;
	}
}