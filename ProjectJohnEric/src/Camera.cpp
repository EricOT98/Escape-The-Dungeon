#include "Camera.h"

Camera::Camera()
{
}

Camera::Camera(Player* player)
	: m_player(player)
{
	init();
}

void Camera::init()
{
	m_menuView.reset(sf::FloatRect(0, 0, 1080, 720));
	m_view.setSize(sf::Vector2f(1080, 720));
	m_zoom = 0.3;
	m_view.zoom(m_zoom);
	

	m_miniMap.setViewport(sf::FloatRect(0.1, 0.7, 0.3, 0.3));
	m_weight = 0.1;
	m_shake = 0.1;
	m_maxAngle = 0.5;
	m_maxOffset = 1;
}

void Camera::update()
{
	sf::Vector2f playerPos = m_player->getPosition();
	float playerRotation = m_player->getRotation();

	playerPos.x += cos(playerRotation*acos(-1) / 180) * m_viewOffset;
	playerPos.y += sin(playerRotation*acos(-1) / 180) * m_viewOffset;

	m_position.x += (playerPos.x - m_position.x)*m_weight;
	m_position.y += (playerPos.y - m_position.y)*m_weight;

	m_outputCentre = m_position;

	m_view.setCenter(m_position);
	m_view.setRotation(0);


	if (KeyboardHandler::GetInstance()->KeyDown(sf::Keyboard::LControl))
	{
		m_angle = m_maxAngle * m_shake * (((float)rand()) / RAND_MAX * 100.0 - 50.0);

		m_offsetX = m_maxOffset * m_shake * (((float)rand()) / RAND_MAX * 100.0 - 50.0);
		m_offsetY = m_maxOffset * m_shake * (((float)rand()) / RAND_MAX * 100.0 - 50.0);

		m_outputCentre.x += m_offsetX;
		m_outputCentre.y += m_offsetY;
		m_view.setRotation(m_angle);
	}
	if (m_player->getViewForward())
	{
		m_viewOffset = 60;
	}
	else
		m_viewOffset = 25;


	m_view.setCenter(m_outputCentre);
}

void Camera::render(sf::RenderWindow &window)
{
	//window.draw(m_TESTCAMERAZONE);
}

void Camera::pauseTransition()
{
	//float
}
