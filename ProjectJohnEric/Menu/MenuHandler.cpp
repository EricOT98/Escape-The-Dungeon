#include "MenuHandler.h"

MenuHandler::MenuHandler()
{
}

/// <summary>
/// Add a menu object onto the vector of menus
/// </summary>
/// <param name="m">The menu object to be added</param>
void MenuHandler::addMenu(std::unique_ptr<Menu> &m)
{
	m_menus.push_back(std::move(m));
}

/// <summary>
/// Update the current menu
/// </summary>
/// <param name="controller">The current connected controller</param>
void MenuHandler::update(Xbox360Controller & controller)
{
	for (m_currentMenu = 0; m_currentMenu < m_menus.size(); ++m_currentMenu)
	{
		if (m_menus.at(m_currentMenu)->getMenuState() == m_menuState)
		{
			m_menus.at(m_currentMenu)->update(controller); //update current menu
			if (m_nextState == m_menuState)
			{
				m_nextState = m_menus.at(m_currentMenu)->getNextState();
			}
			else
			{
				m_menuState = m_nextState;
				m_menus.at(m_currentMenu)->resetNextGameState();
			}
			break;
		}
	}
}

/// <summary>
/// Render the current menu
/// </summary>
/// <param name="window">The current render window</param>
void MenuHandler::render(sf::RenderWindow & window)
{
	//Only render the currently used menu
	if (m_currentMenu < m_menus.size())
	{
		m_menus.at(m_currentMenu)->render(window);
	}
}

bool MenuHandler::setActive(MenuStates state)
{
	for (int i = 0; i < m_menus.size(); ++i)
	{
		if (m_menus.at(i) != nullptr)
		{
			if (state == m_menus.at(i)->getMenuState())
			{
				m_menus.at(i)->setActive(true);
				return true;
			}
		}
	}
	return false;
}

bool MenuHandler::goToMenu(MenuStates state)
{
	for (int i = 0; i < m_menus.size(); i++)
	{
		if (state == m_menus.at(i)->getMenuState())
		{
			m_menuState = state;
			m_nextState = m_menus.at(i)->getNextState();
			m_menus.at(i)->setActive(true);
		}
	}
	return false;
}

/// <summary>
/// Return if the menu vector is empty
/// </summary>
/// <returns>THe empty state of menu vector
bool MenuHandler::isEmpty()
{
	return m_menus.empty();
}

/// <summary>
/// Returns the menu handlers state
/// </summary>
/// <returns>The menu state of the menu handler</returns>
MenuStates MenuHandler::getMenuState()
{
	return m_menuState;
}
