#include "Background.hpp"
#include <iostream>

Background::Background(TextureManager& texManager,
					   const sf::Sprite& player, const std::string& filename)
	:
	texture(texManager.GetTexture(filename)),
	player(player)
{
	sprites.reserve(9);

	constexpr float scaleFactor = 1.5f;
	constexpr float offset = 1.0f;
	constexpr sf::Vector2f scale(scaleFactor, scaleFactor);
	const float spriteWidth = texture.getSize().x * scale.x;
	const sf::Vector2f center = player.getPosition();
	int num = 1;

	for (int i = -num; i <= num; ++i)
	{
		for (int j = -num; j <= num; j++)
		{
			sf::Sprite sprite(texture);
			sprite.setScale(scale);
			sprite.setOrigin(sprite.getLocalBounds().getCenter());
			sprite.setPosition({ center.x + i * (spriteWidth * offset), center.y + j * (spriteWidth * offset) });
			sprites.push_back(sprite);
		}
	}
}

void Background::Update(const sf::View& view)
{
	const sf::Vector2f center = view.getCenter();
	const float spriteWidth = texture.getSize().x;

	for (int y = -1; y <= 1; ++y)
	{
		for (int x = -1; x <= 1; ++x)
		{
			int index = (y + 2) * (x + 1);
			auto& sprite = sprites.at(index);
		}
	}
}

void Background::Draw(sf::RenderWindow& window)
{
	for (auto& sprite : sprites)
	{
		window.draw(sprite);
	}
}