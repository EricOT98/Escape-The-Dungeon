#include <iostream>
#include "Menu.h"

/// <summary>
/// Menu constructor
/// </summary>
/// <param name="window"></param>
Menu::Menu()
{
	std::cout << "Menu created" << std::endl; //Debug message
	initialise(); //Call initialise method
}

/// <summary>
/// Menu deconstructor
/// </summary>
Menu::~Menu()
{
	std::cout << "Menu destroyed" << std::endl; //Debug message
}

/// <summary>
/// Initialise variables here
/// </summary>
void Menu::initialise()
{
	initGUIObjects();
}

/// <summary>
/// Construct and initialise all objects the 
/// gui object will be handling
/// </summary>
void Menu::initGUIObjects()
{
	//selected, unselected, fill ,outline
	m_gui.setColorScheme(sf::Color::Blue, sf::Color::Black, sf::Color::Green, sf::Color::Black);
}

/// <summary>
/// Update menu here, detect button presses,
/// etc
/// </summary>
void Menu::update(Xbox360Controller & controller)
{
	//Check button presses
	processInput(controller);
	m_gui.update();
}

/// <summary>
/// Draw menu here
/// </summary>
void Menu::render(sf::RenderWindow & window)
{
	window.draw(m_gui); //Draw gui components
}

void Menu::processInput(Xbox360Controller & controller)
{
	m_gui.processInput(controller);
}

void Menu::setMenuState(MenuStates & state)
{
	m_currentState = state;
}

MenuStates & Menu::getMenuState()
{
	return m_currentState;
}

void Menu::setActive(bool active)
{
	m_active = active;
}

bool Menu::getActive()
{
	return m_active;
}
