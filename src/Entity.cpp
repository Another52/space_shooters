#include "Entity.hpp"

Entity::Entity(TextureManager& texManager, const std::string& filename, sf::IntRect& rectangle)
	:
	sprite(texManager.GetTexture(filename))
{
	sprite.setTextureRect(rectangle);
}

void Entity::Draw(sf::RenderWindow& window) const
{
	window.draw(sprite);
}
