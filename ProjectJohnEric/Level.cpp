#include "Level.h"

Level::Level()
{
	
}

bool Level::load(std::string & filepath)
{
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
		int layerCount = 0;
		for (auto & layer : map_layers) {
			if (layerCount < 4) {
				//If not drawable type skip it
				if (layer->getType() != tmx::Layer::Type::Tile)
					continue;

				auto* tile_layer = dynamic_cast<const tmx::TileLayer*>(layer.get());

				//get all the tiles in the current tile layer.
				auto & layer_tiles = tile_layer->getTiles();
				//@debug
				//std::cout << "Got all tiles" << std::endl;

				//For every tile at poistion do something
				for (auto y = 0; y < m_rows; ++y) {
					for (auto x = 0; x < m_cols; ++x) {
						int tile_index = x + (y * m_cols);

						//get the gid of the current tile
						uint32_t cur_gid = layer_tiles[tile_index].ID;
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
								break;
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
							region_x, region_y, m_tileWidth, m_tileHeight);
						m_tiles.push_back(t);
						//@debug
						//std::cout << "added tile to the level tiles" << std::endl;
					}
				}
			}
			layerCount++;
		}
		return true;
	}
	return false;
}

void Level::render(sf::RenderWindow & window)
{
	for (auto & tile : m_tiles) {
		tile->draw(window);
	}
	std::cout << "render cycle " << std::endl;
}