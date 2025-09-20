#include "Camera.hpp"
#include <iostream>

Camera::Camera(float zoomlevel, sf::RenderWindow& window)
    : zoomLevel(zoomlevel)
{
    Update(window.getSize());
    window.setView(view);
}

void Camera::Update(sf::Vector2u windowSize)
{
    float aspect = static_cast<float>(windowSize.x) / static_cast<float>(windowSize.y);
    sf::Vector2f size;

    if (aspect < 1.f)
        size = sf::Vector2f(zoomLevel, zoomLevel / aspect);
    else
        size = sf::Vector2f(zoomLevel * aspect, zoomLevel);

    view.setSize(size);
}

void Camera::Follow(Entity& player, float deltatime, bool lerp)
{
    if (!lerp)
    {
        currentCenter = player.GetSprite().getPosition();
        view.setCenter(currentCenter);
        return;
    }
    sf::Vector2f target = player.GetSprite().getPosition();

    currentCenter += (target - currentCenter) * followSpeed * deltatime;
    view.setCenter(currentCenter);
}

const sf::View& Camera::GetView() const
{
    return view;
}