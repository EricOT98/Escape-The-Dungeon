#include "Camera.h"

Camera::Camera()
{
}

Camera::Camera(sf::Vector2f playerPos)
	: m_position(playerPos)
{
	init();
}

void Camera::init()
{
	m_view.setSize(sf::Vector2f(800, 800));
	m_view.zoom(0.2);
}

void Camera::update(sf::Vector2f playerPos)
{
	m_view.setCenter(playerPos);
}
