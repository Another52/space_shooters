#include "Background.hpp"

Background::Background(TextureManager& texManager, const std::string& filename)
	:
	texture(texManager.GetTexture(filename))
{
	sf::Sprite sprite(texture);
	sprite.scale({ 0.9f, 0.9f });
	sprite.setOrigin(sprite.getLocalBounds().getCenter());
	sprites.push_back(sprite);
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