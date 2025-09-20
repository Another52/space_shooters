#include "Entity.hpp"

Entity::Entity(const sf::RenderWindow& window, TextureManager& texManager,
			   const std::string& filename, const sf::IntRect& rectangle)
	:
	sprite(texManager.GetTexture(filename)),
	window(window)
{
	sprite.setTextureRect(rectangle);
	sprite.setOrigin(sprite.getLocalBounds().getCenter());
}

void Entity::Draw(sf::RenderWindow& window) const
{
	window.draw(sprite);
}

bool Entity::Collision(Entity& other)
{
	const sf::Sprite& obj = other.GetSprite();

	if (sprite.getGlobalBounds().findIntersection(obj.getGlobalBounds()))
	{
		return true;
	}

	return false;
}