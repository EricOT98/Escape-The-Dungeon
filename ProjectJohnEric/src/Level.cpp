#include "Level.h"
#include <tmxlite\ImageLayer.hpp>
#include <tmxlite\Tileset.hpp>

Level::Level()
{

}

bool Level::load(std::string & filepath, Player* player)
{
	m_player = player;
	if (m_map.load(filepath)) {
		m_tileCount = m_map.getTileCount();
		m_rows = m_tileCount.x;
		m_cols = m_tileCount.y;

		m_tileSize = m_map.getTileSize();
		m_tileWidth = m_tileSize.x;
		m_tileHeight = m_tileSize.y;

		auto & map_tilesets = m_map.getTilesets();
		for (auto & tset : map_tilesets) {
			sf::Texture * tex = new sf::Texture();
			//if the tileset texture is loaded place it into the map with key being gid
			if (tex->loadFromFile(tset.getImagePath())) {
				m_tileset_textures.push_back(tex);
				std::cout << "Path: " << tset.getImagePath() << std::endl;
				m_tilesets.insert(std::pair<uint32_t, sf::Texture *>(tset.getFirstGID(), tex));
			}
			else {
				std::cout << "ERROR: FAILED LOADING TILESET" << tset.getImagePath() << std::endl;
			}

		}

		auto & map_layers = m_map.getLayers();

		int layerNum = -1;
		for (auto & layer : map_layers) {
			layerNum += 1;
			switch (layer->getType()) {
				case tmx::Layer::Type::Tile:
					std::cout << "Tile Layer: " << layerNum << std::endl;
					parseTMXTileLayer(layer, layerNum);
					continue;
				case tmx::Layer::Type::Object:
					std::cout << "Object Layer: " << layerNum << std::endl;
					parseTMXObjectLayer(layer, layerNum);
					continue;
				case tmx::Layer::Type::Image:
					std::cout << "Image Layer" << layerNum++ << std::endl;
					continue;
				default:
					std::cout << "ERROR: FAILED TO LOAD A VALID LAYER AT LAYER: " << layerNum << std::endl;
					continue;
			}
			
		}
		return true;
	}
	return false;
}



void Level::render(sf::RenderWindow & window)
{
	for (auto tile : m_tiles) {
		tile->draw(window);
	}
	for (auto obj : m_levelObjects) {
		obj->render(window);
		//std::cout << "Draw objects" << std::endl;
	}
	//std::cout << "render cycle " << std::endl;
}

void Level::update()
{
	for (auto tile : m_tiles) {
		if (tile->m_layer == 1) {
			checkCollisions(tile, m_player);
		}
	}
}

void Level::parseTMXMap(tmx::Map & map)
{
}

void Level::parseTMXTileLayer(const std::unique_ptr<tmx::Layer> & layer, int layerNum)
{
	auto* tile_layer = dynamic_cast<const tmx::TileLayer*>(layer.get());

	//get all the tiles in the current tile layer.
	auto & layer_tiles = tile_layer->getTiles();
	//@debug
	//std::cout << "Got all tiles" << std::endl;

	//For every tile at poistion do something
	int count = 0;
	for (auto y = 0; y < m_rows; ++y) {
		for (auto x = 0; x < m_cols; ++x) {
			int tile_index = x + (y * m_cols);

			//get the gid of the current tile
			int cur_gid = layer_tiles[tile_index].ID ;
			//std::cout << "cur_gid: " << cur_gid << std::endl;
			//@debug
			//std::cout << "Gid of tile:" << cur_gid << std::endl;

			//GID of 0 is an empty tile so we skip it
			if (cur_gid == 0)
				continue;

			int tset_gid = -1;
			//if a valid tileset is found break
			for (auto & ts : m_tilesets) {
				if (ts.first <= cur_gid) {
					tset_gid = ts.first;
				}
			}

			//if not valid skip the tile
			if (tset_gid == -1)
				continue;
			//Normalize the GID(converts it to a 1 to n range instead of an n to m range)
			cur_gid -= tset_gid;
			//@debug
			//std::cout << "Normalised GID:" << cur_gid << std::endl;

			unsigned int ts_width = m_tilesets.at(tset_gid)->getSize().x;
			unsigned int ts_height = m_tilesets.at(tset_gid)->getSize().y;

			//Calculate the area on the tilesheet to draw
			uint32_t region_x = (cur_gid % (ts_width / m_tileWidth))  * m_tileWidth;
			uint32_t region_y = (cur_gid / (ts_width / m_tileHeight)) * m_tileHeight;

			//Calculate the world position of the tile
			int x_pos = x * m_tileWidth;
			int y_pos = y * m_tileHeight;

			//Finally actually adding the finished tile
			Tile * t = new Tile(m_tilesets.at(tset_gid), x_pos, y_pos,
				region_x, region_y, m_tileWidth, m_tileHeight, cur_gid, layerNum);
			m_tiles.push_back(t);
			//@debug
			//std::cout << "added tile to the level tiles" << std::endl;
		}
	}
}

void Level::parseTMXObjectLayer(const std::unique_ptr<tmx::Layer> & layer, int layerNum)
{
	auto* object_layer = dynamic_cast<const tmx::ObjectGroup*>(layer.get());
	auto & layer_objects = object_layer->getObjects();

	for (auto & object : layer_objects) {
		uint32_t object_uid = object.getUID();
		const tmx::FloatRect object_aabb = object.getAABB();

		sf::Vector2f pos = sf::Vector2f(object.getPosition().x, object.getPosition().y);
		sf::FloatRect rect = sf::FloatRect(object_aabb.left, object_aabb.top, object_aabb.width, object_aabb.height);
		bool trigger = false;
		if (object.getType() == "Trigger") { trigger = true; }
		Object * o = new Object(pos, rect, true, trigger);
		m_levelObjects.push_back(o);
	}
}


/// <summary>
/// Checks collisions between a Character and a Tile
/// </summary>
/// <param name="t">Tile, AABB</param>
/// <param name="c">Character, circle</param>
/// <returns></returns>
bool Level::checkCollisions(Tile* t, Character* c)
{
	// P will be the vertex on the tile that's closest to the collision.
	sf::Vector2f p = c->getPosition();
	// Centre of the cicle, cached for later
	sf::Vector2f cen = p;

	// Finds closest vertex to the possible collision
	if (p.x < t->m_x) {
		p.x = t->m_x;
		// LEFT
	}
	else if (p.x > t->m_x + t->m_w) {
		p.x = t->m_x + t->m_w;
		// RIGHT
	}

	if (p.y < t->m_y) {
		p.y = t->m_y;
		// TOP
	}
	else if (p.y > t->m_y + t->m_h) {
		p.y = t->m_y + t->m_h;
		// BOTTOM
	}

	// Distance between the circle's centre and the point of collision.
	float dist = sqrt((p.x - cen.x)*(p.x - cen.x) + (p.y - cen.y)*(p.y - cen.y));

	if (abs(dist) < c->getRadius())
	{
		std::cout << "COL" << std::endl;
		sf::Color test = c->m_DEBUGCIRCLE.getFillColor();
		c->m_DEBUGCIRCLE.setFillColor(sf::Color(test.r + 10, test.g + 10, test.b + 10));
		return true;
	}
	//c->m_DEBUGCIRCLE.setFillColor(sf::Color::Blue);
	return false;
}