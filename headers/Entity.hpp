#pragma once

#include <SFML/Graphics.hpp>
#include "MyUtils.h"
#include "TextureManager.hpp"
#include <string>

class Entity
{
public:
	Entity(const sf::RenderWindow& window, TextureManager& texManager,
		   const std::string& filename, const sf::IntRect& rectangle);

	virtual void Update(float dt) = 0;
	virtual void Draw(sf::RenderWindow& window) const;
	bool Collision(Entity& other);
	virtual void TakeDamage(int damage);
	const sf::Sprite& GetSprite() const { return sprite; }
	bool IsDead() const { return dead; }
	void MarkDead() { dead = true; }
	int GetDamage() const { return damage; };
public:
	bool active{true};
protected:
	sf::Sprite sprite;
	const sf::RenderWindow& window;
	float speed{100.f};
	bool dead{ false };
	int maxHealth{ 100 };
	int health{ 100 };
	int damage{ 5 };
};