#pragma once

#include <SFML/Graphics.hpp>
#include "TextureManager.hpp"
#include <string>

class Entity
{
public:
	Entity(TextureManager& texManager, const std::string& filename, sf::IntRect& rectangle);
	virtual void Update(float dt) = 0;
	void Draw(sf::RenderWindow& window) const;
	sf::Vector2f GetPos() { return sprite.getPosition(); }
protected:
	sf::Sprite sprite;
	float speed{100.f};
	//const sf::Texture& tex;
};