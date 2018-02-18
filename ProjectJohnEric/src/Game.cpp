#include "Game.h"
#include <iostream>
#include "Level.h"
#include "../Menu/MainMenu.h"
#include "../Menu/OptionsMenu.h"
#include "../Menu/SoundOptions.h"
#include "../Menu/DisplayOptions.h"
#include "../Menu/Pause.h"
#include "../Menu/GameOver.h"
#include "ResourceManager.h"

#ifdef _DEBUG
#	define debugMSG(x) x
#else
#	define debugMSG(x)
#endif // DEBUG

/// <summary>
/// Default game constructor
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ 1080, 720, 32 }, "SFML Game" },
	m_exitGame{false}, //when true game will exit
	m_player("test"),
	m_camera(&m_player)
{
	//Load Levels
	g_resourceManager.loadAssets();
	m_backgroundMusic.openFromFile("ASSETS/SOUNDS/dark_ambient.wav");
	m_backgroundMusic.setLoop(true);

	std::vector<std::string> levelPaths;
	levelPaths.push_back("ASSETS/LEVELS/Level1.tmx");
	levelPaths.push_back("ASSETS/LEVELS/Level2.tmx");

	for (int i = 0; i < levelPaths.size(); i++) {
		Level * level = new Level();
		level->load(levelPaths[i], m_lightEngine);
		level->setPlayer(&m_player);
		m_levels.push_back(level);
	}
	m_currLevel = 0;
	m_levels.at(m_currLevel)->startLevel();
	m_levels.at(m_currLevel)->setLightBlockingTile(m_lightEngine);
	//Input
	m_keyHandler = m_keyHandler->GetInstance();
	m_controllers.push_back(Xbox360Controller());

	for (auto & controller : m_controllers) {
		if (controller.isConnected()) {
			std::cout << "Controller Connected" << std::endl;
		}
	}

	
	//Lights
	lightMapTexture.create(m_levels.at(m_currLevel)->getBounds().x, m_levels.at(m_currLevel)->getBounds().y);
	lightMapTexture.setSmooth(true);
	lightmap.setTexture(lightMapTexture.getTexture());
	brightness = sf::Color(1, 1, 1, 100);

	m_lightEngine.init();
	m_player.init(m_lightEngine);

	//Menus
	initialiseMenus();
}


Game::~Game()
{
	m_keyHandler = nullptr;
	delete m_keyHandler;
}

/// <summary>
/// Start the game loop
/// </summary>
void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}

/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if ( sf::Event::Closed == event.type) // window message
		{
			m_menuHandler.stopAllMusic();
			m_backgroundMusic.stop();

			m_window.close();
		}
		if (sf::Event::KeyPressed == event.type) //user key press
		{
			if (sf::Keyboard::Escape == event.key.code)
			{
				m_exitGame = true;
			}
		}

		processGameEvents(event);
	}
}

/// <summary>
/// Process the current event by doing an event type comparison
/// </summary>
/// <param name="event">A reference to the current event being processed</param>
void Game::processGameEvents(sf::Event& event)
{
	if (event.key.code >= 0 && event.key.code < sf::Keyboard::Key::KeyCount)
	{
		if (event.type == event.KeyPressed)
		{
			if (!KeyboardHandler::GetInstance()->m_keysUp[event.key.code])
			{
				KeyboardHandler::GetInstance()->m_keysDown[event.key.code] = true;
			}
		}
		else if (event.type == event.KeyReleased)
		{
			KeyboardHandler::GetInstance()->m_keysDown[event.key.code] = false;
			KeyboardHandler::GetInstance()->m_keysUp[event.key.code] = false;
		}
	}

}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{

	m_menuStates = m_menuHandler.getMenuState();
	//Using a switch statement allows us to specify certain conditions for certain menus
	switch (m_menuStates)
	{
	case MenuStates::GAME:
		if (m_backgroundMusic.getStatus() != sf::Music::Playing) {
			m_backgroundMusic.play();
		}
		m_controllers.at(0).update();
		//TODO: PUT THESE INTO THE LEVEL
		if (m_levels.at(m_currLevel)->m_complete) {
			m_currLevel++;
			if (m_currLevel < m_levels.size()) {
				m_lightEngine.Lights.clear();
				m_lightEngine.Blocks.clear();
				m_lightEngine.Lights.push_back(m_player.getLight());
				m_levels.at(m_currLevel)->setLightBlockingTile(m_lightEngine);
				m_levels.at(m_currLevel)->startLevel();
			}
			else {
				m_currLevel = 0;
				m_lightEngine.Lights.clear();
				m_lightEngine.Blocks.clear();
				m_lightEngine.Lights.push_back(m_player.getLight());
				m_levels.at(m_currLevel)->setLightBlockingTile(m_lightEngine);
				m_menuHandler.goToMenu(MenuStates::GAMEOVER);
				
				for (auto & level : m_levels) {
					level->reset();
				}
				break;
			}
		}
		m_levels.at(m_currLevel)->update();
		m_window.setView(m_camera.m_view);
		m_player.update(m_window, m_controllers.at(0));
		m_camera.update();

		if (KeyboardHandler::GetInstance()->KeyPressed(sf::Keyboard::Return))
		{
			m_menuHandler.goToMenu(MenuStates::PAUSE);
		}
		if (KeyboardHandler::GetInstance()->KeyDown(sf::Keyboard::Add))
		{
			brightness += sf::Color(1, 1, 1, 100);
		}
		if (KeyboardHandler::GetInstance()->KeyDown(sf::Keyboard::Subtract))
		{
			brightness -= sf::Color(1, 1, 1, 100);
		}
		for (auto & controller : m_controllers) {
			controller.update();
		}
		break;
	default:
		m_menuHandler.update(m_controllers.at(0));
		break;
	}

	if (m_exitGame)
	{
		m_menuHandler.stopAllMusic();
		m_backgroundMusic.stop();
		m_window.close();
	}
}

/// <summary>
/// draw the frame and then switch bufers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::Black);
	//Using a switch statement allows us to specify certain conditions for certain menus
	switch (m_menuStates)
	{
	case MenuStates::GAME:
		m_window.setView(m_camera.m_view);
		//Lighting
		lightMapTexture.clear(brightness);
		//m_level.renderSeenTiles(lightMapTexture);
		m_player.render(lightMapTexture);
		m_lightEngine.Step(lightMapTexture);
		
		
		lightMapTexture.display();
		lightmap.setPosition(0,0);
		
		//Shadowed Enitites
		m_levels.at(m_currLevel)->render(m_window);
		m_window.draw(lightmap, sf::RenderStates(sf::BlendMultiply));
		
		//Minimap
		m_window.setView(m_camera.m_miniMap);
		//TODO: Outline around Minimap
		m_levels.at(m_currLevel)->renderMiniMap(m_window);

		m_player.renderMiniMap(m_window);

		m_window.setView(m_camera.m_menuView);
		//Draw Ui here

		break;
	case MenuStates::PAUSE:
		m_window.setView(m_camera.m_view);
		//Bright Visible entities
		lightMapTexture.clear(brightness);
		m_player.render(lightMapTexture);
		m_lightEngine.Step(lightMapTexture);
		lightMapTexture.display();
		lightmap.setPosition(0, 0);

		//Shadowed entities
		m_levels.at(m_currLevel)->render(m_window);
		
		//Draw visible entities over shadowed ones
		m_window.draw(lightmap, sf::RenderStates(sf::BlendMultiply));

		m_window.setView(m_camera.m_menuView);
		m_menuHandler.render(m_window);
		break;
	default:
		m_window.setView(m_camera.m_menuView);
		m_menuHandler.render(m_window);
		break;
	}
	m_window.display();
}

/// <summary>
/// Initialise the menu objects of the game
/// </summary>
/// <returns>Returns succes if menu objects can be successully created</returns>
bool Game::initialiseMenus()
{
	//NB : if using this check it would be best to have a different execution on not empty state
	//To avoid overwriting data
	//check if menu list is empty
	if (m_menuHandler.isEmpty())
	{
		std::vector<std::unique_ptr<Menu>> menus;

		//std::unique_ptr<MainMenu> mainMenu = std::make_unique<MainMenu>(m_exitGame, g_resourceManager.fontHolder["GameFont"]);
		//mainMenu->startGame = std::bind(&Game::startGame, this);
		//menus.push_back(std::move(mainMenu));
		menus.push_back(std::make_unique<MainMenu>(m_exitGame, g_resourceManager.fontHolder["GameFont"]));
		menus.push_back(std::make_unique<OptionsMenu>(g_resourceManager.fontHolder["GameFont"]));
		menus.push_back(std::make_unique<SoundOptions>(g_resourceManager.fontHolder["GameFont"]));
		menus.push_back(std::make_unique<DisplayOptions>(g_resourceManager.fontHolder["GameFont"]));
		menus.push_back(std::make_unique<Pause>(g_resourceManager.fontHolder["GameFont"]));
		menus.push_back(std::make_unique<GameOver>(g_resourceManager.fontHolder["GameFont"]));
		for (auto & menu : menus) {
			
			m_menuHandler.addMenu(menu);
		}
		if (m_menuHandler.setActive(MenuStates::MAIN_MENU))
		{
			std::cout << "Menu" << std::endl;
			debugMSG(cout << "Menu at " << static_cast<int>(MenuStates::GAME) << std::endl);
		}
		else {
			debugMSG(cout << "ERROR: Menu at " << static_cast<int>(MenuStates::MAIN_MENU) << " does not exist."
				<< "Error Line: 209" << std::endl);
		}
		m_menuHandler.goToMenu(MenuStates::MAIN_MENU);
		//NB: pass in current game state to avoid the 2 update buffer where a menu is still processing
		//changing the menu
		//TODO: Eric - Implement a possible fix for the frame buffer
		//m_menuHandler.goToGame(m_menuStates);
		return true;
	}
	return false;
}

void Game::startGame()
{
	m_lightEngine.Lights.clear();
	m_lightEngine.Blocks.clear();
	m_lightEngine.Lights.push_back(m_player.getLight());
	m_levels.at(m_currLevel)->setLightBlockingTile(m_lightEngine);
	m_levels.at(m_currLevel)->startLevel();
}
