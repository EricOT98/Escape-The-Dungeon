#ifndef CAMERA_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "Player.h"

#include "KeyboardHandler.h"

class Camera
{
public:
	Camera();
	Camera(Player* player);

	void init();
	void update();

	sf::View m_view;
	sf::CircleShape m_TESTCAMERAZONE;
	void render(sf::RenderWindow &window);

private:
	KeyboardHandler* m_keyHandler;
	Player* m_player;

	int m_zone;

	sf::Vector2f m_position;
	sf::Vector2f m_outputCentre;

	sf::FloatRect m_playerBoundary;

	int m_viewOffset;
	float m_weight;

	float m_shake;

	float m_angle;
	float m_maxAngle;

	float m_offsetX;
	float m_offsetY;
	float m_maxOffset;
};

#endif !CAMERA_H
