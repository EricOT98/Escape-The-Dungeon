#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
#include <tmxlite\Map.hpp>
#include <tmxlite\ImageLayer.hpp>
#include <tmxlite\Tileset.hpp>
#include <tmxlite\TileLayer.hpp>
#include <SFML\Graphics.hpp>

class Tile {
public:
	//world coordinates
	int m_x, m_y;
	//Coordinates on sprite sheet
	int m_tx, m_ty;
	//width and height of the tile
	int m_w, m_h;

	sf::Texture & m_texture;
	sf::Sprite  m_sprite;
	Tile(sf::Texture & tex, int x, int y, int tx, int ty, int w, int h)
		: m_texture(tex), m_x(x), m_y(y), m_tx(tx), m_ty(ty), m_w(w), m_h(h)
	{
		//Initialise the texture to be the sprite at that spritesheet
		m_sprite.setTexture(tex);
		m_sprite.setTextureRect(sf::IntRect(m_tx, m_ty, m_w, m_h));
		m_sprite.setPosition(m_x, m_y);
	}

	void draw(sf::RenderWindow & window) {
		window.draw(m_sprite);
	}

};

class Level {
public:
	Level();
	bool load(std::string & filepath);

	void render(sf::RenderWindow & window);


protected:
	tmx::Map m_map;
	std::map<uint32_t, sf::Texture &> m_tilesets;
	std::vector<sf::Sprite> m_tileSprites;
	std::vector<sf::Texture> m_tileset_textures;
	std::string m_filepath;
	tmx::Vector2u m_tileCount;
	tmx::Vector2u m_tileSize;
	std::vector<Tile> m_tiles;

	int m_rows, m_cols;
	int m_tileWidth, m_tileHeight;

};

#endif //!LEVEL
