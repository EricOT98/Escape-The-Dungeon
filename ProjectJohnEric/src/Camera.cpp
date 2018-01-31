#include "Camera.h"

Camera::Camera()
{
	m_menuView.reset(sf::FloatRect(0, 0, 1080, 720));
	//m_menuView.zoom(1.1);
}

Camera::Camera(sf::Vector2f playerPos)
	: m_position(playerPos)
{
	init();
}

void Camera::init()
{
	m_zone = 50;
	m_view.setSize(sf::Vector2f(800, 800));
	m_view.zoom(0.3);

	m_TESTCAMERAZONE.setOrigin(m_zone, m_zone);
	m_TESTCAMERAZONE.setPosition(m_view.getCenter());
	m_TESTCAMERAZONE.setRadius(m_zone);
	m_TESTCAMERAZONE.setFillColor(sf::Color(0, 255, 255, 100));
}

void Camera::update(sf::Vector2f playerPos)
{
	m_view.setCenter(playerPos);
}

void Camera::render(sf::RenderWindow &window)
{
	//window.draw(m_TESTCAMERAZONE);
}

void Camera::pauseTransition()
{
	//float 
}
