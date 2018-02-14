#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "Menu.h"

class GameOver : public Menu
{
public:
	GameOver(sf::Font & font);
	~GameOver();

	void update(Xbox360Controller & controller) override;
	void render(sf::RenderWindow & window) override;

	void mainmenu();
	void retry();
protected:
	void initialise() override;
	void initGUIObjects() override;

	void reset();

	bool m_backPressed;
	bool m_volumePressed;

	Label * m_title;
	Button * m_mainmenu;
	Button * m_retry;

	bool m_mainmenuPressed;
	bool m_retryPressed;
};
#endif //!GAMEOVER
