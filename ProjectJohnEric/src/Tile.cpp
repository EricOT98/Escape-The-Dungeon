#include "Tile.h"

#include <iostream>

Tile::Tile(sf::Texture * tex, int x, int y, int tx, int ty, int w, int h, int gid, int layer)
	: m_x(x), m_y(y), m_tx(tx), m_ty(ty), m_w(w), m_h(h), m_gid(gid), m_layer(layer)
{
	m_texture = tex;
	//Initialise the texture to be the sprite at that spritesheet position
	m_sprite.setTexture(*m_texture);
	m_sprite.setTextureRect(sf::IntRect(m_tx, m_ty, m_w, m_h));
	m_sprite.setPosition(m_x, m_y);

	size = sf::Vector2f(m_w, m_h);
	rect.setSize(size);
	rect.setPosition(m_x, m_y);
	//rect.setFillColor(sf::Color(255,0,0,50));
	rect.setOutlineColor(sf::Color::Yellow);

	//Needs to be white for lighting to work properly(can be grey too i think)
	rect.setFillColor(sf::Color(255, 255, 255));

	m_block.fRect.left = m_x;
	m_block.fRect.top = m_y;

	m_block.setSize(rect.getSize());

	m_seen = false;
}

void Tile::draw(sf::RenderTarget & targ)
{
	targ.draw(m_sprite);
}

void Tile::draw(sf::RenderTarget & targ, int i)
{
	targ.draw(rect);
}

void Tile::setOccluding(bool occluding = false)
{
	m_block.allowBlock = occluding;
}



bool Tile::withinViewBounds(const sf::FloatRect & bounds)
{
	return !(m_x + m_w < bounds.left ||
		m_x > bounds.left + bounds.width ||
		m_y + m_h < bounds.top ||
		m_y < bounds.top + bounds.height);
}
