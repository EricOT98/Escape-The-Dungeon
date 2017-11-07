#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Player.h"
#include "Camera.h"
#include "KeyboardHandler.h"
#include <tmxlite\TileLayer.hpp>
#include <tmxlite\SFMLOrthogonalLayer.hpp>
#include "Level.h"
#include "Xbox360Controller.h"
#include "../GUI//MainMenu.h"

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

	Player m_player;

	KeyboardHandler * m_keyHandler;
	Level m_level;
	Camera m_camera;
	sf::Texture m_testTexture;
	sf::Sprite m_testSprite;
	std::vector<Xbox360Controller> m_controllers;
	MainMenu m_mainMenu;

	enum class GameStates
	{
		SPLASH,
		LICENSE,
		MAIN_MENU,
		GAME,
		OPTIONS,
		PAUSE,
		GAMEOVER,
		CREDITS
	};

	GameStates m_gameStates;
	std::vector<std::unique_ptr<Menu>> m_menus;

};

#endif // !GAME
