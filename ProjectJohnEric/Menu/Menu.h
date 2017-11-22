/// <summary>
/// Author: James Pierce, Eric O' Toole:
/// Description: The main menu of the game
/// 
/// Time Taken: 2hours
/// Known Errors: Stack overflow on destruction
/// </summary>

#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <SFML\Graphics.hpp>
#include "../GUI/GUI.h"

class Menu
{
public:
	Menu();
	~Menu();

	virtual void update(Xbox360Controller & controller);
	virtual void render(sf::RenderWindow & window);
	void processInput(Xbox360Controller & controller);
protected:
	virtual void initialise();
	virtual void initGUIObjects();

	GUI m_gui;
};

#endif // !MENU_H
