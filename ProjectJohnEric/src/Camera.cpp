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
	m_zone = 50;
	m_view.setSize(sf::Vector2f(800, 800));
	m_view.zoom(0.2);

	m_TESTCAMERAZONE.setOrigin(m_zone, m_zone);
	m_TESTCAMERAZONE.setPosition(m_view.getCenter());
	m_TESTCAMERAZONE.setRadius(m_zone);
	m_TESTCAMERAZONE.setFillColor(sf::Color(0, 255, 255, 100));

	m_weight = 0.1;
	m_shake = 0.1;
	m_maxAngle = 0.5;
	m_maxOffset = 1;
}

void Camera::update()
{
	sf::Vector2f playerPos = m_player->getPosition();
	float playerRotation = m_player->getRotation();

	//x += cos(angle*pi)*dist
	//y += sin(angle*pi)*dist

	std::cout << playerRotation << std::endl;

	// --------------------------
	playerPos.x += cos(playerRotation*acos(-1) / 180) * m_viewOffset;
	playerPos.y += sin(playerRotation*acos(-1) / 180) * m_viewOffset;

	m_TESTCAMERAZONE.setPosition(playerPos);
	//playerPos = m_player->getPosition();

	//---------------------------
	m_position.x += (playerPos.x - m_position.x)*m_weight;
	m_position.y += (playerPos.y - m_position.y)*m_weight;

	m_outputCentre = m_position;
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
	if (KeyboardHandler::GetInstance()->KeyDown(sf::Keyboard::LShift))
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