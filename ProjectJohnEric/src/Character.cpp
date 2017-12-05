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
	m_acceleration(0.2),
	m_maxSpeed(2),
	m_spinSpeed(0.7),
	m_collisionRadius(10),
	m_position(50,50)
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

float Character::getRadius()
{
	return m_collisionRadius;
}

void Character::render(sf::RenderWindow &window)
{
	m_rect.setPosition(m_position);
	m_rect.setRotation(m_rotation);

	m_DEBUGCIRCLE.setRadius(m_collisionRadius);
	m_DEBUGCIRCLE.setOrigin(m_collisionRadius, m_collisionRadius);
	m_DEBUGCIRCLE.setPosition(m_position);
	if (m_collisionRadius < 0)
	{
		m_DEBUGCIRCLE.setFillColor(sf::Color(255, 0, 0, 150));
	}
	else
		m_DEBUGCIRCLE.setFillColor(sf::Color(0, 0, 255, 150));

	window.draw(m_rect);
	window.draw(m_DEBUGCIRCLE);
}

void Character::update()
{
	move();
}

void Character::init()
{
	if (m_texture.loadFromFile("File.png")) {
		m_sprite.setTexture(m_texture);
	}
	else {
		std::cout << "ERROR: LOADING FILENAME:" << std::endl;
	}
	m_rect.setSize(sf::Vector2f(16, 16));
	m_rect.setOrigin(m_rect.getSize().x / 2, m_rect.getSize().y / 2);
	m_rect.setFillColor(sf::Color::Black);
	m_rect.setPosition(m_position);

	m_DEBUGCIRCLE.setRadius(m_collisionRadius);
	m_DEBUGCIRCLE.setOrigin(m_collisionRadius, m_collisionRadius);
	m_DEBUGCIRCLE.setFillColor(sf::Color(0, 0, 255, 150));
}

void Character::applyForce(sf::Vector2f direction)
{
	m_position -= direction;
}

/// <summary>
/// Moves the character
/// </summary>
void Character::move()
{
	// should this be a method in the parent class?
	if (m_moving && m_moveSpeed < m_maxSpeed)
	{
		m_moveSpeed += m_acceleration;
		if (m_moveSpeed > m_maxSpeed)
			m_moveSpeed = m_maxSpeed;
	}
	else if (!m_moving && m_moveSpeed > 0)
	{
		m_moveSpeed -= m_acceleration;
		if (m_moveSpeed < 0)
			m_moveSpeed = 0;
	}

	m_position += m_direction * m_moveSpeed;
}


