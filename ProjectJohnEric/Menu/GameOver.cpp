#include "GameOver.h"

/// <summary>
/// Default constructor
/// </summary>
GameOver::GameOver(sf::Font & font) :
	Menu(MenuStates::GAMEOVER, font)
{
	initialise();
}

/// <summary>
/// Default destructor
/// </summary>
GameOver::~GameOver()
{
}

/// <summary>
/// updates the game over menu
/// </summary>
/// <param name="controller">The current connected controller</param>
void GameOver::update(Xbox360Controller & controller)
{
	m_gui.processInput(controller);
	//Menu functionality for a button press
	if (m_mainmenuPressed)
	{
		goToMenu(MenuStates::MAIN_MENU);
		reset();
	}
	if (m_retryPressed)
	{
		goToMenu(MenuStates::GAME);
		reset();
	}
	m_gui.update();
}

/// <summary>
/// Draw the current menu
/// </summary>
/// <param name="window">The current render window</param>
void GameOver::render(sf::RenderWindow & window)
{
	window.draw(m_gui); //Draw gui components
}

/// <summary>
/// mainmenu button callback
/// </summary>
void GameOver::mainmenu()
{
	m_mainmenuPressed = true;
}

/// <summary>
/// Retry button callback
/// </summary>
void GameOver::retry()
{
	m_retryPressed = true;
}

/// <summary>
/// Initiilaise the Game Over menu
/// </summary>
void GameOver::initialise()
{
	initGUIObjects();
	m_mainmenu->select = std::bind(&GameOver::mainmenu, this);
	m_retry->select = std::bind(&GameOver::retry, this);
}

/// <summary>
/// Initilaise all GUI objects in the menu
/// </summary>
void GameOver::initGUIObjects()
{
	m_title = new Label( m_font, nullptr);
	m_mainmenu = new Button( m_font, nullptr);
	m_retry = new Button( m_font, nullptr);
	m_gui.addLabel(m_title, "Game Over", sf::Vector2f(100, 0), 80, sf::Color::Green);
	m_gui.addButton(m_mainmenu, "Return to Menu", sf::Vector2f(100, 600), sf::Vector2i(200, 50), sf::Color::Green);
	m_gui.addButton(m_retry, "Replay", sf::Vector2f(400, 600), sf::Vector2i(200, 50), sf::Color::Green);

	//selected, unselected, fill ,outline
	m_gui.setColorScheme(sf::Color::Blue, sf::Color::Black, sf::Color::Green, sf::Color::Black);
	m_title->setColour(sf::Color::White);
}

/// <summary>
/// Reset the menu to be used again
/// </summary>
void GameOver::reset()
{
	m_mainmenuPressed = false;
	m_retryPressed = false;
}
