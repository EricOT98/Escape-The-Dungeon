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

	sf::CircleShape m_DEBUGCIRCLE;

	Character();
	Character(string name);

	virtual string getName();
	virtual float getRadius();

	virtual void render(sf::RenderWindow &window);
	virtual void update();
	virtual void init();

	virtual void applyForce(sf::Vector2f direction); // needed?
	virtual void move();
	//virtual void push();

	sf::Vector2f getPosition(){
		return m_position;
	}

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

	bool m_moving;
	float m_acceleration;
	float m_moveSpeed;
	float m_maxSpeed;

	float m_collisionRadius;
};

#endif !CHARACTER