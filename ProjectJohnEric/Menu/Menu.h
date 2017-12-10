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

enum class MenuStates {
	SPLASH,
	LICENSE,
	MAIN_MENU,
	GAME,
	OPTIONS,
	PAUSE,
	GAMEOVER,
	CREDITS
};

class Menu
{
public:
	Menu(MenuStates stateIn);
	~Menu();

	virtual void update(Xbox360Controller & controller);
	virtual void render(sf::RenderWindow & window);
	void processInput(Xbox360Controller & controller);
	void setMenuState(MenuStates & state, MenuStates & nextState);
	MenuStates & getMenuState();
	MenuStates & getNextState();
	void setActive(bool active);
	bool getActive();
	void resetNextGameState();

	void goToMenu(MenuStates state);
protected:
	virtual void initialise();
	virtual void initGUIObjects();

	GUI m_gui;
	MenuStates m_currentState;
	MenuStates m_nextState;
	bool m_active;
};

#endif // !MENU_H
