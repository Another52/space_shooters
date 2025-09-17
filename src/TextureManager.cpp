#include "TextureManager.hpp"
#include <iostream>

TextureManager::TextureManager()
	:
	fallbackTex {sf::Image{{10u, 10u}, sf::Color::Magenta}} 
{}

const sf::Texture& TextureManager::GetTexture(const std::string& filename)
{
	//Return if available
	auto tex = Textures.find(filename);
	if (tex != Textures.end())
		return tex->second;

	//Get the texture
	sf::Texture texture;
	if (!texture.loadFromFile(RESOURCES_PATH + filename))
	{
		return fallbackTex;
	}
	Textures[filename] = std::move(texture);
	return Textures[filename];
}