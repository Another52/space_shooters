#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>

class TextureManager {
public:
    TextureManager();
    const sf::Texture& GetTexture(const std::string& filename);
private:
    sf::Texture fallbackTex;
    std::unordered_map<std::string, sf::Texture> Textures;
};