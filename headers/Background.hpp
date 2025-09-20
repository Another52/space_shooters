#pragma once

#include <SFML/Graphics.hpp>
#include "TextureManager.hpp"
#include <vector>
#include <string>

class Background
{
public:
	Background(TextureManager& texManager, const sf::Sprite& player, const std::string& filename, float spriteScale = 1.f);
	void Update(const sf::View& view);
	void Draw(sf::RenderWindow& window);
private:
	void MoveAllSprites(sf::Vector2f offset);
private:
	float spriteScale{};
	bool done = false;
	const sf::Texture& texture;
	const sf::Sprite& player;
	std::vector<sf::Sprite> sprites;
};