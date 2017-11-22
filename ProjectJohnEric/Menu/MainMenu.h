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
	bool m_playPressed;
	bool m_optionsPressed;
	bool m_quitPressed;

protected:
	void initialise() override;
	void initGUIObjects() override;
	Label * m_title;
	Button * m_play;
	Button * m_options;
	Button * m_quit;

	

};
#endif //!menu