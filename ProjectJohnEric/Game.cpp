#include "Game.h"
#include <iostream>
#include "Level.h"

Game::Game() :
	m_window{ sf::VideoMode{ 1080, 720, 32 }, "SFML Game" },
	m_exitGame{false}, //when true game will exit
	m_character("test")
{
	m_character.init();
	/*m_keyHandler = m_keyHandler->GetInstance();
	if (!m_map.load("ASSETS/LEVELS/Level1.tmx")) {
		std::cout << "ERROR: Loading map failed" << std::endl;
	}
	int size = m_map.getLayers().size();
	for (int i = 0; i < size; i++) {
		m_layers.push_back(new MapLayer(m_map, i));
	}*/
	std::string filename = "ASSETS/LEVELS/Level1.tmx";
	m_level.load(filename);
}


Game::~Game()
{
	m_keyHandler = nullptr;
	delete m_keyHandler;
}


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
				std::cout << m_character.getName() << std::endl;
			}
		}
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
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
	//m_window.clear(sf::Color::White);
	m_level.render(m_window);
	//m_character.render(m_window);
	/*for (MapLayer * m : m_layers) {
		m_window.draw(*m);
	}*/
	
	m_window.display();
}