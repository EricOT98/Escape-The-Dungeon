#include "Block.h"

Block::Block() : fRect(0, 0, 0, 0), allowBlock(false), col(255, 0, 0, 255)

{
	m_rectShape.setPosition(fRect.left, fRect.top);
	m_rectShape.setSize(sf::Vector2f(fRect.width, fRect.height));
	m_rectShape.setFillColor(col);
	m_rectShape.setOrigin(fRect.width / 2, fRect.height / 2);
}

void Block::setAllowed(bool allowed)
{
	allowBlock = allowed;
}

void Block::render(sf::RenderWindow & window)
{
	window.draw(m_rectShape);
}

void Block::setSize(sf::Vector2f size)
{
	m_rectShape.setSize(size);
	fRect.width = size.x;
	fRect.height = size.y;
	m_rectShape.setOrigin(0, 0);
}

void Block::setPosition(sf::Vector2f pos)
{
	fRect.left = pos.x;
	fRect.top = pos.y;
	m_rectShape.setPosition(pos);
}
