#include "Game.h"
#include <iostream>
#include "Level.h"

/// <summary>
/// Degfault game constructor
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ 1080, 720, 32 }, "SFML Game" },
	m_exitGame{false}, //when true game will exit
	m_player("test"),
	m_camera()
{
	std::string filename = "ASSETS/LEVELS/Level1.tmx";
	m_level.load(filename, &m_player);
	m_player.init();
	m_keyHandler = m_keyHandler->GetInstance();

	if (m_testTexture.loadFromFile("ASSETS/IMAGES/testMap.png")) {
		m_testSprite.setTexture(m_testTexture);
	}
	else {
		std::cout << "ERROR: LOADING FILENAME: " << __FILE__ << std::endl;
	}

	m_controllers.push_back(Xbox360Controller());
	for (auto & controller : m_controllers) {
		if (controller.isConnected()) {
			std::cout << "Controller Connected" << std::endl;
		}
	}
<<<<<<< HEAD
	initialiseMenus();
=======
	m_menuStates = MenuStates::MAIN_MENU;
	m_menus.push_back(std::make_unique<MainMenu>());
	for (auto  & menu : m_menus) {
		m_menuHandler.addMenu(menu);
	}
<<<<<<< HEAD
>>>>>>> Button callbacks implemented not changing menu states yet
=======
	m_menuHandler.setActive(MenuStates::MAIN_MENU);
	m_menuHandler.goToMenu(MenuStates::MAIN_MENU);
>>>>>>> Menu FUnctionality implemented using callbacks
	m_camera.init();
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
			m_window.close();
		}
		if (sf::Event::KeyPressed == event.type) //user key press
		{
			if (sf::Keyboard::Escape == event.key.code)
			{
				m_exitGame = true;
			}
			if (sf::Keyboard::Return == event.key.code)
			{
				std::cout << m_player.getName() << std::endl;
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		m_window.close();
	}

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
<<<<<<< HEAD
	//Using a switch statement allows us to specify certain conditions for certain menus
=======
>>>>>>> Menu FUnctionality implemented using callbacks
	switch (m_menuStates)
	{
	case MenuStates::GAME:
		m_controllers.at(0).update();
		//TODO: PUT THESE INTO THE LEVEL
		m_level.update();
		m_player.update(m_window, m_controllers.at(0));
		m_camera.update(m_player.getPosition());
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
		m_level.render(m_window);
		m_camera.render(m_window);         // TODO: JUST FOR TESTING!!
		//m_window.draw(m_testSprite);
		m_player.render(m_window);
		break;
	default:
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
		menus.push_back(std::make_unique<MainMenu>());
		for (auto & menu : menus) {
			m_menuHandler.addMenu(menu);
		}
		m_menuHandler.setActive(MenuStates::MAIN_MENU);
		m_menuHandler.goToMenu(MenuStates::MAIN_MENU);
		return true;
	}
	return false;
}
