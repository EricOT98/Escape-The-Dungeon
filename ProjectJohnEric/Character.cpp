#include "Character.h"

/// <summary>
/// Default character constructor
/// </summary>
Character::Character()
{
}

/// <summary>
/// Charcater constructor that sets a name
/// </summary>
/// <param name="name">Name of the character for testing</param>
Character::Character(string name)
	: m_name(name),
	m_acceleration(0.5),
	m_maxSpeed(10),
	m_spinSpeed(0.7)
{

}

/// <summary>
/// Return the characters name
/// </summary>
/// <returns>Name of the character</returns>
string Character::getName()
{
	return m_name;
}

void Character::render(sf::RenderWindow &window)
{
	m_rect.setPosition(m_position);
	m_rect.setRotation(m_rotation);
	window.draw(m_rect);
}

void Character::update()
{

}

void Character::init()
{
	if (m_texture.loadFromFile("File.png")) {
		m_sprite.setTexture(m_texture);
	}
	else {
		std::cout << "ERROR: LOADING FILENAME:" << std::endl;
	}
	m_rect.setSize(sf::Vector2f(100, 100));
	m_rect.setOrigin(50, 50);
	m_rect.setFillColor(sf::Color::Black);
	m_rect.setPosition(m_position);
}

void Character::applyForce(sf::Vector2f direction)
{
	//m_acceleration = direction;
}


