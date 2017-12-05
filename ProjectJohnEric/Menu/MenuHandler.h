#ifndef MENUHANDLER_H
#define MENUHANDLER_H

#include <iostream>
#include "Menu.h"
#include <memory>
#include <SFML\Graphics.hpp>

class MenuHandler {
public:
	MenuHandler();
	void addMenu(MenuStates & state,std::unique_ptr<Menu> &m);
	void update(Xbox360Controller & controller);
	void render(sf::RenderWindow & window);
	void goToNext();
	bool goToMenu(MenuStates & state);
	MenuStates getMenuState();
protected:
	std::vector<std::unique_ptr<Menu>> m_menus;
	MenuStates m_menuStates;
};
#endif //!MENUHANDLER_H