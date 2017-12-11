#include "OptionsMenu.h"

OptionsMenu::OptionsMenu() :
	Menu(MenuStates::OPTIONS)
{
	initialise();
}

OptionsMenu::~OptionsMenu()
{
}

void OptionsMenu::update(Xbox360Controller & controller)
{
	m_gui.processInput(controller);
	//Menu functionality for a button press
	if (m_backPressed)
	{
		goToMenu(MenuStates::MAIN_MENU);
		reset();
	}
	m_gui.update();
}

void OptionsMenu::render(sf::RenderWindow & window)
{
	window.draw(m_gui); //Draw gui components
}

void OptionsMenu::sound()
{
	m_soundPressed = true;
}

void OptionsMenu::back()
{
	m_backPressed = true;
}

void OptionsMenu::initialise()
{
	initGUIObjects();
	m_sound->select = std::bind(&OptionsMenu::sound, this);
	m_back->select = std::bind(&OptionsMenu::back, this);
}

void OptionsMenu::initGUIObjects()
{
	m_title = new Label(nullptr);
	m_sound = new Button(nullptr);
	m_back = new Button(nullptr);
	m_gui.addLabel(m_title, "Options", sf::Vector2f(100, 100), 80, sf::Color::Green);
	m_gui.addButton(m_sound, "Sound Options", sf::Vector2f(100, 500), sf::Vector2i(200, 50), sf::Color::Green);
	m_gui.addButton(m_back, "<- Back", sf::Vector2f(100, 600), sf::Vector2i(200, 50), sf::Color::Green);

	//selected, unselected, fill ,outline
	m_gui.setColorScheme(sf::Color::Blue, sf::Color::Black, sf::Color::Green, sf::Color::Black);
}

void OptionsMenu::reset()
{
	m_backPressed = false;
	m_soundPressed = false;
}
