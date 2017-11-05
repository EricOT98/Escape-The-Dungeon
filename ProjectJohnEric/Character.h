/// <summary>
/// @author: Eric O' Toole, John O' Meara
/// date: 17/10/2017
/// </summary>

#ifndef CHARACTER
#define CHARACTER

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class Character
{
public:
	Character();
	Character(string name);

	virtual string getName();
	virtual void render(sf::RenderWindow &window);
	virtual void update();
	virtual void init();
	virtual void applyForce(sf::Vector2f direction);

protected:
	string m_name;
	sf::RectangleShape m_rect;
	sf::Texture m_texture;
	sf::Sprite m_sprite;

	float m_rotation;
	float m_spinSpeed;

	sf::Vector2f m_position;
	sf::Vector2f m_velocity;

	sf::Vector2f m_direction; // direction to move towards, seperate to rotation

	float m_acceleration;
	float m_moveSpeed;
	float m_maxSpeed;
};

#endif !CHARACTER