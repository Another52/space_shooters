#pragma once

#include <SFML/Graphics.hpp>
#include "TextureManager.hpp"
#include <vector>
#include <string>

class Background
{
public:
	Background(TextureManager& texManager, const sf::Sprite& player, const std::string& filename);
	void Update(const sf::View& view);
	void Draw(sf::RenderWindow& window);
private:
	bool done = false;
	const sf::Texture& texture;
	const sf::Sprite& player;
	std::vector<sf::Sprite> sprites;
};