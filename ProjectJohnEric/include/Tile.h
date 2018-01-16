#ifndef TILE_H
#define TILE_H
#include <SFML\Graphics.hpp>
#include <tmxlite\TileLayer.hpp>

class Tile {
public:
	//world coordinates
	int m_x, m_y;
	//Coordinates on sprite sheet
	int m_tx, m_ty;
	//width and height of the tile
	int m_w, m_h;
	//Layer of the tile
	int m_layer;

	//The tiles gid in the tilesheet
	int m_gid;	//TODO: Eric use this for tile comparisons for game events

	//Used for controlled culling of the tiles
	bool m_onScreen;

	

	sf::Texture * m_texture;
	sf::Sprite  m_sprite;
	sf::RectangleShape rect;
	sf::Vector2f size;
	Tile(sf::Texture * tex, int x, int y, int tx, int ty, int w, int h,int gid,int layer);

	void draw(sf::RenderWindow & window);
	void draw(sf::RenderWindow & window, int i);

	bool withinViewBounds(const sf::FloatRect & bounds);

};

#endif //!TILE_H
