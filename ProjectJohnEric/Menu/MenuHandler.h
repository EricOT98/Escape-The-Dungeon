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
	void stopAllMusic();
	MenuStates getMenuState();
	std::unique_ptr<Menu> getMenuFromState(MenuStates state);
	MenuStates m_previousMenu;
protected:
	std::vector<std::unique_ptr<Menu>> m_menus;
	MenuStates m_menuState;
	MenuStates m_nextState;
	
	bool m_menuChanged;
	int m_currentMenu;
};
#endif //!MENUHANDLER_H
