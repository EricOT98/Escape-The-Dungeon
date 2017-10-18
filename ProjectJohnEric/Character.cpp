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
	: m_name(name)
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
	window.draw(m_rect);
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
	m_rect.setFillColor(sf::Color::Black);
	m_rect.setPosition(sf::Vector2f(200, 200));
}

void Character::applyForce(sf::Vector2f direction)
{
	m_acceleration = direction;
}


