#include "Block.h"

Block::Block() : fRect(0, 0, 0, 0), allowBlock(false), col(255, 0, 0, 255)

{
	m_rectShape.setPosition(fRect.top, fRect.left);
	m_rectShape.setSize(sf::Vector2f(fRect.width, fRect.height));
	m_rectShape.setFillColor(col);
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
}
