#include "Background.hpp"
#include <iostream>

Background::Background(TextureManager& texManager,
					   const sf::Sprite& player, const std::string& filename, float spriteScale)
	:
	texture(texManager.GetTexture(filename)),
	player(player),
	spriteScale(spriteScale)
{
	sprites.reserve(9);
	constexpr float offset = 1.f;
	const sf::Vector2f scale(spriteScale, spriteScale);
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
	const float spriteSide = texture.getSize().x * spriteScale;
	const auto playerPos = player.getPosition();
	const auto midsprite = sprites[4].getPosition();
	
	if (playerPos.x < (midsprite.x - spriteSide))
	{
		MoveAllSprites({ -spriteSide, 0 });
	}
	if (playerPos.x > (midsprite.x + spriteSide))
	{
		MoveAllSprites({ spriteSide, 0 });
	}
	if (playerPos.y < (midsprite.y - spriteSide))
	{
		MoveAllSprites({ 0, -spriteSide });
	}
	if (playerPos.y > (midsprite.y + spriteSide))
	{
		MoveAllSprites({ 0, spriteSide});
	}
}

void Background::Draw(sf::RenderWindow& window)
{
	for (auto& sprite : sprites)
	{
		window.draw(sprite);
	}
}

void Background::MoveAllSprites(sf::Vector2f offset)
{
	for (auto& sprite : sprites)
	{
		sprite.move(offset);
	}
}