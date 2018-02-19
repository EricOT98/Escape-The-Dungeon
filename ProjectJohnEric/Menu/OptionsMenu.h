/// <summary>
/// @author: Eric O' Toole
/// @desc: Options menu class deesigned to allow players to toggle varying options
/// </summary>

#ifndef OPTIONSMENU_H
#define OPTIONSMENU_H

#include "Menu.h"

class OptionsMenu : public Menu
{
public:
	OptionsMenu(sf::Font & font, MenuStates & prev);
	~OptionsMenu();

	void update(Xbox360Controller & controller) override;
	void render(sf::RenderWindow & window) override;

	void sound();
	void display();
	void back();

	bool m_soundPressed;
	bool m_displayPressed;
	bool m_backPressed;

protected:
	void initialise() override;
	void initGUIObjects() override;

	void reset();

	Label * m_title;
	Button * m_sound;
	Button * m_display;
	Button * m_back;
	MenuStates & m_previousMenu;
};

#endif //!OPTIONS_MENU
