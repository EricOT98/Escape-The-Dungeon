/// <summary>
/// @author: eric O' Toole
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
	virtual void init();
	virtual void applyForce(sf::Vector2f direction);
protected:
	string m_name;
	sf::RectangleShape m_rect;
	sf::Texture m_texture;
	sf::Sprite m_sprite;

	sf::Vector2f m_position;
	sf::Vector2f m_velocity;
	sf::Vector2f m_acceleration;
};
#endif !CHARACTER
