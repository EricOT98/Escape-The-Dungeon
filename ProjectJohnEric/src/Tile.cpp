#include "Tile.h"

#include <iostream>

Tile::Tile(sf::Texture * tex, int x, int y, int tx, int ty, int w, int h, int gid, int layer)
	: m_x(x), m_y(y), m_tx(tx), m_ty(ty), m_w(w), m_h(h), m_gid(gid), m_layer(layer)
{
	{
		m_texture = tex;
		//Initialise the texture to be the sprite at that spritesheet position
		m_sprite.setTexture(*m_texture);
		m_sprite.setTextureRect(sf::IntRect(m_tx, m_ty, m_w, m_h));
		m_sprite.setPosition(m_x, m_y);

		size = sf::Vector2f(m_x, m_y);
		rect.setSize(size);
		rect.setPosition(m_x, m_y);
		rect.setOutlineThickness(2);
		rect.setFillColor(sf::Color::Red);
		rect.setOutlineColor(sf::Color::Yellow);
	}
}

void Tile::draw(sf::RenderWindow & window)
{
	//if (withinViewBounds(sf::FloatRect(0, 000, 200, 200))) {
		//window.draw(rect);
		window.draw(m_sprite);
		//std::cout << m_gid << std::endl;
	//}
}

bool Tile::withinViewBounds(const sf::FloatRect & bounds)
{
	return !(m_x + m_w < bounds.left ||
		m_x > bounds.left + bounds.width ||
		m_y + m_h < bounds.top ||
		m_y < bounds.top + bounds.height);
}
