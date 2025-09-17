#include "Camera.hpp"

sf::View Camera::GetView(sf::Vector2u windowSize)
{
	float aspect = float(windowSize.x) / float(windowSize.y);
	sf::Vector2f size;
	if (aspect < 1.f)
		size = sf::Vector2f(zoomLevel, zoomLevel / aspect);
	else
		size = sf::Vector2f(zoomLevel * aspect, zoomLevel);

	return sf::View(sf::Vector2f(0.f, 0.f), size);
}