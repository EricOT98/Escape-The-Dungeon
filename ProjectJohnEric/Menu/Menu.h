/// <summary>
/// Author: Eric O' Toole:
/// A menu base class that contains both a gui and a state
/// in order to allow game and menu based state changes to take place
/// through gui objects
///
/// Time Taken: 6 hours
/// Known Errors: Possible memory leaks
/// TODO: Eric: check for memory allocatin erros
/// </summary>

#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <SFML\Graphics.hpp>
#include "../GUI/GUI.h"

//Enum assigned here to allow modifciation of game states
enum class MenuStates {
	SPLASH,
	LICENSE,
	MAIN_MENU,
	GAME,
	OPTIONS,
	PAUSE,
	GAMEOVER,
	CREDITS,
	SOUNDOPTIONS
};

class Menu
{
public:
	Menu(MenuStates stateIn);
	~Menu();

	virtual void update(Xbox360Controller & controller);
	virtual void render(sf::RenderWindow & window);
	void processInput(Xbox360Controller & controller);
	void setMenuState(MenuStates state, MenuStates nextState);
	MenuStates & getMenuState();
	MenuStates & getNextState();
	void setActive(bool active);
	bool getActive();
	void resetNextGameState();

	virtual void goToMenu(MenuStates state);
protected:
	virtual void initialise();
	virtual void initGUIObjects();
	virtual void reset() = 0; //Pure virtaul must be overridden

	GUI m_gui;
	MenuStates m_currentState;
	MenuStates m_nextState;
	bool m_active;
};

#endif // !MENU_H
