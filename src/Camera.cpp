#include "Camera.hpp"

void Camera::Update(sf::Vector2u windowSize)
{
    float aspect = static_cast<float>(windowSize.x) / static_cast<float>(windowSize.y);
    sf::Vector2f size;

    if (aspect < 1.f)
        size = sf::Vector2f(zoomLevel, zoomLevel / aspect);
    else
        size = sf::Vector2f(zoomLevel * aspect, zoomLevel);

    view.setSize(size);
    view.setCenter({ 0.f, 0.f });
    currentCenter = sf::Vector2f(0.f, 0.f);
}

void Camera::Follow(Entity& player, float deltatime)
{
    sf::Vector2f target = player.GetPos();

    currentCenter += (target - currentCenter) * followSpeed * deltatime;
    view.setCenter(currentCenter);
}

const sf::View& Camera::GetView() const
{
    return view;
}