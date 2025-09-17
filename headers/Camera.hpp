#pragma once

#include<SFML/Graphics.hpp>

class Camera
{
public:
	Camera(float zoomlevel) : zoomLevel(zoomlevel) {}
	sf::View GetView(sf::Vector2u windowSize);
private:
	float zoomLevel;
};