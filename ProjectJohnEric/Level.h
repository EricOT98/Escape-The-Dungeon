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

	sf::Texture * m_texture;
	sf::Sprite  m_sprite;
	sf::RectangleShape rect;
	sf::Vector2f size;
	Tile(sf::Texture * tex, int x, int y, int tx, int ty, int w, int h)
		: m_x(x), m_y(y), m_tx(tx), m_ty(ty), m_w(w), m_h(h)
	{
		m_texture = tex;
		//Initialise the texture to be the sprite at that spritesheet
		m_sprite.setTexture(*m_texture);
		m_sprite.setTextureRect(sf::IntRect(m_tx, m_ty, m_w, m_h));
		m_sprite.setPosition(m_x, m_y);
		
		size = sf::Vector2f(m_x, m_y);
		rect.setSize(size);
		rect.setPosition(m_x, m_y);
		rect.setOutlineThickness(2);
		rect.setFillColor(sf::Color::Red);
		rect.setOutlineColor(sf::Color::Yellow);
		//rect.setTexture(m_texture);
		//rect.setTextureRect(sf::IntRect(m_tx, m_ty, m_w, m_h));
	}

	void draw(sf::RenderWindow & window) {
		//window.draw(rect);
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
