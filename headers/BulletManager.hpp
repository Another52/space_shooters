#pragma once

#include "SFML/Audio.hpp"
#include "Entity.hpp"
#include "Bullet.hpp"
#include <vector>
#include <memory>
#include <string>

class BulletManager
{
public:
	BulletManager(const Entity& player, const sf::RenderWindow& window,
				  TextureManager& texManager, std::string filename, sf::IntRect rectangle);
	void Add();
	void Update(float deltatime);
	void Draw(sf::RenderWindow& window);
	void Collide(Entity& entity);
private:
	std::vector<std::unique_ptr<Bullet>> bullets;
	const Entity& player;
	const sf::RenderWindow& window;
	TextureManager& texManager;
	std::string filename;
	sf::IntRect rectangle;
	sf::Music shoot;
};