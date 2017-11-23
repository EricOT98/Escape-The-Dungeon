#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
#include <tmxlite\Map.hpp>
#include <SFML\Graphics.hpp>
#include "Tile.h"
#include "Object.h"
#include "Player.h"

class Level {
public:
	Level();
	bool load(std::string & filepath, Player* player);

	void render(sf::RenderWindow & window);
	void update();

protected:
	Player * m_player;

	tmx::Map m_map;
	std::map<uint32_t, sf::Texture *> m_tilesets;
	std::vector<sf::Texture *> m_tileset_textures;
	std::string m_filepath;
	tmx::Vector2u m_tileCount;
	tmx::Vector2u m_tileSize;
	std::vector<Tile *> m_tiles;
	std::vector<Object *> m_levelObjects;

	int m_rows, m_cols;
	int m_tileWidth, m_tileHeight;

	void parseTMXMap(tmx::Map & map);
	void parseTMXTileLayer(const std::unique_ptr<tmx::Layer> & layer, int layerNum);
	void parseTMXObjectLayer(const std::unique_ptr<tmx::Layer> & layer, int layerNum);

	bool checkCollisions(Tile* t, Character* c);
};

#endif //!LEVEL
