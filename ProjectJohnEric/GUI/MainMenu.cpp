#include "MainMenu.h"

MainMenu::MainMenu()
{
	initialise();
}

MainMenu::~MainMenu()
{
}

void MainMenu::update(Xbox360Controller & controller)
{
	m_gui.processInput(controller);
	
	if (m_play->getPressed())
	{
		std::cout << "Play pressed " << std::endl;
		m_playPressed = true;
		m_play->resetPressed();
	}
	else
	{
		m_playPressed = false;
	}
	m_gui.update();
}

void MainMenu::render(sf::RenderWindow & window)
{
	window.draw(m_gui); //Draw gui components
}

void MainMenu::initialise()
{
	initGUIObjects();
}

void MainMenu::initGUIObjects()
{
	m_title = new Label(nullptr);
	m_play = new Button(nullptr);
	m_options = new Button(nullptr);
	m_quit = new Button(nullptr);
	m_gui.addLabel(m_title, "Escape the Dungeon", sf::Vector2f(100, 100), 80, sf::Color::Green);
	m_gui.addButton(m_play, "Play", sf::Vector2f(100, 400), sf::Vector2i(200, 50), sf::Color::Green);
	m_gui.addButton(m_options, "Options", sf::Vector2f(100, 500), sf::Vector2i(200, 50), sf::Color::Green);
	m_gui.addButton(m_quit, "Quit", sf::Vector2f(100, 600), sf::Vector2i(200, 50), sf::Color::Green);
	//selected, unselected, fill ,outline
	m_gui.setColorScheme(sf::Color::Blue, sf::Color::Black, sf::Color::Green, sf::Color::Black);
}
