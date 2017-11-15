#include "Object.h"

Object::Object(sf::Vector2f _pos, sf::FloatRect _rect, bool _visible, bool _trigger) :
	m_position(_pos),
	m_aabb(_rect),
	m_isVisible(_visible),
	m_isTrigger(_trigger)
{
	m_rect.setSize(getSize());
	m_rect.setPosition(_pos);
}

void Object::update()
{
}

void Object::render(sf::RenderWindow & window)
{
	if (m_isVisible) {
		window.draw(m_rect);
	}
}

sf::Vector2f Object::getSize()
{
	return sf::Vector2f(m_aabb.width, m_aabb.height);
}

sf::Vector2f Object::getPosition()
{
	return m_position;
}
