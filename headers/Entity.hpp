#pragma once

#include <SFML/Graphics.hpp>
#include "TextureManager.hpp"

class Entity
{
public:
	Entity(TextureManager& texManager);
	virtual void Update(float dt);
	void Draw(sf::RenderWindow& window) const;
	sf::Vector2f GetPos() { return sprite.getPosition(); }
private:
	sf::Sprite sprite;
	float speed{100.f};
	//const sf::Texture& tex;
};