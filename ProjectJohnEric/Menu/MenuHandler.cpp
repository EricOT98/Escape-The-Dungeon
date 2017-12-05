#include "MenuHandler.h"

MenuHandler::MenuHandler()
{
}

void MenuHandler::addMenu(MenuStates & state,std::unique_ptr<Menu> &m)
{
	m->setMenuState(state);
	m_menus.push_back(std::move(m));
}

void MenuHandler::update(Xbox360Controller & controller)
{
	m_menus.at(static_cast<int>(m_menuStates))->update(controller);
}

void MenuHandler::render(sf::RenderWindow & window)
{
	m_menus.at(static_cast<int>(m_menuStates))->render(window);
}

void MenuHandler::goToNext()
{
	if (m_menus.at(static_cast<int>(m_menuStates))->getActive()) {
	}
}

bool MenuHandler::goToMenu(MenuStates & state)
{
	if (nullptr != m_menus.at(static_cast<int>(state)) )
	{
		m_menus.at(static_cast<int>(state))->setActive(true);
		m_menus.at(static_cast<int>(m_menuStates))->setActive(false);
		return true;
	}
	return false;
}

MenuStates MenuHandler::getMenuState()
{
	return m_menuStates;
}
