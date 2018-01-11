#ifndef MENUHANDLER_H
#define MENUHANDLER_H

#include <iostream>
#include "../Menu/Menu.h"
#include <memory>
#include <SFML\Graphics.hpp>

class MenuHandler {
public:
	MenuHandler();
	void addMenu(std::unique_ptr<Menu> &m);
	void update(Xbox360Controller & controller);
	void render(sf::RenderWindow & window);
	bool setActive(MenuStates state);
	bool goToMenu(MenuStates state);

	bool isEmpty();
	void goToGame(MenuStates & game_state);
	MenuStates getMenuState();
	std::unique_ptr<Menu> getMenuFromState(MenuStates state);
protected:
	std::vector<std::unique_ptr<Menu>> m_menus;
	MenuStates m_menuState;
	MenuStates m_nextState;
	int m_currentMenu;
};
#endif //!MENUHANDLER_H
