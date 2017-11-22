#ifndef MENUHANDLER_H
#define MENUHANDLER_H

#include <iostream>
#include "Menu.h"
#include <memory>
#include <SFML\Graphics.hpp>

class MenuHandler {
public:
	MenuHandler();
	bool addMenu(std::unique_ptr<Menu> m);
	void update();
	void render(sf::RenderWindow & window);
protected:
	std::vector<std::unique_ptr<Menu>> m_menus;
};
#endif //!MENUHANDLER_H