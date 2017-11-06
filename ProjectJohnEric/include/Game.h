#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Player.h"
#include "Camera.h"
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
	void processGameEvents(sf::Event& event);
	void update(sf::Time t_deltaTime);
	void render();

	sf::RenderWindow m_window; // main SFML window
	bool m_exitGame; // control exiting game

	//Character m_character;
	Player m_player;

	KeyboardHandler * m_keyHandler;
	Level m_level;
	Camera m_camera;
	sf::Texture m_testTexture;
	sf::Sprite m_testSprite;
};

#endif // !GAME
