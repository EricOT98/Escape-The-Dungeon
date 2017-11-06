#ifndef CAMERA_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Camera
{
public:
	Camera();
	Camera(sf::Vector2f playerPos);

	void init();
	void update(sf::Vector2f playerPos);

	sf::View m_view;

private:
	

	sf::Vector2f m_position;

	sf::FloatRect m_playerBoundary;

};

#endif !CAMERA_H
