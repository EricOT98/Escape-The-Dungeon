#include "Pause.h"

Pause::Pause() :
	Menu(MenuStates::PAUSE)
{
	initialise();
}

Pause::~Pause()
{
}

void Pause::update(Xbox360Controller & controller)
{
	m_gui.processInput(controller);
	//Menu functonality for a button press
	if (m_continuePressed)
	{
		goToMenu(MenuStates::GAME);
		reset();
	}
	if (m_optionsPressed)
	{
		goToMenu(MenuStates::OPTIONS);
		reset();
	}

	if (m_quitPressed)
	{
		goToMenu(MenuStates::MAIN_MENU);
		reset();
	}
	m_gui.update();
}

void Pause::render(sf::RenderWindow & window)
{
	window.draw(m_gui);
}

void Pause::continueCallback()
{
	m_continuePressed = true;
}

void Pause::optionsCallback()
{
	m_optionsPressed = true;
}

void Pause::quitToMenuCallback()
{
	m_quitPressed = true;
}

void Pause::initialise()
{
	initGUIObjects();
	m_continue->select = std::bind(&Pause::continueCallback, this);
	m_options->select = std::bind(&Pause::optionsCallback, this);
	m_back->select = std::bind(&Pause::quitToMenuCallback, this);
}

void Pause::initGUIObjects()
{
	m_title = new Label(nullptr);
	m_continue = new Button(nullptr);
	m_options = new Button(nullptr);
	m_back = new Button(nullptr);
	m_gui.addLabel(m_title, "Paused", sf::Vector2f(100, 100), 80, sf::Color::Green);
	m_gui.addButton(m_continue, "Continue", sf::Vector2f(100, 400), sf::Vector2i(200, 50), sf::Color::Green);
	m_gui.addButton(m_options, "Options", sf::Vector2f(100, 500), sf::Vector2i(200, 50), sf::Color::Green);
	m_gui.addButton(m_back, "Back to Main Menu", sf::Vector2f(100, 600), sf::Vector2i(200, 50), sf::Color::Green);
	//selected, unselected, fill ,outline
	m_gui.setColorScheme(sf::Color::Blue, sf::Color::White, sf::Color::Green, sf::Color::Black);
}

void Pause::reset()
{
	m_continuePressed = false;
	m_optionsPressed = false;
	m_quitPressed = false;
}
