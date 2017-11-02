#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
#include <tmxlite\Map.hpp>
#include <tmxlite\ImageLayer.hpp>
#include <tmxlite\Tileset.hpp>
#include <tmxlite\TileLayer.hpp>
#include <SFML\Graphics.hpp>
#include "Tile.h";

class Level {
public:
	Level();
	bool load(std::string & filepath);

	void render(sf::RenderWindow & window);


protected:
	tmx::Map m_map;
	std::map<uint32_t, sf::Texture *> m_tilesets;
	std::vector<sf::Sprite> m_tileSprites;
	std::vector<sf::Texture *> m_tileset_textures;
	std::string m_filepath;
	tmx::Vector2u m_tileCount;
	tmx::Vector2u m_tileSize;
	std::vector<Tile *> m_tiles;

	int m_rows, m_cols;
	int m_tileWidth, m_tileHeight;

};

#endif //!LEVEL
