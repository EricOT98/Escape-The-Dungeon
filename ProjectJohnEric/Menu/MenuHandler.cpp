#include "MenuHandler.h"

MenuHandler::MenuHandler()
{
}

void MenuHandler::addMenu(std::unique_ptr<Menu> &m)
{
	m_menus.push_back(std::move(m));
}

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

void MenuHandler::render(sf::RenderWindow & window)
{
	/*for (int i = 0; i < m_menus.size(); ++i)
	{
		if (m_menuState == m_menus.at(i)->getMenuState() && 
			m_menus.at(i)->getActive())
		{
			m_menus.at(i)->render(window);
		}
	}*/
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
	/*if (nullptr != m_menus.at(static_cast<int>(state)) )
	{
		m_menus.at(static_cast<int>(state))->setActive(true);
		m_menus.at(static_cast<int>(m_menuState))->setActive(false);
		return true;
	}
	return false;*/

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

MenuStates MenuHandler::getMenuState()
{
	return m_menuState;
}
