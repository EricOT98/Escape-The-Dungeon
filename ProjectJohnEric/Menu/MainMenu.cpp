#include "MainMenu.h"

/// <summary>
/// Default constructor for main menu which creates a menu
/// with base state MAinMenu
/// </summary>
MainMenu::MainMenu() :
	Menu(MenuStates::MAIN_MENU)
{
	initialise();
}

/// <summary>
/// Defalt destructor for the main menu
/// </summary>
MainMenu::~MainMenu()
{
}

/// <summary>
/// Uopdate the main menu elemeents
/// </summary>
/// <param name="controller"></param>
void MainMenu::update(Xbox360Controller & controller)
{
	m_gui.processInput(controller);
	//Menu functionality for a button press
	if (m_playPressed)
	{
		goToMenu(MenuStates::GAME);
	}
	if (m_optionsPressed)
	{
		goToMenu(MenuStates::OPTIONS);
	}
	m_gui.update();
}

/// <summary>
/// Render all elelments in the main menu
/// </summary>
/// <param name="window">The current render window</param>
void MainMenu::render(sf::RenderWindow & window)
{
	window.draw(m_gui); //Draw gui components
}

/// <summary>
/// Funbction callback for play button pressed
/// </summary>
void MainMenu::play()
{
	m_playPressed = true;
}

/// <summary>
/// Funbction callback for options button pressed
/// </summary>/
void MainMenu::options()
{
	m_optionsPressed = true;
}

/// <summary>
/// Funbction callback for quit button pressed
/// </summary>
void MainMenu::quit()
{
	m_quitPressed = true;
}

/// <summary>
/// Default initilaiser for the main menu
/// </summary>
void MainMenu::initialise()
{
	initGUIObjects();
	m_play->select =  std::bind(&MainMenu::play, this);
	m_options->select = std::bind(&MainMenu::options, this);
	m_quit->select = std::bind(&MainMenu::quit, this);
}

/// <summary>
/// Initiialise all gui objects inside the main menu
/// </summary>
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

void MainMenu::goToMenu(MenuStates state)
{
	m_nextState = state;
	reset();
}

void MainMenu::reset()
{
	m_playPressed = false;
	m_optionsPressed = false;
	m_quitPressed = false;
}
