#ifndef INTERACTABLE_H
#define INTERACTABLE_H

#include <SFML/Graphics.hpp>
#include "Tile.h"

struct Key {
	Tile* m_tile;
	bool m_active = true;
};

struct Door {
	std::vector<Tile*> m_tiles;
	float m_radius = 16;
	sf::Vector2f m_centre;
};

#endif // !INTERACTABLE_H

