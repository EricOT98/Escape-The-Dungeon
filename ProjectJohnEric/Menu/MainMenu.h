/// <summary>
/// @author: Eric O' Toole
/// @desc: A main menu class designed to allow the player 
/// to access other menus as well as gameplay
/// Time Taken: 2 hours
/// Known Errors: Buttons must have a callback function
/// Tasks: //TODO: Eric assign all buttons a function callback
/// </summary>

//TODO: Eric: assign all buttons a callback function
#ifndef MAINMENU_H
#define MAINMENU_H

#include "Menu.h"

class MainMenu : public Menu
{
public:
	MainMenu();
	~MainMenu();

	void update(Xbox360Controller & controller) override;
	void render(sf::RenderWindow & window) override;
	void play();
	void options();
	void quit();
	bool m_playPressed;
	bool m_optionsPressed;
	bool m_quitPressed;

protected:
	void initialise() override;
	void initGUIObjects() override;
	void goToMenu(MenuStates state) override;
	void reset();
	Label * m_title;
	Button * m_play;
	Button * m_options;
	Button * m_quit;
};
#endif //!menu