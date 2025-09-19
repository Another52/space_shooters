#pragma once

#include "Entity.hpp"

class Player : public Entity
{
public:
	Player(const sf::RenderWindow& window, TextureManager& texManager, const std::string& filename, const sf::IntRect& rect);
	void Update(float dt) override;
private:

};