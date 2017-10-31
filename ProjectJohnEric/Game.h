#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>
#include "Character.h"
#include "KeyboardHandler.h"
#include <tmxlite\TileLayer.hpp>
#include <tmxlite\SFMLOrthogonalLayer.hpp>
#include "Level.h"

class Game
{
public:
	Game();
	~Game();

	void run();

private:

	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();

	sf::RenderWindow m_window; // main SFML window
	bool m_exitGame; // control exiting game
	Character m_character;
	KeyboardHandler * m_keyHandler;
	//tmx::Map m_map;
	//std::vector<MapLayer*> m_layers;
	Level m_level;
};

#endif // !GAME

