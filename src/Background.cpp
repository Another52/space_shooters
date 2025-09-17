#include "Background.hpp"

Background::Background(TextureManager& texManager, const std::string& filename)
	:
	texture(texManager.GetTexture(filename))
{
	sprites.reserve(9);
}

void Background::Update(const Camera& camera)
{
	
}

void Background::Draw(sf::RenderWindow& window) const
{
	for (auto& sprite : sprites)
	{
		window.draw(sprite);
	}
}