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

	if (m_layer == 0){
		rect.setFillColor(sf::Color(255, 255, 255));
	}
	else if (m_layer == 1) {
		rect.setFillColor(sf::Color(255, 255, 255));
	}
	else if (m_layer == 2) {
		rect.setFillColor(sf::Color(255, 255, 255));
	}
	m_block.fRect.left = m_x;
	m_block.fRect.top = m_y;

	m_block.setSize(rect.getSize());
	if (m_layer == 1) {
		m_block.setAllowed(true);
	}
	m_seen = false;
}

void Tile::draw(sf::RenderTarget & targ)
{
	//if (withinViewBounds(sf::FloatRect(0, 000, 200, 200))) {

	targ.draw(m_sprite);
		//window.draw(rect);
		//std::cout << m_gid << std::endl;
	//}
}

void Tile::draw(sf::RenderTarget & targ, int i)
{
	targ.draw(rect);
}



bool Tile::withinViewBounds(const sf::FloatRect & bounds)
{
	return !(m_x + m_w < bounds.left ||
		m_x > bounds.left + bounds.width ||
		m_y + m_h < bounds.top ||
		m_y < bounds.top + bounds.height);
}
