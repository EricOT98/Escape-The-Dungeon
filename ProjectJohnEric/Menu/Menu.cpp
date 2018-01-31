#include <iostream>
#include "Menu.h"

/// <summary>
/// Menu constructor
/// </summary>
/// <param name="window"></param>
Menu::Menu(MenuStates stateIn) :
	m_currentState(stateIn),
	m_nextState(stateIn)
{
	//std::cout << "Menu created" << std::endl; //Debug message
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

/// <summary>
/// Process all current input in the menu
/// </summary>
/// <param name="controller">The current connected controller</param>
void Menu::processInput(Xbox360Controller & controller)
{
	m_gui.processInput(controller);
}

/// <summary>
/// Set the states of the menu(Both current and next states)
/// </summary>
/// <param name="state">The menus current state</param>
/// <param name="nextState">The menus next state</param>
void Menu::setMenuState(MenuStates state, MenuStates  nextState)
{
	m_currentState = state;
	m_nextState = nextState;
}

/// <summary>
/// Return a reference to the current menu state
/// </summary>
/// <returns>Refurance to the current menu state</returns>
MenuStates & Menu::getMenuState()
{
	return m_currentState;
}

/// <summary>
/// Return a reference to the next state
/// </summary>
/// <returns>A refernece to the next menu state</returns>
MenuStates & Menu::getNextState()
{
	return m_nextState;
}

/// <summary>
/// Set the currenyt meenu to be active
/// </summary>
/// <param name="active">The menus active state</param>
void Menu::setActive(bool active)
{
	m_active = active;
}

/// <summary>
/// Return the menus alive state
/// </summary>
/// <returns>The menus alive state</returns>
bool Menu::getActive()
{
	return m_active;
}

/// <summary>
/// Reset the menus next game state to it's current game state
/// </summary>
void Menu::resetNextGameState()
{
	m_nextState = m_currentState;
}

MenuStates & Menu::getPreviousMenu()
{
	return m_previousMenu;
}

void Menu::setPreviousMenu(MenuStates state)
{
	m_previousMenu = state;
}

/// <summary>
/// Set the menus next state to be the corresponding menu
/// This allows the update to change the menu state
/// </summary>
/// <param name="state">The next state for the menu</param>
void Menu::goToMenu(MenuStates state)
{
	m_nextState = state; // Change the next game state
	//reset(); // Reset the current menu
}
