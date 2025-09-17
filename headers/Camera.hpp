#pragma once

#include<SFML/Graphics.hpp>
#include "Entity.hpp"

class Camera
{
public:
	Camera(float zoomlevel) : zoomLevel(zoomlevel) {}
	
	void Update(sf::Vector2u windowSize);
	void Follow(Entity& player);
	const sf::View& GetView() const;
private:
	float zoomLevel;
	sf::View view;
};