/// <summary>
/// @author Eric O' Toole, John O' Meara
/// @desc The core functionality of the game
/// timetaken: 3o hours(very rough approximaion)
///
/// </summary>

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Player.h"
#include "Camera.h"
#include "KeyboardHandler.h"
#include <tmxlite\TileLayer.hpp>
#include "Level.h"
#include "../Input/Xbox360Controller.h"
#include "../Menu/MenuHandler.h"
#include "../Lights/LightEngine.h"
#include "Thor\Resources.hpp"

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

	bool initialiseMenus();

	sf::RenderWindow m_window; // main SFML window
	bool m_exitGame; // control exiting game

	Player m_player;

	KeyboardHandler * m_keyHandler;
	Level m_level;
	Camera m_camera;
	sf::Texture m_testTexture;
	sf::Sprite m_testSprite;
	std::vector<Xbox360Controller> m_controllers;
	MenuStates m_menuStates;
	MenuHandler m_menuHandler;

	Level m_levels[2];
	//Menu objects if using predefined menus to be stroed in header

	sf::CircleShape m_debug;

	////TODO: Eric Lights
	LightEngine m_lightEngine;
	//LightEngine le;
	Block block;
	Light light;
	sf::CircleShape debugCirc;
};

#endif // !GAME
