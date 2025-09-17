#pragma once

#include <SFML/Graphics.hpp>
#include "TextureManager.hpp"
#include "Camera.hpp"
#include <vector>
#include <string>

class Background
{
public:
	Background(TextureManager& texManager, const std::string& filename);
	void Update(const Camera& camera);
	void Draw(sf::RenderWindow& window) const;
private:
	const sf::Texture& texture;
	std::vector<sf::Sprite> sprites;
};