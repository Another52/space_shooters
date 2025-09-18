#pragma once

#include <SFML/Graphics.hpp>
#include "TextureManager.hpp"
#include <string>

class Entity
{
public:
	Entity(const sf::RenderWindow& window, TextureManager& texManager,
		   const std::string& filename, const sf::IntRect& rectangle);
	virtual void Update(float dt) = 0;
	void Draw(sf::RenderWindow& window) const;
	const sf::Sprite& GetSprite() const { return sprite; }
	bool Collision(Entity& other);
protected:
	sf::Sprite sprite;
	float speed{100.f};
	const sf::RenderWindow& window;
};